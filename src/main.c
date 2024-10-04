#include <stdio.h>
#include "lang.h"

/*
 * Todo: 
 * - remove casts from mallocs
 * - star on type not name
  */

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage: main [script]\n");
    return 1;
  } else if (argc == 2) {
    return lang_run_file(argv[0]);
  } else {
    lang_run_prompt();
  }

  return 0;
}
