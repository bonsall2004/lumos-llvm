/*
 * lumos-llvm
 * Author: bonsall2004
 * Description: 
 */
#include "Lexer.hpp"
#include <iostream>

constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::vector<Token> Lexer::tokenize()
{
  std::vector<Token> tokens;
  uint32_t line_num = 1;
  std::string buff;
  while(peek() != '\0')
  {
    if(isalpha(peek()))
    {
      while(isalnum(peek()))
      {
        buff += consume();
      }

      switch(str2int(buff.c_str()))
      {
      case str2int("int"):
        tokens.push_back({ LCTokens::TOK_INT, buff, line_num });
        buff.clear();
        break;
      case str2int("float"):
        tokens.push_back({ LCTokens::TOK_FLOAT, buff, line_num });
        buff.clear();
        break;
      case str2int("char"):
        tokens.push_back({ LCTokens::TOK_CHAR, buff, line_num });
        buff.clear();
        break;
      case str2int("bool"):
        tokens.push_back({ LCTokens::TOK_BOOL, buff, line_num });
        buff.clear();
        break;
      case str2int("string"):
        tokens.push_back({ LCTokens::TOK_STRING, buff, line_num });
        buff.clear();
        break;
      case str2int("if"):
        tokens.push_back({ LCTokens::TOK_IF, buff, line_num });
        buff.clear();
        break;
      case str2int("else"):
        tokens.push_back({ LCTokens::TOK_ELSE, buff, line_num });
        buff.clear();
        break;
      case str2int("while"):
        tokens.push_back({ LCTokens::TOK_WHILE, buff, line_num });
        buff.clear();
        break;
      case str2int("for"):
        tokens.push_back({ LCTokens::TOK_FOR, buff, line_num });
        buff.clear();
        break;
      case str2int("return"):
        tokens.push_back({ LCTokens::TOK_RETURN, buff, line_num });
        buff.clear();
        break;
      case str2int("true"):
        tokens.push_back({ LCTokens::TOK_BOOL_TRUE, buff, line_num });
        buff.clear();
        break;
      case str2int("false"):
        tokens.push_back({ LCTokens::TOK_BOOL_FALSE, buff, line_num });
        buff.clear();
        break;
      default:
        tokens.push_back({ LCTokens::TOK_IDENTIFIER, buff, line_num });
        buff.clear();
        break;
      }
    }
    else if(peek() == '\n')
    {
      line_num++;
      consume();
    }
    else if(isspace(peek()))
    {
      consume();
    }

  }
  return tokens;
}