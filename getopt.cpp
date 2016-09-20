#include "getopt.h"
#include <memory>

static int optind = 1;
char * optarg = nullptr;
static int opterr = 1;
static bool optinited = false;
static char optnames[128];

void parse_arg(const char *optstring) {
	// do not use strchr
	char curname = 0;
	memset(optnames, 0, sizeof optnames);
	while (*optstring != '\0') {
		if (*optstring == ':') {
			if (*(optstring + 1) == ':') {
				optnames[curname] = 3; // optional
			}
			else {
				optnames[curname] = 2; // an argument
			}
		}
		else {
			curname = *optstring;
			optnames[curname] = 1; // valid
		}
		optstring++;
	}
}

int getopt(int argc, char *const argv[], const char *optstring) {
	if (!optinited) {
		parse_arg(optstring);
		optinited = true;
	}
	optarg = nullptr;
	if (optind >= argc) {
		return -1;
	}
	else if (argv[optind][0] != '-' || argv[optind][1] == '\0') {
		// begin with no dash or dash alone
		return -1;
	}
	char optname = argv[optind][1];
	if (optnames[optname] == 0) {
		return -1;
		return '?';
	}
	if (optnames[optname] == 2) {
		if (++optind >= argc) {
			return -1;
		}
		optarg = argv[optind];
	}
	return optname;
}