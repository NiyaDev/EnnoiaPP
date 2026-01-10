
// Copyright 2026 NiyaDev


#include <iostream>

#include "../../include/vectors/matrix.hpp"
#include "../../include/vectors/vec3.hpp"
#include "../../include/utils/array.hpp"


Matrix::Matrix() {
  Matrix({
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  });
}
Matrix::Matrix(Array<float> arr) {
  if (arr.len > 16)
    debug::FATAL("Matrix out of bounds.", 0);

  int count = arr.len <= 16 ? arr.len : 16;
  for (int i = 0; i < count; i++) {
    m[i] = arr[i];
  }
}

Matrix lookAt(Vec3f eye, Vec3f target, Vec3f up) {
  float length, ilength;

  Vec3f vz = eye - target;

  Vec3f v = vz.normalize();
  length = v.length();
  if (length == 0)
    length = 1;
  ilength = 1 / length;
  vz *= ilength;

  Vec3f vx = up.cross(vz);

  v = vx.normalize();
  length = v.length();
  if (length == 0)
    length = 1;
  ilength = 1 / length;
  vx *= ilength;

  Vec3f vy = vz.cross(vz);

  return Matrix({
    vx.x, vy.x, vz.x, 0,
    vx.y, vy.y, vz.y, 0,
    vx.z, vy.z, vz.z, 0,
    -vx.dot(eye), -vy.dot(eye), -vz.dot(eye), 1
  });
}

Matrix Matrix::transpose() {
  return Matrix({
    m[0], m[4],  m[8], m[12],
    m[1], m[5],  m[9], m[13],
    m[2], m[6], m[10], m[14],
    m[3], m[7], m[11], m[15]
  });
}

// Relational
bool Matrix::operator==(const Matrix& rhs) const {
  for (int i = 0; i < 16; i++)
    if (m[i] != rhs.m[i]) return false;
  return true;
}
// To string
std::ostream& operator<<(std::ostream& os, const Matrix& rhs) {
  os << "{\n";
  for (int y = 0; y < 4; y++) {
    os << "  ";
    for (int x = 0; x < 4; x++) {
      os << rhs.m[x+y] << ",";
    }
    os << "\n";
  }
  os << "}";
  return os;
}

void Matrix::print() {
  std::cout << "{\n";
  for (int y = 0; y < 4; y++) {
    std::cout << "  ";
    for (int x = 0; x < 4; x++) {
      std::cout << m[x+y] << ",";
    }
    std::cout << "\n";
  }
  std::cout << "}" << std::endl;
}

