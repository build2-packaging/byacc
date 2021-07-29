/* Define to 1 to enable backtracking extension */
#define YYBTYACC 1

/* Define to maximum table size (default: 32500) */
#define MAXTABLE INT_MAX

/* Define to 1 if you want to perform memory-leak testing. */
/* #undef NO_LEAKS */

/* Define to 1 if you want to perform memory-leak testing. */
/* #undef YY_NO_LEAKS */

#ifndef _WIN32
#  define HAVE_FCNTL_H 1
#  define HAVE_GETOPT 1
#  define HAVE_MKSTEMP 1
#  define HAVE_VSNPRINTF 1
#else
#  define HAVE_VSNPRINTF 1
#  ifdef __MINGW32__
#    define HAVE_GETOPT 1
#  endif
/* Note: tmpfile() is unusable on MinGW so we are providing our own. */
#  include <stdio.h>
   FILE *mytmpfile ();
#  define tmpfile mytmpfile
#endif
