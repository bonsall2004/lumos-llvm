/*
 * lumos-compiler
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <string>

enum class LCTokens
{
  TOK_EOF = -1,

  // Keywords
  TOK_INT = -2, TOK_FLOAT = -3, TOK_BOOL = -4, TOK_CHAR = -5, TOK_IF = -6, TOK_ELSE = -7, TOK_FOR = -8, TOK_WHILE = -9, TOK_RETURN = -10, TOK_STRING = -52,

  // Identifiers
  TOK_IDENTIFIER = -11,

  // Literals
  TOK_INT_LITERAL = -12, TOK_FLOAT_LITERAL = -13, TOK_CHAR_LITERAL = -14, TOK_STRING_LITERAL = -15, TOK_BOOL_TRUE = -16, TOK_BOOL_FALSE = -17,

  // Operators
  TOK_PLUS = -18, TOK_MINUS = -19, TOK_MULTIPLY = -20, TOK_DIVIDE = -21, TOK_MODULO = -22, TOK_ASSIGN = -23, TOK_EQUALS = -24, TOK_NOT_EQUALS = -25, TOK_LESS_THAN = -26, TOK_LESS_THAN_OR_EQUAL = -27, TOK_GREATER_THAN = -28, TOK_GREATER_THAN_OR_EQUAL = -29, TOK_LOGICAL_AND = -30, TOK_LOGICAL_OR = -31, TOK_LOGICAL_NOT = -32, TOK_INCREMENT = -33, TOK_DECREMENT = -34,

  // Punctuation
  TOK_SEMICOLON = -35, TOK_COMMA = -36, TOK_COLON = -37, TOK_PERIOD = -38, TOK_OPEN_PAREN = -39, TOK_CLOSE_PAREN = -40, TOK_OPEN_BRACE = -41, TOK_CLOSE_BRACE = -42, TOK_OPEN_BRACKET = -43, TOK_CLOSE_BRACKET = -44, // Comments

  // Preprocessor Directives
  TOK_INCLUDE = -47, TOK_DEFINE = -48, TOK_IFDEF = -49, TOK_IFNDEF = -50, TOK_ENDIF = -51,
};

typedef struct TOKEN_
{
  LCTokens token;
  std::string value;
  uint32_t line_number;
} Token;