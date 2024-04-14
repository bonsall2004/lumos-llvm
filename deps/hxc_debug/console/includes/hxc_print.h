/**
 * @file hxc_print
 * @brief
 * @date 26/03/2024
 * @developer bonsall2004
 * @link https://github.com/bonsall2004
 */

#pragma once

#include "../../hxc_debug_config.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void PrintError(const char* format, ...);

void PrintErrorN(const char* name, const char* format, ...);

void PrintWarning(const char* format, ...);

void PrintWarningN(const char* name, const char* format, ...);

void PrintInfo(const char* format, ...);

void PrintInfoN(const char* name, const char* format, ...);

void PrintInfoC(const char* color, const char* format, ...);

void PrintInfoNC(const char* name, const char* color, const char* format, ...);

void PrintRequired(const char* format, ...);

void PrintRequiredN(const char* name, const char* format, ...);

void PrintRequiredC(const char* color, const char* format, ...);

void PrintRequiredNC(const char* name, const char* color, const char* format, ...);

void PrintUtil(const char* format, ...);

void PrintUtilN(const char* name, const char* format, ...);

void PrintUtilC(const char* color, const char* format, ...);

void PrintUtilNC(const char* name, const char* color, const char* format, ...);