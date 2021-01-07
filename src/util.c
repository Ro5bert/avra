#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "avra2.h"

void *
emalloc(size_t size)
{
	void *p = malloc(size);
	if (p == 0)
		exit(1); /* TODO */
	return p;
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p = calloc(nmemb, size);
	if (p == 0)
		exit(1); /* TODO */
	return p;
}

void *
erealloc(void *p, size_t size)
{
	p = realloc(p, size);
	if (p == 0)
		exit(1); /* TODO */
	return p;
}

void
assert_fail(const char *expr, const char *file, const char *func, long line)
{
	fprintf(stderr, "fatal internal error: assertion failed %s (%s:%s:%ld)\n",
			expr, file, func, line);
	fprintf(stderr, "Please report this at " AVRA_REPO_URL "\n");
	abort();
}
