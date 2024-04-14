/**
 * @file hxc_utils
 * @brief 
 * @date 26/03/2024
 * @developer bonsall2004
 * @link https://github.com/bonsall2004
 */

#include "includes/hxc_utils.h"
#include <cstdlib>
#include <hxc_print.h>

#if MEMORY_DBG || VERBOSITY == 0

void* operator new(size_t size) {
  void* ptr = malloc(size); // Allocate memory using malloc
  if(ptr == nullptr) {
    PrintError("Failed to Allocate", size);
  } else {
    PrintUtilN("Memory", "Allocated: %d", size);
  }
  return ptr;
}

void operator delete(void* ptr, size_t size) noexcept {
  free(ptr);
  PrintUtilN("Memory", "Freed: %d", size);
}

#endif
