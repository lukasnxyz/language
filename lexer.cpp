#include "lexer.hpp"

#include <vector>

std::vector<Token> Scanner::scan_tokens() {
	std::vector<Token> tokens;

	return tokens;
}

std::ostream& operator<< (std::ostream& os, Token& t) { // const Token& t
	//return os << t.get_type() << " " << t.get_lexeme() << " " << t.get_literal();
	return os << t.get_type() << " " << t.get_lexeme();
}
