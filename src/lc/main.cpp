#include <string>

/*
 * lumos-llvm
 * Author: bonsall2004
 * Description: 
 */
#include <Tokens.h>
#include <TaskScheduler.h>
#include <hxc_print.h>
#include <iostream>
#include "ExitCodes.h"
#include "Lexer/Lexer.hpp"

int main(int argc, char** argv)
{
  if(argc <= 1)
  {
    PrintErrorN("Error", "Please Specify a file!");
    PrintErrorN("Usage", "%s <filename.ls>", argv[0]);
    TaskScheduler::safe_exit(EXIT_INVALID_PARAMS);
  }
  auto* lexer1 = new Lexer(reinterpret_cast<std::string&>(argv[1]));
  std::vector<Token> lexed_tokens = lexer1->tokenize();
  TaskScheduler::safe_exit(EXIT_SUCCESS);
}