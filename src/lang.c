#include "lang.h"
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

static size_t had_error = 0;

static void lang_run(char *source) {
  struct Scanner *scanner = scanner_construct(source);
  struct Token *tokens = scanner_scan_tokens(scanner);

  /* for now just print tokens */
  for (size_t i = 0; i < scanner->num_tokens; i++) {
    printf("token: %s\n", tokens[i].lexeme);
  }
}

int lang_run_file(const char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    fprintf(stderr, "failed to allocate memory!");
    had_error = 1;
    return 1;
  }
  fseek(f, 0, SEEK_END);
  long length = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *src_str = (char *)malloc(length + 1);
  if (src_str == NULL) {
    fprintf(stderr, "failed to allocate memory!");
    had_error = 1;
    fclose(f);
    return 1;
  }

  fread(src_str, 1, length, f);
  src_str[length] = '\0'; 
  fclose(f);

  lang_run(src_str);

  free(src_str);
  if (had_error) {
    return 1;
  } 
  return 0;
}

void lang_run_prompt(void) {
  for (;;) {
    printf("> ");
    char *line = NULL;
    fgets(line, 1000, stdin);
    if (line == NULL) {
      break;
    }
    lang_run(line);
    had_error = 0;
  }
}

void lang_error(const int line, const char *msg) {
  lang_report(line, "", msg);
}

void lang_report(const int line, const char *where, const char *msg) {
  fprintf(stderr, "'[line %d]' Error %s: %s\n", line, where, msg);
  had_error = 1;
}
