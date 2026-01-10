
// Copyright 2026 NiyaDev


#include "../../include/utils/floats.hpp"


bool areAlmostEqual(float x, float y, float epsilon) {
  if (fabs(x - y) < epsilon)
    return true;
  return false;
}

float clamp(float value, float lo, float hi) {
  if (value < lo)
    return lo;
  if (value > hi)
    return hi;
  return value;
}

