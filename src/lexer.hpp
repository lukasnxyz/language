#ifndef _LEXER_HPP_
#define _LEXER_HPP_

#include <vector>

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
	TokenType type;
	std::string lexeme;
	std::string literal;
	int line;

public:
	Token(TokenType type, std::string lexeme, std::string literal, int line) : 
		type(type), lexeme(lexeme), literal(literal), line(line) {}

	friend std::ostream& operator<< (std::ostream& os, const Token& t);

	TokenType get_type(void) { return type; }
	std::string get_lexeme(void) { return lexeme; }
	std::string get_literal(void) { return literal; }
	int get_line(void) { return line; }
};

class Scanner {
private:
	std::string source;
	std::vector<Token> tokens;
	size_t start;
	size_t current;
	size_t line;

	bool is_at_end(void) { return current >= source.size(); }
	void scan_token(void);
	char advance(void) { return source[current++]; }
	void add_token(TokenType type, std::string literal); 
	void add_token(TokenType type) { add_token(type, nullptr); }
	bool match(char expected);
	char peek(void);
	void string(void);
	void number(void);
	char peek_next(void);

public:
	Scanner(std::string source) : source(source), start(0), current(0), line(1) {}
	std::vector<Token> scan_tokens(void); 
};

#endif // _LEXER_HPP_ 
