/**
 * @file hxc_timer
 * @brief
 * @date 26/03/2024
 * @developer bonsall2004
 * @link https://github.com/bonsall2004
 */

#include "includes/hxc_timer.h"

std::_Put_time<char> get_time() {
  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::tm* local_time = std::localtime(&now_c);
  return std::put_time(local_time, "%H:%M:%S");
}

Timer::Timer(bool should_start) {
  if(!should_start) return;

  this->startTimer();
}

void Timer::startTimer() {
  startTime = std::chrono::high_resolution_clock::now();
}

double Timer::endTimer() {
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
  return duration.count(); // Return elapsed time in milliseconds as a double
}

template <typename T>
bool isValid(const T* ptr) {
  return (ptr != nullptr);
}