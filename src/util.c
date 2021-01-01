#include <stdlib.h>

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
