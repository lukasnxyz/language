#include "lang.hpp"

#include <iostream>
#include <string>
#include <fstream>

#include "scanner.hpp"

bool Lang::had_error = false;

// TODO: return exit code?
void Lang::run(std::string source) {
  Scanner scanner(source);
  std::vector<Token> tokens = scanner.scan_tokens();

  // for now just print tokens
	for (auto& token : tokens) {
		std::cout << token << std::endl;
	}
}

int Lang::run_file(std::string path) {
  std::ifstream f(path);
  std::string str;
  std::string src;
  while (std::getline(f, str)) {
    src += str;
    src.push_back('\n');
  }  

  run(src);

  if (had_error) {
    return 2;
  } else {
    return 0;
  }
}

void Lang::run_prompt() {
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

void Lang::error(int line, std::string msg) {
  report(line, "", msg);
}

void Lang::report(int line, std::string where, std::string msg) {
  std::cout << "[line " << line << "] Error" << where << ": " << msg << std::endl;
  had_error = true;
}
