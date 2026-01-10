
// Copyright 2026 NiyaDev


#ifndef INCLUDE_VECTORS_VEC3_HPP_
#define INCLUDE_VECTORS_VEC3_HPP_


#include "../vectors/vec2.hpp"


struct Vec3f {
  union {
    Vec2f v2;
    struct {
      float x;
      float y;
    };
  };
  float z;

  // Constructors
  Vec3f();
  Vec3f(float x, float y, float z);

  // Operators
  // Relational
  bool  operator==(const Vec3f& rhs) const;
  // Arithmetic self
  Vec3f operator+ (const Vec3f& rhs) const;
  Vec3f operator- (const Vec3f& rhs) const;
  Vec3f operator* (const Vec3f& rhs) const;
  Vec3f operator/ (const Vec3f& rhs) const;
  // Compound assignment self
  void  operator+=(const Vec3f& rhs);
  void  operator-=(const Vec3f& rhs);
  void  operator*=(const Vec3f& rhs);
  void  operator/=(const Vec3f& rhs);
  // Arithmetic float
  Vec3f operator+(float rhs) const;
  Vec3f operator-(float rhs) const;
  Vec3f operator*(float rhs) const;
  Vec3f operator/(float rhs) const;
  // Compound assignment float
  void  operator+=(float rhs);
  void  operator-=(float rhs);
  void  operator*=(float rhs);
  void  operator/=(float rhs);
  // To string
  friend std::ostream& operator<<(std::ostream& os, const Vec3f& rhs);

  // Functions
  float length();
  float dot(Vec3f v3);
  float distance(Vec3f v3);
  float angle_rad(Vec3f v3);
  float angle_deg(Vec3f v3);
  Vec3f cross(Vec3f v3);
  Vec3f perpendicular();
  Vec3f normalize();
  Vec3f project(Vec3f v3);
  Vec3f reject(Vec3f v3);
  void  orthonormalize(Vec3f* v3);
  // Vec3f transform(Matrix mat);
  // Vec3f rotate_quaternion(Quaternion q);
  Vec3f rotate(Vec3f dist, float rot);
  Vec3f rotate_axis(Vec3f axis, float angle);
  Vec3f lerp(Vec3f v3, float amount);
  Vec3f reflect(Vec3f normal);
  Vec3f move_towards(Vec3f target, float max_distance);
  Vec3f invert();
  Vec3f clamp(Vec3f min, Vec3f max);
};


#endif  // INCLUDE_VECTORS_VEC3_HPP_

