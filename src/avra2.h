/* Requires: size_t, stdbool.h, stdint.h */

#ifndef VERSION
#define VERSION "(version undefined)"
#endif

#ifdef DEFAULT_INCLUDE_PATH
#define INCLUDE_PATH DEFAULT_INCLUDE_PATH
#else
#define INCLUDE_PATH "."
#endif

/* These parameters are not fine tuned. */
#define MAP_BUCKET_SIZE 8
#define MAP_LOAD_FACTOR 6

#define MAPV_EMPTY_TYPE 0
#define MAPV_INT_TYPE 1
#define MAPV_STR_TYPE 2
#define mapv_is_empty(v) ((v).type == MAPV_EMPTY_TYPE)
#define mapv_is_int(v)   ((v).type == MAPV_INT_TYPE)
#define mapv_is_str(v)   ((v).type == MAPV_STR_TYPE)
#define mapv2int(v) ((v).u.i)
#define mapv2str(v) ((v).u.s)
#define int2mapv(v) ((struct mapv){ .type=MAPV_INT_TYPE, .u.i=v })
#define str2mapv(v) ((struct mapv){ .type=MAPV_STR_TYPE, .u.s=v })

struct mapv {
	int type;
	union {
		int64_t i;
		char *s;
	} u;
};

struct mapb {
	char *k[MAP_BUCKET_SIZE];
	struct mapv v[MAP_BUCKET_SIZE];
	struct mapb *ovf;
};

struct mapi {
	struct map *m;
	struct mapb *b;
	size_t bi;
	size_t mi;
	char *k;
	struct mapv v;
};

struct map {
	uint32_t iters;
	uint32_t nbits;
	size_t cnt;
	struct mapb *bs; /* bs is an array of 1<<nbits buckets. */
};

struct map *map_new(size_t cnt_hint);
void map_free(struct map *m);
void map_put(struct map *m, char *k, struct mapv v);
struct mapv map_get(struct map *m, char *k);
bool map_del(struct map *m, char *k);

void mapi_init(struct mapi *iter, struct map *m);
bool mapi_next(struct mapi *iter);
void mapi_free(struct mapi *iter);

void *emalloc(size_t size);
void *ecalloc(size_t nmemb, size_t size);
