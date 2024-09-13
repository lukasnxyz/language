#include "lexer.hpp"

#include <vector>

#include "lang.hpp"

std::vector<Token> Scanner::scan_tokens() {
	std::vector<Token> tokens;
	while (!is_at_end()) {
		start = current;
		scan_token();
	}
	tokens.push_back(Token(END_OF_FILE, "", line));

	return tokens;
}

void Scanner::scan_token() {
	char c = advance();
	switch (c) {
		case '(': add_token(LEFT_PAREN); break;
    case ')': add_token(RIGHT_PAREN); break;
    case '{': add_token(LEFT_BRACE); break;
    case '}': add_token(RIGHT_BRACE); break;
    case ',': add_token(COMMA); break;
    case '.': add_token(DOT); break;
    case '-': add_token(MINUS); break;
    case '+': add_token(PLUS); break;
    case ';': add_token(SEMICOLON); break;
    case '*': add_token(STAR); break; 
		//default: Lang.error(line, "Unexpected character."); break;
	}
}

void Scanner::add_token(TokenType type) { // Object literal
	std::string txt = source.substr(start, current);
	tokens.push_back(Token(type, txt, line));
}

std::ostream& operator<< (std::ostream& os, Token& t) { // const Token& t
	//return os << t.get_type() << " " << t.get_lexeme() << " " << t.get_literal();
	return os << t.get_type() << " " << t.get_lexeme();
}
