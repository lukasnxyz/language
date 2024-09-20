#ifndef _LEXER_HPP_
#define _LEXER_HPP_

#include <vector>
#include <variant>
#include <map>

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

using literal_variant = std::variant<std::string, double>;

class Token {
private:
	TokenType type;
	std::string lexeme;
	literal_variant literal;
	int line;

public:
	Token(TokenType type, std::string lexeme, literal_variant literal, int line) : 
		type(type), lexeme(lexeme), literal(literal), line(line) {}

	friend std::ostream& operator<<(std::ostream& os, Token& t);

	TokenType get_type(void) { return type; }
	std::string get_lexeme(void) { return lexeme; }
	literal_variant get_literal(void) { return literal; }
	int get_line(void) { return line; }
};

class Scanner {
private:
	std::string source;
	std::vector<Token> tokens;
	size_t start;
	size_t current;
	size_t line;

  static const std::unordered_map<std::string, TokenType> keywords;

	bool is_at_end(void) { return current >= source.size(); }
	void scan_token(void);
	char advance(void) { return source[current++]; }
	void add_token(TokenType type, literal_variant literal); // add token needs to take string or double or etc.
	void add_token(TokenType type) { add_token(type, nullptr); }
	bool match(char expected);
	char peek(void);
	void string(void);
	void number(void);
  void identifier(void);
	char peek_next(void);

public:
	Scanner(std::string source) : source(source), start(0), current(0), line(1) {}
	std::vector<Token> scan_tokens(void); 

  const std::unordered_map<std::string, TokenType> Scanner::keywords = {
    {"and",    TokenType::AND},
    {"class",  TokenType::CLASS},
    {"else",   TokenType::ELSE},
    {"false",  TokenType::FALSE},
    {"for",    TokenType::FOR},
    {"fun",    TokenType::FUN},
    {"if",     TokenType::IF},
    {"nil",    TokenType::NIL},
    {"or",     TokenType::OR},
    {"print",  TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super",  TokenType::SUPER},
    {"this",   TokenType::THIS},
    {"true",   TokenType::TRUE},
    {"var",    TokenType::VAR},
    {"while",  TokenType::WHILE}
  };
};

#endif // _LEXER_HPP_ 
