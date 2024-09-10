#ifndef _RUN_HPP_
#define _RUN_HPP_

#include <iostream>

class Main {
public:
  static void run_file(std::string path);
  static void run_prompt();
  static void run(std::string source);
};

#endif // _RUN_HPP_