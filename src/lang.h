#ifndef _LANG_H_
#define _LANG_H_

#include "utils.h"

//void lang_run(char *source);
int lang_run_file(char *path);
void lang_run_prompt(void);

void lang_error(int line, char *msg);
void lang_report(int line, char *where, char *msg);

#endif /* _LANG_H_ */
