/* TODO copyright */

/* Use main(int argc, char **argv).
 * Requires string.h and stdbool.h to be included.
 * At the end of parsing options, argv will be a null-terminated array
 * containing all the arguments (i.e., non-options), starting with the program
 * name, and argc with be the length of argv.
 * Supports both POSIX- and GNU-style options.
 * Arguments and options may be interspersed, but everything after "--" is
 * considered an argument, as per convention. */

#define OPTBEGIN {\
	size_t i_, last_;\
	char *opt_, *arg_;\
	bool skip_ = false, long_, attached_, argused_;\
	for (i_ = last_ = 1; argv[i_]; i_++) {\
		if (skip_ || argv[i_][0] != '-' || argv[i_][1] == '\0') {\
			argv[last_++] = argv[i_];\
			continue;\
		}\
		argc--;\
		if (argv[i_][1] == '-' && argv[i_][2] == '\0') {\
			skip_ = true;\
			continue;\
		}\
		long_ = argv[i_][1] == '-';\
		opt_ = long_ ? &argv[i_][2] : &argv[i_][1];\
		do {\
			if (long_ && (arg_ = strchr(opt_, '=')))\
				attached_ = true, *arg_++ = '\0';\
			else if (!long_ && opt_[1] != '\0')\
				attached_ = true, arg_ = &opt_[1];\
			else\
				attached_ = false, arg_ = argv[i_+1];\
			argused_ = false;\
			if (0) {}

#define OPT(o) \
			else if (o)

#define SHORT_ARG(s, arg) (!long_ && opt_[0] == (s)\
                           && ((arg) = arg_) && (argused_ = true))

#define SHORT(s) (!long_ && opt_[0] == (s))

#define LONG_ARG(s, arg) (long_ && !strcmp(opt_, (s))\
                          && ((arg) = arg_) && (argused_ = true))

#define LONG(s) (long_ && !strcmp(opt_, (s)) && !attached_)

#define OPTERR() \
			else

#define OPTEND \
		} while (!long_ && !argused_ && *++opt_ != '\0');\
		if (argused_ && !attached_)\
			i_++;\
	}\
	argv[last_] = NULL;\
}
