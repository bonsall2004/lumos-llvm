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
      case str2int("mutable"):
        tokens.push_back({ LCTokens::TOK_MUTABLE, buff, line_num });
        buff.clear();
        break;
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
    else if(isdigit(peek()))
    {
      LCTokens token = LCTokens::TOK_INT_LITERAL;
      while(isdigit(peek()))
      {
        buff += consume();
        if(peek() == '.')
        {
          buff += consume();
          token = LCTokens::TOK_FLOAT_LITERAL;
        }
      }

      tokens.push_back({ token, buff, line_num });
      buff.clear();

    }
    else if(isspace(peek()))
    {
      consume();
    }
    else
    {
      switch(peek())
      {
      case '+':
        tokens.push_back({ LCTokens::TOK_PLUS, "+", line_num });
        consume();
        break;
      case '-':
        tokens.push_back({ LCTokens::TOK_MINUS, "-", line_num });
        consume();
        break;
      case '*':
        tokens.push_back({ LCTokens::TOK_MULTIPLY, "*", line_num });
        consume();
        break;
      case ';':
        tokens.push_back({ LCTokens::TOK_SEMICOLON, ";", line_num });
        consume();
        break;
      case '(':
        tokens.push_back({ LCTokens::TOK_OPEN_PAREN, "(", line_num });
        consume();
        break;
      case ')':
        tokens.push_back({ LCTokens::TOK_CLOSE_PAREN, ")", line_num });
        consume();
        break;
      case '{':
        tokens.push_back({ LCTokens::TOK_OPEN_BRACE, "{", line_num });
        consume();
        break;
      case '}':
        tokens.push_back({ LCTokens::TOK_CLOSE_BRACE, "}", line_num });
        consume();
        break;
      case '=':
        if(peek(1) == '=')
        {
          tokens.push_back({ LCTokens::TOK_EQUALS, "==", line_num });
          consume();
          consume();
        }
        else
        {
          tokens.push_back({ LCTokens::TOK_ASSIGN, "=", line_num });
          consume();
        }
        break;
      case '<':
        if(peek(1) == '=')
        {
          tokens.push_back({ LCTokens::TOK_LESS_THAN_OR_EQUAL, "<=", line_num });
          consume();
          consume();
        }
        else
        {
          tokens.push_back({ LCTokens::TOK_LESS_THAN, "<", line_num });
          consume();
        }
        break;
      case '>':
        if(peek(1) == '=')
        {
          tokens.push_back({ LCTokens::TOK_GREATER_THAN_OR_EQUAL, ">=", line_num });
          consume();
          consume();
        }
        else
        {
          tokens.push_back({ LCTokens::TOK_GREATER_THAN, ">", line_num });
          consume();
        }
        break;
      case '!':
        if(peek(1) == '=')
        {
          tokens.push_back({ LCTokens::TOK_NOT_EQUALS, "!=", line_num });
          consume();
          consume();
        }
        else
        {
          tokens.push_back({ LCTokens::TOK_LOGICAL_NOT, "!", line_num });
          consume();
        }
        break;
      case '&':
        if(peek(1) == '&')
        {
          tokens.push_back({ LCTokens::TOK_LOGICAL_AND, "&&", line_num });
          consume();
          consume();
        }
        break;
      case '|':
        if(peek(1) == '|')
        {
          tokens.push_back({ LCTokens::TOK_LOGICAL_OR, "||", line_num });
          consume();
          consume();
        }
        break;
      case '/':
        if(peek(1) == '/')
        {
          while(peek() != '\n')
          {
            consume();
          }
        }
        else
        {
          tokens.push_back({ LCTokens::TOK_DIVIDE, "/", line_num });
          consume();
        }
        break;
      case '"':
        consume();
        while(peek() != '"')
        {
          buff += consume();
        }
        consume();
        tokens.push_back({ LCTokens::TOK_STRING_LITERAL, buff, line_num });
        buff.clear();
        break;
      case '\'':
        consume();
        buff += consume();
        consume();
        tokens.push_back({ LCTokens::TOK_CHAR_LITERAL, buff, line_num });
        buff.clear();
        break;
      case '%':
        tokens.push_back({ LCTokens::TOK_MODULO, "%", line_num });
        consume();
        break;
      case '[':
        tokens.push_back({ LCTokens::TOK_OPEN_BRACKET, "[", line_num });
        consume();
        break;
      case ']':
        tokens.push_back({ LCTokens::TOK_CLOSE_BRACKET, "]", line_num });
        consume();
        break;
      case ',':
        tokens.push_back({ LCTokens::TOK_COMMA, ",", line_num });
        consume();
        break;
      case ':':
        tokens.push_back({ LCTokens::TOK_COLON, ":", line_num });
        consume();
        break;
      case '.':
        tokens.push_back({ LCTokens::TOK_PERIOD, ".", line_num });
        consume();
        break;
      case '\n':
        line_num++;
        consume();
        break;
      default:
        consume();
        break;
      }
    }

  }
  tokens.push_back({ LCTokens::TOK_EOF, "EOF", line_num });
  return tokens;
}