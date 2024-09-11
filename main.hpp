#ifndef _RUN_HPP_
#define _RUN_HPP_

#include <iostream>

class Main {
private:
  static bool had_error;
  static void report(int line, std::string where, std::string msg);

public:
  static int run_file(std::string path);
  static void run_prompt();
  static void run(std::string source);
  static void error(int line, std::string msg);
};

#endif // _RUN_HPP_