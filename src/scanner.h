#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "utils.h"

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

/*
union O_Literal {
  char *o;
  double *o;
};*/

struct Token {
  enum TokenType type;
  char *lexeme;
  // literal can be a string or double
  size_t line;
};

struct Token *token_construct(enum TokenType type, char *lexeme, size_t line);
char *token_to_string(struct Token *token);

struct Scanner {
  char *source;

  size_t start; // 0
  size_t current; // 0
  size_t line; // 1
  
  struct Token *tokens; // array
};

struct Scanner *scanner_construct(char *source);
//int scanner_is_at_end(struct Scanner *scanner);
struct Token *scanner_scan_tokens(struct Scanner *scanner);

#endif /* _SCANNER_H_ */
