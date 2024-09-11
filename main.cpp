#include <iostream>

#include "lang.hpp"

int main(int argc, char **argv) {
  if (argc > 1) {
    std::cout << "Usage: main [script]" << std::endl;
    return 1;
  } else if (argc == 1) {
    return Lang::run_file(argv[0]);
  } else {
    Lang::run_prompt();
  }

  return 0;
}
