#include "main.hpp"

#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
  if (argc > 1) {
    std::cout << "Usage: main [script]" << std::endl;
    return 1;
  } else if (argc == 1) {
    Main::run_file(argv[0]);
  } else {
    Main::run_prompt();
  }

  return 0;
}

void Main::run(std::string source) {
  // Scanner
  // Array of tokens


  // for now just print tokens
}

void Main::run_file(std::string path) {
  std::ifstream f(path);
  std::stringstream buffer;
  buffer << f.rdbuf();
  std::string src_str = buffer.str();
  run(src_str);
}

void Main::run_prompt() {
  std::string line;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }
    Main:run(line);
  }
}