
// Copyright 2026 NiyaDev


#ifndef INCLUDE_VECTORS_VEC2_HPP_
#define INCLUDE_VECTORS_VEC2_HPP_


#include <ostream>


struct Vec2f {
  float x;
  float y;

  // Constructors
  Vec2f();
  Vec2f(float x, float y);

  // Operators
  // Relational
  bool  operator==(const Vec2f& rhs) const;
  // Arithmetic self
  Vec2f operator+ (const Vec2f& rhs) const;
  Vec2f operator- (const Vec2f& rhs) const;
  Vec2f operator* (const Vec2f& rhs) const;
  Vec2f operator/ (const Vec2f& rhs) const;
  // Compound assignment self
  void  operator+=(const Vec2f& rhs);
  void  operator-=(const Vec2f& rhs);
  void  operator*=(const Vec2f& rhs);
  void  operator/=(const Vec2f& rhs);
  // Arithmetic float
  Vec2f operator+(float rhs) const;
  Vec2f operator-(float rhs) const;
  Vec2f operator*(float rhs) const;
  Vec2f operator/(float rhs) const;
  // Compound assignment float
  void  operator+=(float rhs);
  void  operator-=(float rhs);
  void  operator*=(float rhs);
  void  operator/=(float rhs);
  // To string
  friend std::ostream& operator<<(std::ostream& os, const Vec2f& rhs);

  // Functions
  float length();
  float dot(Vec2f v2);
  float distance(Vec2f v2);
  float angle_rad(Vec2f v2);
  float angle_deg(Vec2f v2);
  Vec2f normalize();
  Vec2f lerp(Vec2f v2, float amount);
  Vec2f reflect(Vec2f normal);
  Vec2f rotate_rad(float angle);
  Vec2f rotate_deg(float angle);
  Vec2f move_towards(Vec2f target, float max_distance);
  Vec2f invert();
  Vec2f clamp(Vec2f min, Vec2f max);
};


#endif  // INCLUDE_VECTORS_VEC2_HPP_
