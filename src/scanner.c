#include "scanner.h"
#include <stdlib.h>
#include <string.h>

struct Token *token_construct(const enum TokenType type, const char *lexeme, const size_t line) {
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

struct Scanner *scanner_construct(const char *source) {
  struct Scanner *scanner = (struct Scanner *)malloc(sizeof(struct Scanner));
  if (scanner == NULL) {
    fprintf(stderr, "error allocating memory!");
    return NULL;
  }

  scanner->source = source;

  scanner->start = 0;
  scanner->current = 0;
  scanner->line = 0;

  scanner->num_tokens = 0;
  scanner->tokens = NULL;

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

void scanner_scan_token(struct Scanner *scanner) {
  char c = advance();
  switch (c) {
    case '(': scanner_add_token(LEFT_PAREN); break;
    case ')': scanner_add_token(RIGHT_PAREN); break;
    case '{': scanner_add_token(LEFT_BRACE); break;
    case '}': scanner_add_token(RIGHT_BRACE); break;
    case ',': scanner_add_token(COMMA); break;
    case '.': scanner_add_token(DOT); break;
    case '-': scanner_add_token(MINUS); break;
    case '+': scanner_add_token(PLUS); break;
    case ';': scanner_add_token(SEMICOLON); break;
    case '*': scanner_add_token(STAR); break; 
  }
}

char scanner_advance(struct Scanner *scanner) {
  return scanner->source[scanner->current++];
}

void scanner_add_token(struct Scanner *scanner, const enum TokenType type) {
  // char *text = scanner
}

void scanner_append_tokens(struct Scanner *scanner, struct Token *token) {
  if (scanner->tokens == NULL) {
    scanner->tokens = (struct Token *)malloc(sizeof(struct Token) * 1);
    // check fail
  } else {
    scanner->tokens = (struct Token *)realloc(sizeof(struct Token) * (source->num_tokens+1));
    // check fail
  }
  if (scanner->tokens == NULL) {
    fprintf(stderr, "memory allocation failed!");
    // return 2;
  }
  scanner->num_tokens++;

  scanner->tokens[source->num_tokens] = token;
}
