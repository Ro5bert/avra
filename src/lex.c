#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avra2.h"

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

static int
isident(int c)
{ return isalpha(c) || isdigit(c) || c == '_' || c == '@'; }

static int
iseol(int c)
{
	switch (c) {
		case '\n': case '\r': case '\f': case '\v':
			return 1;
		default:
			return 0;
	}
}

static int
iscomment(int c)
{ return !iseol(c) && c != EOF; }

static int
ishspace(int c)
{ return c == ' ' || c == '\t'; }

static int
isbindigit(int c)
{ return ('0' <= c && c <= '1') || c == '_'; }

static int
isoctdigit(int c)
{ return ('0' <= c && c <= '7') || c == '_'; }

static int
isdecdigit(int c)
{ return isdigit(c) || c == '_'; }

static int
ishexdigit(int c)
{ return isxdigit(c) || c == '_'; }

size_t
lrem(struct lexer *l)
{ return l->len - l->boff; }

void
lread(struct lexer *l, size_t n)
{
	size_t rem;

	rem = lrem(l);
	if (n > l->cap - rem) {
		if (l->cap == 0)
			l->cap = LEXER_MIN_CAP;
		while (n > l->cap - rem)
			l->cap *= 2;
		l->buf = erealloc(l->buf, l->cap);
	}
	memmove(l->buf, l->buf + l->boff, rem);
	l->eoff -= l->boff;
	l->boff = 0;
	l->len = rem + fread(l->buf + rem, 1, l->cap - rem, l->f);
}

int
lnext(struct lexer *l)
{
	if (lrem(l) == 0) {
		lread(l, 1);
		if (lrem(l) == 0)
			return EOF;
	}
	return l->buf[l->eoff++];
}

int
lpeek(struct lexer *l, size_t i)
{
	if (lrem(l) <= i) {
		lread(l, i+1);
		if (lrem(l) <= i)
			return EOF;
	}
	return l->buf[l->eoff+i];
}

void
lbackup(struct lexer *l)
{
	if (l->eoff == l->boff)
		assert(feof(l->f) || ferror(l->f));
	else
		l->eoff--;
}

void
laccept(struct lexer *l, int (*isvalid)(int))
{
	int c;

	while (isvalid(c = lpeek(l, 0)))
		lnext(l);
}

int
laccept1(struct lexer *l, char *set)
{
	char *p;

	if ((p = strchr(set, lpeek(l, 0))) != 0) {
		lnext(l);
		return *p;
	} else {
		return '\0';
	}
}

void
lignore(struct lexer *l)
{ l->boff = l->eoff; }

struct tok *
ltok(struct lexer *l, struct tok *tok, int type)
{
	size_t len;

	len = l->eoff - l->boff;
	if (tok->cap <= len) {
		if (tok->cap == 0)
			tok->cap = TOK_MIN_CAP;
		while (tok->cap <= len)
			tok->cap *= 2;
		tok->t = erealloc(tok->t, tok->cap);
	}
	strncpy(tok->t, &l->buf[l->boff], len);
	tok->t[len] = '\0';
	tok->type = type;
	l->boff = l->eoff;
	return tok;
}

struct tok *
lexcharlit(struct tok *tok, struct lexer *l)
{ assert(false); };

struct tok *
lexstrlit(struct tok *tok, struct lexer *l)
{ assert(false); };

struct tok *
nexttok(struct tok *tok, struct lexer *l)
{
	int c;

again:
	laccept(l, ishspace);
	lignore(l);

	c = lnext(l);

	if (isalpha(c) || c == '_' || c == '@') {
		laccept(l, isident);
		return ltok(l, tok, TOK_IDENT);
	}

	switch (c) {
	case ';':
		laccept(l, iscomment);
		lignore(l);
		c = lnext(l);
		if (c == EOF)
			return ltok(l, tok, TOK_EOF);
		goto EOL;

	case '.':
	case '#':
		lignore(l); /* Ignore the '.' or '#'; keep the name only. */
		laccept(l, isident);
		return ltok(l, tok, TOK_DIR);

	/* Number literals: */
	/* TODO floating point */
	case '0': /* 0b, 0x, 0 */
		switch (c = lpeek(l, 0)) {
		case 'b':
		case 'x':
			lnext(l);
			laccept(l, c == 'b' ? isbindigit : ishexdigit);
			return ltok(l, tok, TOK_NUM);
		default:
			laccept(l, isoctdigit);
			return ltok(l, tok, TOK_NUM);
		}
	case '1': case '2': case '3':
	case '4': case '5': case '6':
	case '7': case '8': case '9':
		laccept(l, isdecdigit);
		return ltok(l, tok, TOK_NUM);
	case '$':
		laccept(l, ishexdigit);
		return ltok(l, tok, TOK_NUM);

	case '\'':
		return lexcharlit(tok, l);
	case '"':
		return lexstrlit(tok, l);

	case ':': return ltok(l, tok, TOK_COLON);
	case ',': return ltok(l, tok, TOK_COMMA);
	case '?': return ltok(l, tok, TOK_QMARK);
	case '(': return ltok(l, tok, TOK_LPAREN);
	case ')': return ltok(l, tok, TOK_RPAREN);
	case '[': return ltok(l, tok, TOK_LBRACK);
	case ']': return ltok(l, tok, TOK_RBRACK);
	case '~': return ltok(l, tok, TOK_UNARY);
	case '+': case '-':
		/* Can be unary or binary, so + and - have special token type. */
		return ltok(l, tok, TOK_PM);
	case '*': case '/': case '%': case '^':
		return ltok(l, tok, TOK_BINARY);
	case '<': /* <<, <=, < */
		laccept1(l, "<=");
		return ltok(l, tok, TOK_BINARY);
	case '>': /* >>, >=, > */
		laccept1(l, ">=");
		return ltok(l, tok, TOK_BINARY);
	case '=': /* ==, = */
		laccept1(l, "=");
		return ltok(l, tok, TOK_BINARY);
	case '&': /* &&, & */
		laccept1(l, "&");
		return ltok(l, tok, TOK_BINARY);
	case '|': /* ||, | */
		laccept1(l, "|");
		return ltok(l, tok, TOK_BINARY);
	case '!': /* !=, = */
		if (laccept1(l, "="))
			return ltok(l, tok, TOK_BINARY);
		else
			return ltok(l, tok, TOK_UNARY);

	EOL:
	case '\n': case '\r': case '\f': case '\v':
		if (c == '\r')
			laccept1(l, "\n");
		return ltok(l, tok, TOK_EOL);

	case EOF:
		return ltok(l, tok, TOK_EOF);

	case '\\':
		if ((c = laccept1(l, "\n\r\f\v"))) {
			if (c == '\r')
				laccept1(l, "\n");
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
	struct lexer l = {0};
	assert(argc == 2);
	
	l.f = fopen(argv[1], "rb");
	assert(l.f != 0);
	
	do {
		nexttok(&tok, &l);
		printf("%s: %s\n", toktype2str(tok.type), tok.t);
	} while (tok.type != TOK_EOF);

	fclose(l.f);
	free(l.buf);
	free(tok.t);
}
