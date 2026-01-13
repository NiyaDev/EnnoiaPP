
// Copyright 2026 NiyaDev


#include <iostream>
#include <cmath>

#include "../../include/vectors/matrix.hpp"
#include "../../include/vectors/vec3.hpp"
#include "../../include/utils/array.hpp"


//Matrix::Matrix() {}
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
Matrix perspective(double fov, double aspect, double near, double far) {
  Matrix output;
  double top =  near * tan(fov * 0.5);
  double bot = -top;
  double right =  top * aspect;
  double left  = -right;

  float rl = right - left;
  float tb = top - bot;
  float fn = far - near;

  output.m[0] =  (near * 2) / rl;
  output.m[5] =  (near * 2) / tb;
  output.m[8] =  (right + left) / rl;
  output.m[9] =  (top + bot) / tb;
  output.m[10]= -(far + near) / fn;
  output.m[11]= -1;
  output.m[14]= -(far * near * 2) / fn;

  return output;
}

Matrix Matrix::translate(Vec3f v) {
  Matrix output = *this;
  output.m[12] += v.x;
  output.m[13] += v.y;
  output.m[14] += v.z;

  return output;
}
Matrix Matrix::rotate(Vec3f angle) {
  Matrix output = *this;
  float cosz = cos(angle.z * (M_PI / 180));
  float sinz = sin(angle.z * (M_PI / 180));
  float cosy = cos(angle.y * (M_PI / 180));
  float siny = sin(angle.y * (M_PI / 180));
  float cosx = cos(angle.x * (M_PI / 180));
  float sinx = sin(angle.x * (M_PI / 180));

  output.m[0] = cosz * cosy;
  output.m[1] = (cosz * siny * sinx) - (sinz * cosx);
  output.m[2] = (cosz * siny * cosx) + (sinz * sinx);

  output.m[4] = sinz * cosy;
  output.m[5] = (sinz * siny * sinx) - (cosz * cosx);
  output.m[6] = (sinz * siny * cosx) + (cosz * sinx);

  output.m[8] = -siny;
  output.m[9] = cosy * sinx;
  output.m[10]= cosy * cosx;

  return output;
}
Matrix Matrix::scale(Vec3f scale) {
  Matrix output = *this;
  output.m[0] = scale.x;
  output.m[5] = scale.y;
  output.m[10]= scale.z;

  return output;
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
    if (m[i] != rhs.m[i]) {printf("%.10f %.10f",m[i],rhs.m[i]);return false;}
  return true;
}
// To string
std::ostream& operator<<(std::ostream& os, const Matrix& rhs) {
  os << "{\n";
  for (int y = 0; y < 4; y++) {
    os << "  ";
    for (int x = 0; x < 4; x++) {
      os << rhs.m[(y*4)+x] << ",";
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
      std::cout << m[(y*4)+x] << ",";
    }
    std::cout << "\n";
  }

  std::cout << "}" << std::endl;
}

