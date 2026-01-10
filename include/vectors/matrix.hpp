
// Copyright 2026 NiyaDev


#ifndef INCLUDE_UTILS_MATRIX_HPP_
#define INCLUDE_UTILS_MATRIX_HPP_


#include "../vectors/vec3.hpp"
#include "../utils/array.hpp"


struct Matrix {
  float m[16];

  Matrix();
  Matrix(Array<float> arr);

  bool operator==(const Matrix& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Matrix& rhs);

  Matrix transpose();
  void print();
};

Matrix lookAt(Vec3f eye, Vec3f target, Vec3f up);


#endif  // INCLUDE_UTILS_MATRIX_HPP_

