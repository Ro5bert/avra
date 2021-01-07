/* Requires: size_t, stdbool.h, stdint.h, stdio.h */

/* Normally set by the Makefile. */
#ifndef VERSION
#define VERSION "(version undefined)"
#endif

/* Normally set by the Makefile to something like /usr/local/include/avr. */
#ifndef DEFAULT_INCLUDE_PATH
#define DEFAULT_INCLUDE_PATH "."
#endif

#define AVRA_REPO_URL "https://github.com/Ro5bert/avra"

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

/* Don't use assert.h so we can do custom error handling. */
#ifdef NDEBUG
#define assert(cond) ((void)0)
#else
#define assert(cond) ((void)((cond) ||\
			(assert_fail(#cond, __FILE__, __func__, __LINE__),0)))
#endif

enum {
	TOK_EOF,
	TOK_EOL,
	TOK_IDENT,
	TOK_DIR,
	TOK_NUM,
	TOK_STR,
	TOK_CHAR,
	TOK_COLON,
	TOK_COMMA,
	TOK_QMARK,
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_LBRACK,
	TOK_RBRACK,
	TOK_UNARY,
	TOK_BINARY,
	TOK_PM,
};

#define TOK_MIN_CAP 64

struct tok {
	char *t;
	size_t cap;
	int type;
};

#define LEXER_MIN_CAP 4096

struct lexer {
	FILE *f;
	char *buf;
	size_t boff; /* Offset into buf of beginning of current token */
	size_t eoff; /* Offset into buf of end of current token */
	size_t len;  /* Number of bytes in buf */
	size_t cap;  /* Capacity of buf*/
};

size_t lrem(struct lexer *l);
void lread(struct lexer *l, size_t n);
int lnext(struct lexer *l);
int lpeek(struct lexer *l, size_t i);
void lbackup(struct lexer *l);
void laccept(struct lexer *l, int (*isvalid)(int));
int laccept1(struct lexer *l, char *set);
void lignore(struct lexer *l);
struct tok *ltok(struct lexer *l, struct tok *tok, int type);

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

/* hash.c */
struct map *map_new(size_t cnt_hint);
void map_free(struct map *m);
void map_put(struct map *m, char *k, struct mapv v);
struct mapv map_get(struct map *m, char *k);
bool map_del(struct map *m, char *k);
void mapi_init(struct mapi *iter, struct map *m);
bool mapi_next(struct mapi *iter);
void mapi_free(struct mapi *iter);

/* util.c */
void *emalloc(size_t size);
void *ecalloc(size_t nmemb, size_t size);
void *erealloc(void *p, size_t size);
void assert_fail(const char *expr, const char *file, const char *func, long line);
// void logf(char *fmt, ...);
// void infof(char *fmt, ...);
// void warnf(char *fmt, ...);
// void errorf(char *fmt, ...);
