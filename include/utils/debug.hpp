
// Copyright 2026 NiyaDev


#ifndef INCLUDE_UTILS_DEBUG_HPP_
#define INCLUDE_UTILS_DEBUG_HPP_


#include <iostream>
#include "../types.h"


namespace debug {

#include <iostream>

template<typename T>
void FATAL(String x, T y) {
  std::cout << "[FATAL] - "
    << x << " [" << y << "]"
    << std::endl;
  exit(1);
}
template<typename T>
void ERROR(String x, T y) {
  std::cout << "[ERROR] - "
    << x << " [" << y << "]"
    << std::endl;
}
template<typename T>
void WARNING(String x, T y) {
  std::cout << "[WARNING] - "
    << x << " [" << y << "]"
    << std::endl;
}

}  // namespace debug

#endif  // INCLUDE_UTILS_DEBUG_HPP_

