#include "scanner.h"
#include <stdlib.h>
#include <string.h>

struct Token *token_construct(const enum TokenType type, char *lexeme, const size_t line) {
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
  while (!scanner_is_at_end(scanner)) {
    scanner->start = scanner->current;
    scanner_scan_token(scanner);
  }
  // scanner->tokens append new Token(EOF, "", null, line);
  return scanner->tokens;
}

void scanner_scan_token(struct Scanner *scanner) {
  char c = scanner_advance(scanner);
  switch (c) {
    case '(': scanner_add_token(scanner, LEFT_PAREN); break;
    case ')': scanner_add_token(scanner, RIGHT_PAREN); break;
    case '{': scanner_add_token(scanner, LEFT_BRACE); break;
    case '}': scanner_add_token(scanner, RIGHT_BRACE); break;
    case ',': scanner_add_token(scanner, COMMA); break;
    case '.': scanner_add_token(scanner, DOT); break;
    case '-': scanner_add_token(scanner, MINUS); break;
    case '+': scanner_add_token(scanner, PLUS); break;
    case ';': scanner_add_token(scanner, SEMICOLON); break;
    case '*': scanner_add_token(scanner, STAR); break; 
  }
}

char scanner_advance(struct Scanner *scanner) {
  return scanner->source[scanner->current++];
}

void scanner_add_token(struct Scanner *scanner, const enum TokenType type) {
  char *text = scanner_substring(scanner);
  struct Token *token = token_construct(type, text, scanner->line); // check NULL
  scanner_append_tokens(scanner, token);
}

//void scanner_add_token_literal(const enum TokenType type, const literal) {}

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

char *scanner_substring(struct Scanner *scanner) {
  // get sub string from start to current
}
