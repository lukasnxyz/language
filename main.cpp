#include "main.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "lexer.hpp"

bool Main::had_error = false;

int main(int argc, char **argv) {
  if (argc > 1) {
    std::cout << "Usage: main [script]" << std::endl;
    return 1;
  } else if (argc == 1) {
    return Main::run_file(argv[0]);
  } else {
    Main::run_prompt();
  }

  return 0;
}

// TODO: return exit code?
void Main::run(std::string source) {
  Scanner scanner(source);
  //std::vector<Token> tokens = scanner.scan_tokens();

  // for now just print tokens
}

int Main::run_file(std::string path) {
  std::ifstream f(path);
  std::stringstream buffer;
  buffer << f.rdbuf();
  std::string src_str = buffer.str();
  run(src_str);

  if (had_error) {
    return 2;
  } else {
    return 0;
  }
}

void Main::run_prompt() {
  std::string line;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }
    run(line);
    had_error = false;
  }
}

void Main::error(int line, std::string msg) {
  report(line, "", msg);
}

void Main::report(int line, std::string where, std::string msg) {
  std::cout << "[line " << line << "] Error" << where << ": " << msg << std::endl;
  had_error = true;
}
