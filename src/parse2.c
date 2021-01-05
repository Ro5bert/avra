#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avra2.h"

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

char *
toktype2str(int type)
{
	switch (type) {
	case TOK_EOF:    return "EOF";
	case TOK_EOL:    return "EOL";
	case TOK_IDENT:  return "IDENT";
	case TOK_DIR:    return "DIR";
	case TOK_NUM:    return "NUM";
	case TOK_STR:    return "STR";
	case TOK_CHAR:   return "CHAR";
	case TOK_COLON:  return "COLON";
	case TOK_COMMA:  return "COMMA";
	case TOK_QMARK:  return "QMARK";
	case TOK_LPAREN: return "LPAREN";
	case TOK_RPAREN: return "RPAREN";
	case TOK_LBRACK: return "LBRACK";
	case TOK_RBRACK: return "RBRACK";
	case TOK_UNARY:  return "UNARY";
	case TOK_BINARY: return "BINARY";
	case TOK_PM:     return "PM";
	default:         return "(invalid)";
	}
}

int isident(int c) { return isalpha(c) || isdigit(c) || c == '_' || c == '@'; }
int iseol(int c) {
	switch (c) {
		case '\n': case '\r': case '\f': case '\v':
			return 1;
		default:
			return 0;
	}
}
int iscomment(int c) { return !iseol(c) && c != EOF; }
int ishspace(int c) { return c == ' ' || c == '\t'; }
int isbindigit(int c) { return ('0' <= c && c <= '1') || c == '_'; }
int isoctdigit(int c) { return ('0' <= c && c <= '7') || c == '_'; }
int isdecdigit(int c) { return isdigit(c) || c == '_'; }
int ishexdigit(int c) { return isxdigit(c) || c == '_'; }

#define TOK_MIN_CAP 64

struct tok {
	char *t;
	size_t cap;
	int type;
};

#define IO_MIN_CAP 4096

struct io {
	FILE *f;
	char *buf;
	size_t boff; /* Offset into buf of beginning of current token */
	size_t eoff; /* Offset into buf of end of current token */
	size_t len;  /* Number of bytes in buf */
	size_t cap;  /* Capacity of buf*/
};

size_t
iorem(struct io *io)
{ return io->len - io->boff; }

void
ioread(struct io *io, size_t n)
{
	size_t rem;

	rem = iorem(io);
	if (n > io->cap - rem) {
		if (io->cap == 0)
			io->cap = IO_MIN_CAP;
		while (n > io->cap - rem)
			io->cap *= 2;
		io->buf = erealloc(io->buf, io->cap);
	}
	memmove(io->buf, io->buf + io->boff, rem);
	io->eoff -= io->boff;
	io->boff = 0;
	io->len = rem + fread(io->buf + rem, 1, io->cap - rem, io->f);
}

int
ionext(struct io *io)
{
	if (iorem(io) == 0) {
		ioread(io, 1);
		if (iorem(io) == 0)
			return EOF;
	}
	return io->buf[io->eoff++];
}

int
iopeek(struct io *io, size_t i)
{
	if (iorem(io) <= i) {
		ioread(io, i+1);
		if (iorem(io) <= i)
			return EOF;
	}
	return io->buf[io->eoff+i];
}

void
iobackup(struct io *io)
{
	if (io->eoff == io->boff)
		assert(feof(io->f) || ferror(io->f));
	else
		io->eoff--;
}

void
ioaccept(struct io *io, int (*isvalid)(int))
{
	int c;

	while (isvalid(c = iopeek(io, 0)))
		ionext(io);
}

int
ioaccept1(struct io *io, char *set)
{
	char *p;

	if ((p = strchr(set, iopeek(io, 0))) != 0) {
		ionext(io);
		return *p;
	} else {
		return '\0';
	}
}

void
ioignore(struct io *io)
{ io->boff = io->eoff; }

struct tok *
iotok(struct io *io, struct tok *tok, int type)
{
	size_t len;

	len = io->eoff - io->boff;
	if (tok->cap <= len) {
		if (tok->cap == 0)
			tok->cap = TOK_MIN_CAP;
		while (tok->cap <= len)
			tok->cap *= 2;
		tok->t = erealloc(tok->t, tok->cap);
	}
	strncpy(tok->t, &io->buf[io->boff], len);
	tok->t[len] = '\0';
	tok->type = type;
	io->boff = io->eoff;
	return tok;
}

struct tok *lexcharlit(struct tok *tok, struct io *io) { assert(false); };
struct tok *lexstrlit(struct tok *tok, struct io *io) { assert(false); };

struct tok *
nexttok(struct tok *tok, struct io *io)
{
	int c;

again:
	ioaccept(io, ishspace);
	ioignore(io);

	c = ionext(io);

	if (isalpha(c) || c == '_' || c == '@') {
		ioaccept(io, isident);
		return iotok(io, tok, TOK_IDENT);
	}

	switch (c) {
	case ';':
		ioaccept(io, iscomment);
		ioignore(io);
		c = ionext(io);
		if (c == EOF)
			return iotok(io, tok, TOK_EOF);
		goto EOL;

	case '.':
	case '#':
		ioignore(io); /* Ignore the '.' or '#'; keep the name only. */
		ioaccept(io, isident);
		return iotok(io, tok, TOK_DIR);

	/* Number literals: */
	/* TODO floating point */
	case '0': /* 0b, 0x, 0 */
		switch (c = iopeek(io, 0)) {
		case 'b':
		case 'x':
			ionext(io);
			ioaccept(io, c == 'b' ? isbindigit : ishexdigit);
			return iotok(io, tok, TOK_NUM);
		default:
			ioaccept(io, isoctdigit);
			return iotok(io, tok, TOK_NUM);
		}
	case '1': case '2': case '3':
	case '4': case '5': case '6':
	case '7': case '8': case '9':
		ioaccept(io, isdecdigit);
		return iotok(io, tok, TOK_NUM);
	case '$':
		ioaccept(io, ishexdigit);
		return iotok(io, tok, TOK_NUM);

	case '\'':
		return lexcharlit(tok, io);
	case '"':
		return lexstrlit(tok, io);

	case ':': return iotok(io, tok, TOK_COLON);
	case ',': return iotok(io, tok, TOK_COMMA);
	case '?': return iotok(io, tok, TOK_QMARK);
	case '(': return iotok(io, tok, TOK_LPAREN);
	case ')': return iotok(io, tok, TOK_RPAREN);
	case '[': return iotok(io, tok, TOK_LBRACK);
	case ']': return iotok(io, tok, TOK_RBRACK);
	case '~': return iotok(io, tok, TOK_UNARY);
	case '+': case '-':
		/* Can be unary or binary, so + and - have special token type. */
		return iotok(io, tok, TOK_PM);
	case '*': case '/': case '%': case '^':
		return iotok(io, tok, TOK_BINARY);
	case '<': /* <<, <=, < */
		ioaccept1(io, "<=");
		return iotok(io, tok, TOK_BINARY);
	case '>': /* >>, >=, > */
		ioaccept1(io, ">=");
		return iotok(io, tok, TOK_BINARY);
	case '=': /* ==, = */
		ioaccept1(io, "=");
		return iotok(io, tok, TOK_BINARY);
	case '&': /* &&, & */
		ioaccept1(io, "&");
		return iotok(io, tok, TOK_BINARY);
	case '|': /* ||, | */
		ioaccept1(io, "|");
		return iotok(io, tok, TOK_BINARY);
	case '!': /* !=, = */
		if (ioaccept1(io, "="))
			return iotok(io, tok, TOK_BINARY);
		else
			return iotok(io, tok, TOK_UNARY);

	EOL:
	case '\n': case '\r': case '\f': case '\v':
		if (c == '\r')
			ioaccept1(io, "\n");
		return iotok(io, tok, TOK_EOL);

	case EOF:
		return iotok(io, tok, TOK_EOF);

	case '\\':
		if ((c = ioaccept1(io, "\n\r\f\v"))) {
			if (c == '\r')
				ioaccept1(io, "\n");
			goto again;
		}
		/* FALLTHROUGH (backslash is invalid if not before EOL) */

	default:
		/* TODO */
		fprintf(stderr, "lexer error!\n");
		exit(1);
	}
}

int
main(int argc, char **argv)
{
	struct tok tok = {0};
	struct io io = {0};
	assert(argc == 2);
	
	io.f = fopen(argv[1], "rb");
	assert(io.f != 0);
	
	do {
		nexttok(&tok, &io);
		printf("%s: %s\n", toktype2str(tok.type), tok.t);
	} while (tok.type != TOK_EOF);

	fclose(io.f);
	free(io.buf);
	free(tok.t);
}
