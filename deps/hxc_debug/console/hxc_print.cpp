/**
 * @file hxc_print
 * @brief
 * @date 26/03/2024
 * @developer bonsall2004
 * @link https://github.com/bonsall2004
 */

#include <hxc_print.h>
#include <hxc_timer.h>
#include <cstdarg>
#include <iostream>

void PrintError(const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << RED << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintErrorN(const char* name, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << RED << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintWarning(const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1 || VERBOSITY == 2
  va_list args;
  va_start(args, format);

  std::cout << YELLOW << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintWarningN(const char* name, const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1 || VERBOSITY == 2
  va_list args;
  va_start(args, format);

  std::cout << YELLOW << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintInfo(const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1
  va_list args;
  va_start(args, format);

  std::cout << CYAN << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintInfoN(const char* name, const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1
  va_list args;
  va_start(args, format);

  std::cout << CYAN << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintInfoC(const char* color, const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintInfoNC(const char* name, const char* color, const char* format, ...) {
  #if VERBOSITY == 0 || VERBOSITY == 1
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
  #endif
}

void PrintRequired(const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << CYAN << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintRequiredN(const char* name, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << CYAN << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintRequiredC(const char* color, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintUtil(const char* name, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << MAGENTA << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintUtilN(const char* name, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << MAGENTA << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintRequiredNC(const char* name, const char* color, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintUtilC(const char* color, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}

void PrintUtilNC(const char* name, const char* color, const char* format, ...) {
  va_list args;
  va_start(args, format);

  std::cout << color << "[" << get_time() << "]" << "[" << name << "] " << RESET;
  vfprintf(stdout, format, args);
  std::cout << RESET << std::endl;

  va_end(args);
}