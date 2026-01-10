
// Copyright 2026 NiyaDev


#ifndef INCLUDE_VECTORS_VEC4_HPP_
#define INCLUDE_VECTORS_VEC4_HPP_


#include "../vectors/vec2.hpp"
#include "../vectors/vec3.hpp"


struct Vec4f {
  union {
    Vec2f v2;
    Vec3f v3;
    struct {
      float x;
      float y;
      float z;
    };
  };
  float w;

  // Constructors
  Vec4f();
  Vec4f(float x, float y, float z, float w);

  // Operators
  bool operator==(const Vec4f& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Vec4f& rhs);
};

#endif  // INCLUDE_VECTORS_VEC4_HPP_

