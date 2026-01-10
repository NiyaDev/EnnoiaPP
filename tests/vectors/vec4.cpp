
// Copyright 2026 NiyaDev


#include <catch2/catch_test_macros.hpp>
#include "../../include/vectors/vec4.hpp"
//#include"../../src/vectors/vec4.cpp"


TEST_CASE("Vector4", "[VEC4]") {
  REQUIRE(sizeof(Vec4f) == 16);

  // Relational
  REQUIRE(Vec4f() == Vec4f(0, 0, 0, 0));
  REQUIRE(Vec4f(10, 10, 10, 10).v2 == Vec2f(10, 10));
  REQUIRE(Vec4f(10, 10, 10, 10).v3 == Vec3f(10, 10, 10));
}

