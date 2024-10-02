#ifndef _LANG_H_
#define _LANG_H_

//void lang_run(char *source);
int lang_run_file(const char *path);
void lang_run_prompt(void);

void lang_error(const int line, const char *msg);
void lang_report(const int line, const char *where, const char *msg);

#endif /* _LANG_H_ */
