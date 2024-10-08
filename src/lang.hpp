#ifndef _LANG_HPP_
#define _LANG_HPP_

#include <string>

class Lang {
private:
	static bool had_error;
	static void report(int line, std::string where, std::string msg);

public:
	static int run_file(std::string path);
	static void run_prompt();
	static void run(std::string source);
	static void error(int line, std::string msg);
};

#endif // _LANG_HPP_
