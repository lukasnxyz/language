#ifndef _LEXER_HPP_
#define _LEXER_HPP_

#include <iostream>
#include <vector>

#include "utils.hpp"

enum TokenType {
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
	COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

	BANG, BANG_EQUAL,
	EQUAL, EQUAL_EQUAL,
	GREATER, GREATER_EQUAL,
	LESS, LESS_EQUAL,

	IDENTIFIER, STRING, NUMBER,

	AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
	PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

	END_OF_FILE
};

class Token {
private:
	Final<TokenType> type;
	Final<std::string> lexeme;
	//Final<Object> literal;
	Final<int> line;

public:
	Token(TokenType type, std::string lexeme, int line) : 
		type(type), lexeme(lexeme), line(line) {}

	friend std::ostream& operator<< (std::ostream& os, const Token& t);

	TokenType get_type() { return type.get(); }
	std::string get_lexeme() { return lexeme.get(); }
	// obj get_literal() { return literal.get(); }
	int get_line() { return line.get(); }
};

class Scanner {
private:
	Final<std::string> source;
	std::vector<Token> tokens;

public:
	Scanner(std::string source) : source(source) {}
	std::vector<Token> scan_tokens(); 
};

#endif // _LEXER_HPP_ 
