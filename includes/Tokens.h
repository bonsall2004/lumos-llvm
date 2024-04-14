/*
 * lumos-compiler
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <string>

enum class LCTokens
{
  TOK_EOF = -1, TOK_CONST = -2, TOK_

};

typedef struct TOKEN_
{
  LCTokens token;
  std::string value;
  uint32_t line_number;
} Token;