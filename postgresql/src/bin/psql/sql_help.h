/*
 * *** Do not change this file by hand. It is automatically
 * *** generated from the DocBook documentation.
 *
 * generated by
 *     /usr/bin/perl create_help.pl ../../../doc/src/sgml/ref sql_help
 *
 */

#ifndef SQL_HELP_H
#define SQL_HELP_H

#include "pqexpbuffer.h"

struct _helpStruct
{
	const char	   *cmd;		/* the command name */
	const char	   *help;		/* the help associated with it */
	void (*syntaxfunc)(PQExpBuffer);	/* function that prints the syntax associated with it */
	int				nl_count;	/* number of newlines in syntax (for pager) */
};

extern const struct _helpStruct QL_HELP[];

#define QL_HELP_COUNT	178		/* number of help items */
#define QL_MAX_CMD_LEN	32		/* largest strlen(cmd) */


#endif /* SQL_HELP_H */