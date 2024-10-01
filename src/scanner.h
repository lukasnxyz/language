#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <stdio.h>

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

struct Token {
  enum TokenType type;
  char *lexeme;
  // literal can be a string or double
  size_t line;
};

struct Token *token_construct(const enum TokenType type, const char *lexeme, const size_t line);
char *token_to_string(struct Token *token);

struct Scanner {
  char *source;

  size_t start; 
  size_t current; 
  size_t line; 

  size_t num_tokens;
  struct Token *tokens; // array
};

struct Scanner *scanner_construct(const char *source);
//int scanner_is_at_end(struct Scanner *scanner);
struct Token *scanner_scan_tokens(struct Scanner *scanner);
void scanner_scan_token(struct Scanner *scanner);
char scanner_advance(struct Scanner *scanner);
void scanner_add_token(struct Scanner *scanner, const enum TokenType type);
//void scanner_add_token_literal(const enum TokenType type, const literal);
void scanner_append_tokens(struct Scanner *scanner, struct Token *token);

#endif /* _SCANNER_H_ */
