/*
 * OpenComal -- a free Comal implementation
 *
 * This file is part of the OpenComal package.
 * (c) Copyright 1992-2002 Jos Visser <josv@osp.nl>
 *
 * The OpenComal package is covered by the GNU General Public
 * License. See doc/LICENSE for more information.
 */

/** @file
 * OpenComal SYS routines
 */

#ifndef PDCDSYS_H
#define PDCDSYS_H

#include "pdcdef.h"

#include <stdio.h>

extern void sys_init(void);
extern void sys_tini(void);
extern void sys_rand(long *result, long *scale);

/** Randomizes the random number generator */
extern void sys_randomize(long seed);

extern int sys_escape(void);
extern void sys_put(int stream, const char *buf, long len);
extern void sys_page(FILE * f);

/** Erase the current line to the right of the cursor to the end of the current line */
extern void sys_clrtoeol(FILE * f);

extern int sys_system(char *cmd);
extern void sys_setpaged(int flag);
extern void sys_cursor(FILE * f, long y, long x);

/** Returns the current column position of the cursor on the text screen */
extern int sys_curcol(void);

/** Returns the current row of the text screen that the cursor is on */
extern int sys_currow(void);

extern void sys_nl(int stream);

/** Move the cursor to the next tab stop */
extern void sys_ht(int stream);

/** Get the current tab stop interval */
extern long sys_zone_num(void);

/** Set the tab stop interval */
extern void sys_zone(long size);

extern void sys_screen_readjust(void);
extern int sys_yn(int stream, const char *s);
extern int sys_get(int stream, char *line, int maxlen, const char *prompt);
extern int sys_edit(int stream, char *line, int maxlen, int cursor);
extern char *sys_dir_string();
extern void sys_dir(const char *pattern);
extern const char *sys_unit_string();

/** Return a string containing enough spaces to get to a column */
extern const char *sys_tab_string(long col);

extern void sys_unit(char *unit);
extern void sys_chdir(char *dir);
extern void sys_rmdir(char *dir);
extern void sys_mkdir(char *dir);
extern char *sys_key(long delay);

extern int sys_call_scan(struct id_rec *id, struct exp_list *exproot,
			 char *errtext);
extern int sys_call(struct id_rec *id, struct exp_list *exproot,
		    int calltype, void **result, enum VAL_TYPE *type);
extern void sys_sys_exp(struct exp_list *exproot, void **result, enum
			VAL_TYPE *type);
extern void sys_syss_exp(struct exp_list *exproot, struct string **result, enum
			 VAL_TYPE *type);
extern int sys_sys_stat(struct exp_list *exproot);

#endif
