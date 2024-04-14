/*
 * lumos-llvm
 * Author: bonsall2004
 * Description: 
 */
#include "Lexer.hpp"
#include <iostream>

std::vector<Token> Lexer::tokenize()
{
  while(peek() != '\0')
  {
    std::cout << consume();
  }
  return {};
}