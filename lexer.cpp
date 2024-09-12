#include "lexer.hpp"

#include <vector>

std::vector<Token> Scanner::scan_tokens() {
	std::vector<Token> tokens;
	while (!is_at_end()) {
		start = current;
		scan_token();
	}
	tokens.push_back(Token(EOF, "", line));

	return tokens;
}

void Scanner::scan_token() {
	char c = advance();
}

void Scanner::add_token(TokenType type, Object literal) {
	std::string txt = source.substr(start, current);
	tokens.push_back(new Token(type, text, literal, line));
}

std::ostream& operator<< (std::ostream& os, Token& t) { // const Token& t
	//return os << t.get_type() << " " << t.get_lexeme() << " " << t.get_literal();
	return os << t.get_type() << " " << t.get_lexeme();
}
