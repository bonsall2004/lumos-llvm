/*
 * lumos-llvm
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <Tokens.h>
#include <fstream>
#include <mutex>
#include <atomic>
#include <vector>

class Lexer
{
  public:
    explicit Lexer(std::string& file_name);
    ~Lexer();

    std::vector<Token> tokenize();

    char peek(size_t count = 0);

    char consume();

  protected:
    std::mutex char_index_mutex;
    size_t char_index = 0;

    std::mutex file_contents_mutex;
    std::string file_contents;

    std::mutex file_stream_mutex;
    std::ifstream file_stream;
};
