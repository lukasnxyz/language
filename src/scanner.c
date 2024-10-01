#include "scanner.h"
#include <stdlib.h>
#include <string.h>

struct Token *token_construct(enum TokenType type, char *lexeme, size_t line) {
  struct Token *token = (struct Token *)malloc(sizeof(struct Token));
  if (token == NULL) {
    fprintf(stderr, "error allocating memory!");
    return NULL;
  }

  token->type = type;
  token->lexeme = lexeme;
  token->line = line;

  return token;
}

// TODO: make this return all information
char *token_to_string(struct Token *token) {
  return token->lexeme;
}

struct Scanner *scanner_construct(char *source) {
  struct Scanner *scanner = (struct Scanner *)malloc(sizeof(struct Scanner));
  if (scanner == NULL) {
    fprintf(stderr, "error allocating memory!");
    return NULL;
  }

  scanner->source = source;
  scanner->tokens = NULL;

  scanner->start = 0;
  scanner->current = 0;
  scanner->line = 0;

  return scanner;
}

static int scanner_is_at_end(struct Scanner *scanner) {
  return scanner->current >= strlen(scanner->source);
}

struct Token *scanner_scan_tokens(struct Scanner *scanner) {
  while (!scanner_is_at_end) {
    scanner->start = scanner->current;
    scanner_scan_token(scanner);
  }
  // scanner->tokens append new Token(EOF, "", null, line);
  return scanner->tokens;
}
