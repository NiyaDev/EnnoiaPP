
// Copyright 2026 NiyaDev


#ifndef INCLUDE_UTILS_MATRIX_HPP_
#define INCLUDE_UTILS_MATRIX_HPP_


#include "../vectors/vec3.hpp"
#include "../utils/array.hpp"


struct Matrix {
  float m[16];

  Matrix() : m{1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1} {}
  Matrix(Array<float> arr);

  bool operator==(const Matrix& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Matrix& rhs);

  Matrix translate(Vec3f v);
  Matrix rotate(Vec3f angle);
  Matrix scale(Vec3f scale);
  Matrix transpose();
  void print();
};

Matrix lookAt(Vec3f eye, Vec3f target, Vec3f up);
Matrix perspective(double fov, double aspect, double near, double far);


#endif  // INCLUDE_UTILS_MATRIX_HPP_

