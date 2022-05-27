#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* relevant ASCII codes */
#define BEL "\007"
#define ESC "\033"

/* relevant ANSI Escape Sequences */
#define OSC ESC "]"
#define APC ESC "_"
#define ST  ESC "\\"

const char * app_name;

void die(int rv) {
	if (rv) {
		if (errno) {
			perror(app_name);
			exit(-errno);
		}
		exit(rv);
	}
}

int
main(int argc, char ** argv)
{
	app_name = argv[0];
	const char * term = getenv("TERM");
	const char * open, * close;
	if (strncmp(term, "screen", 6) == 0) { /* screen is special */
		open = APC;
		close = ST;
	}
	else {
		open = OSC "0;";  /* some terminals also accept OSC "2;" */
		close = BEL;
	}
	die(0 > fputs(open, stdout));
	for (int i = 1; i < argc; i++) {
		die(0 > fputs(argv[i], stdout));
		if (i != argc - 1)
			die(EOF == fputc(' '    , stdout));
	}
	die(0 > fputs(close, stdout));
}
