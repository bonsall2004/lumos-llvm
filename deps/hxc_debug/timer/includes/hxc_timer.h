/**
 * @file hxc_timer
 * @brief
 * @date 26/03/2024
 * @developer bonsall2004
 * @link https://github.com/bonsall2004
 */

#pragma once

#include <chrono>
#include <iomanip>

class Timer {
private:
  std::chrono::high_resolution_clock::time_point startTime;

public:
  Timer(bool should_start = true);

  void startTimer();

  double endTimer();
};

std::_Put_time<char> get_time();