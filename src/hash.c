/* TODO copyright */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avra2.h"

#define mapsize(m) (1<<(m)->nbits)
#define mapmask(m) (mapsize(m)-1)
#define mapidx(m, k) (strhash((unsigned char*) (k)) & mapmask(m))
#define keyeq(a, b) ((a)[0] == (b)[0] && !strcmp((a), (b)))
#define emptymapv ((struct mapv){ .type=MAPV_EMPTY_TYPE })

/* Return a hash for str. This is the djb2 hash function. */
static unsigned long
strhash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/* Put (k,v) into b, or one of b's overflow buckets, or allocate a new
 * overflow bucket, if needed. */
static bool
mapb_put(struct mapb *b, char *k, struct mapv v, bool growing)
{
	size_t i;
	struct mapb *emptyb = 0;
	size_t emptyi;

	while (1) {
		for (i = 0; i < MAP_BUCKET_SIZE; i++) {
			if (b->k[i] == 0) { /* Slot empty? */
				/* Record the first empty slot we find. */
				if (emptyb == 0) {
					emptyb = b;
					emptyi = i;
					/* If we're growing, there's no chance the key is
					 * somewhere else in the table, so skip to end. */
					if (growing)
						goto done;
				}
			} else if (keyeq(k, b->k[i])) { /* k already in table? */
				b->v[i] = v;
				return false;
			}
		}
		if (b->ovf != 0) {
			b = b->ovf;
		} else {
			if (emptyb == 0) {
				emptyb = b->ovf = ecalloc(1, sizeof *b->ovf);
				emptyi = 0;
			}
			break;
		}
	}

	/* If we're not growing, k is supplied by the user, so we must copy it. */
	if (!growing)
		k = strcpy(emalloc(strlen(k)+1), k);
done:
	emptyb->k[emptyi] = k;
	emptyb->v[emptyi] = v;
	return true;
}

/* Get the value corresponding to k in b, or emptymapv if k is not in b. */
static struct mapv
mapb_get(struct mapb *b, char *k)
{
	size_t i;

	for (; b; b = b->ovf) {
		for (i = 0; i < MAP_BUCKET_SIZE; i++) {
			if (b->k[i] != 0 && keyeq(k, b->k[i]))
				return b->v[i];
		}
	}
	return emptymapv;
}

/* Delete k from b. Return true if and only if k was in b. */
static bool
mapb_del(struct mapb *b, char *k)
{
	size_t i;

	for (; b; b = b->ovf) {
		for (i = 0; i < MAP_BUCKET_SIZE; i++) {
			if (b->k[i] != 0 && keyeq(k, b->k[i])) {
				free(b->k[i]);
				b->k[i] = 0;
				return true;
			}
		}
	}
	return false;
}

/* Free b's contained keys and overflow buckets. */
static void
mapb_free(struct mapb *b)
{
	size_t i;
	struct mapb *bovf;
	bool b_is_ovf = false;

	while (b) {
		for (i = 0; i < MAP_BUCKET_SIZE; i++) {
			if (b->k[i] != 0)
				free(b->k[i]);
		}
		bovf = b->ovf;
		if (b_is_ovf)
			free(b);
		b = bovf;
		b_is_ovf = true;
	}
}

/* Double the size of m. */
static void
map_grow(struct map *m)
{
	uint32_t newnbits;
	struct mapb *newbs;
	size_t mi;
	size_t bi;
	struct mapb *b;
	struct mapb *bovf;
	bool b_is_ovf;
	size_t idx;

	newnbits = m->nbits+1;
	newbs = ecalloc(1<<newnbits, sizeof *newbs);

	for (mi = 0; mi < mapsize(m); mi++) {
		b = &m->bs[mi];
		b_is_ovf = false;
		while (b) {
			for (bi = 0; bi < MAP_BUCKET_SIZE; bi++) {
				if (b->k[bi] == 0)
					continue;
				idx = strhash((unsigned char*) b->k[bi]) & ((1<<newnbits)-1);
				mapb_put(&newbs[idx], b->k[bi], b->v[bi], true);
			}
			bovf = b->ovf;
			if (b_is_ovf) {
				/* Currently we just allocate overflow buckets as we need
				 * them, and free them everytime we grow. We would most
				 * likely benefit from caching empty overflow buckets. */
				free(b);
			}
			b = bovf;
			b_is_ovf = true;
		}
	}

	free(m->bs);
	m->nbits = newnbits;
	m->bs = newbs;
}

/* Allocate a new map with space for at least cnt_hint elements before the
 * map has to grow. The allocated map should be freed with map_free. */
struct map *
map_new(size_t cnt_hint)
{
	struct map *m;

	m = emalloc(sizeof *m);
	m->iters = 0;
	m->cnt = 0;
	m->nbits = 0;
	while (cnt_hint > MAP_LOAD_FACTOR*mapsize(m))
		m->nbits++;
	m->bs = ecalloc(mapsize(m), sizeof *m->bs);

	return m;
}

/* Free all resources associated with m. */
void
map_free(struct map *m)
{
	size_t i;

	for (i = 0; i < mapsize(m); i++)
		mapb_free(&m->bs[i]);
	free(m->bs);
	free(m);
}

/* Put (k,v) into m. */
void
map_put(struct map *m, char *k, struct mapv v)
{
	assert(m->iters == 0);
	if (m->cnt >= MAP_LOAD_FACTOR*mapsize(m))
		map_grow(m);
	if (mapb_put(&m->bs[mapidx(m, k)], k, v, false))
		m->cnt++;
}

/* Get the value corresponding to k in m, or emptymapv if k is not in m. */
struct mapv
map_get(struct map *m, char *k)
{ return mapb_get(&m->bs[mapidx(m, k)], k); }

/* Delete k from m. Return true if and only if k was in m. */
bool
map_del(struct map *m, char *k)
{
	bool deleted;

	deleted = mapb_del(&m->bs[mapidx(m, k)], k);
	if (deleted)
		m->cnt--;
	return deleted;
}

/* Initialize iter to iterate over (k,v) pairs in m. See mapi_next. New
 * elements must not be inserted into m until mapi_free(iter) has been
 * called. */
void
mapi_init(struct mapi *iter, struct map *m)
{
	iter->m = m;
	iter->b = &m->bs[0];
	iter->bi = 0;
	iter->mi = 0;
	iter->k = 0;
	iter->v = emptymapv;
	m->iters++;
}

/* Returns true if and only if there is another (k,v) to iterate over,
 * and sets iter->k and iter->v appropriately in that case. */
bool
mapi_next(struct mapi *iter)
{
	for (; iter->mi < mapsize(iter->m); iter->mi++) {
		for (; iter->b; iter->b = iter->b->ovf) {
			for (; iter->bi < MAP_BUCKET_SIZE; iter->bi++) {
				if (iter->b->k[iter->bi] != 0) {
					iter->k = iter->b->k[iter->bi];
					iter->v = iter->b->v[iter->bi];
					iter->bi++;
					return true;
				}
			}
			iter->bi = 0;
		}
		iter->b = &iter->m->bs[iter->mi+1];
	}
	return false;
}

/* Free the resources associated with iter. */
void
mapi_free(struct mapi *iter)
{
	iter->m->iters--;
	iter->m = 0; /* Make sure mapi_next now fails. */
}
