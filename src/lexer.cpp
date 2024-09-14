#include "lexer.hpp"

#include <iostream>
#include <vector>
#include <cctype>

#include "lang.hpp"

std::vector<Token> Scanner::scan_tokens(void) {
	std::vector<Token> tokens;
	while (!is_at_end()) {
		start = current;
		scan_token();
	}
	tokens.push_back(Token(TokenType::END_OF_FILE, "", nullptr, line));

	return tokens;
}

void Scanner::scan_token(void) {
	char c = advance();
	switch (c) {
		case '(': add_token(TokenType::LEFT_PAREN); break;
    case ')': add_token(TokenType::RIGHT_PAREN); break;
    case '{': add_token(TokenType::LEFT_BRACE); break;
    case '}': add_token(TokenType::RIGHT_BRACE); break;
    case ',': add_token(TokenType::COMMA); break;
    case '.': add_token(TokenType::DOT); break;
    case '-': add_token(TokenType::MINUS); break;
    case '+': add_token(TokenType::PLUS); break;
    case ';': add_token(TokenType::SEMICOLON); break;
    case '*': add_token(TokenType::STAR); break; 

		case '!':
			add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
			break;
		case '=':
			add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
			break;
		case '<':
			add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
			break;
		case '>':
			add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
			break;
		case '/':
			if (match('/')) {
				while (peek() != '\n' && !is_at_end()) {
					advance();
				}
			} else {
				add_token(TokenType::SLASH);
			}
			break;

		case ' ':
		case '\r':
		case '\t':
			break;
		case '\n':
			line++;
			break;

		case '"':
			string();
			break;

		default: 
			if (isdigit(c)) {
				number();
			} else {
				Lang::error(line, "Unexpected character."); 
			}
			break;
	}
}

void Scanner::add_token(TokenType type, std::string literal) { 
	std::string txt = source.substr(start, current);
	tokens.push_back(Token(type, txt, literal, line));
}

bool Scanner::match(char expected) {
	if (is_at_end()) {
		return false;
	}

	if (source[current] != expected) {
		return false;
	}

	current++;
	return true;
}

char Scanner::peek(void) {
	if (is_at_end()) {
		return '\0';
	}
	return source[current];
}

// multi line strings are allowed with just "
void Scanner::string(void) {
	while (peek() != '"' && !is_at_end()) {
		if (peek() == '\n') {
			line++;
		}
		advance();
	}

	if (is_at_end()) {
		Lang::error(line, "Unterminated string.");
		return;
	}

	advance();
	std::string value = source.substr(start+1, current-1);
	add_token(TokenType::STRING, value);
}

void Scanner::number(void) {
	while (isdigit(peek())) {
		advance();
	}

	if (peek() == '.' && isdigit(peek_next())) {
		advance();
		while (isdigit(peek())) {
			advance();
		}
	}

	add_token(TokenType::NUMBER, std::stod(source.substr(start, current)));
}

char Scanner::peek_next(void) {
	if (current+1 >= source.size()) {
		return '\0';
	}
	return source[current+1];
}

std::ostream& operator<< (std::ostream& os, Token& t) { // const Token& t
	//return os << t.get_type() << " " << t.get_lexeme() << " " << t.get_literal();
	return os << t.get_type() << " " << t.get_lexeme();
}
