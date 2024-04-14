/*
 * lumos-llvm
 * Author: bonsall2004
 * Description: 
 */
#include <sstream>
#include "Lexer.hpp"
#include "Task.h"
#include "hxc_print.h"
#include <ExitCodes.h>
#include <iostream>

Lexer::~Lexer() = default;

Lexer::Lexer(std::string& file_name)
{
  std::lock(this->char_index_mutex, this->file_contents_mutex, this->file_stream_mutex);

  std::lock_guard<std::mutex> fileLock(this->file_contents_mutex, std::adopt_lock);
  std::lock_guard<std::mutex> indexLock(this->char_index_mutex, std::adopt_lock);
  std::lock_guard<std::mutex> streamLock(this->file_stream_mutex, std::adopt_lock);

  this->file_stream.open(file_name);

  if(!this->file_stream.is_open())
  {
    PrintErrorN("Lexer", "%s cannot be found", file_name.c_str());
    TaskScheduler::safe_exit(EXIT_INVALID_PARAMS);
  }
  std::stringstream buffer;
  buffer << this->file_stream.rdbuf();
  this->file_contents = buffer.str();
}

char Lexer::peek(size_t count)
{
  std::lock(this->file_contents_mutex, this->char_index_mutex);

  std::lock_guard<std::mutex> fileLock(this->file_contents_mutex, std::adopt_lock);
  std::lock_guard<std::mutex> indexLock(this->char_index_mutex, std::adopt_lock);

  if(this->char_index + count > this->file_contents.length())
  {
    return '\0';
  }

  return this->file_contents[this->char_index + count];
}

char Lexer::consume()
{
  std::lock(this->file_contents_mutex, this->char_index_mutex);

  std::lock_guard<std::mutex> fileLock(this->file_contents_mutex, std::adopt_lock);
  std::lock_guard<std::mutex> indexLock(this->char_index_mutex, std::adopt_lock);

  if(this->char_index + 1 > this->file_contents.length())
  {
    return '\0';
  }

  return this->file_contents[this->char_index++];
}

