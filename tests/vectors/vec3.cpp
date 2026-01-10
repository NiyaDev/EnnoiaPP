
// Copyright 2026 NiyaDev


#include <catch2/catch_test_macros.hpp>
#include "../../include/vectors/vec3.hpp"
//#include"../../src/vectors/vec3.cpp"


TEST_CASE("Vector3", "[VEC3]") {
  REQUIRE(sizeof(Vec3f) == 12);

  // Relational
  REQUIRE(Vec3f() == Vec3f(0, 0, 0));
  REQUIRE(Vec3f(10, 10, 10).v2 == Vec2f(10, 10));

  // Arithmetic self
  REQUIRE(Vec3f(1, 1, 1) + Vec3f(1, 1, 1) == Vec3f(2, 2, 2));
  REQUIRE(Vec3f(1, 1, 1) - Vec3f(1, 1, 1) == Vec3f(0, 0, 0));
  REQUIRE(Vec3f(1, 1, 1) * Vec3f(2, 2, 2) == Vec3f(2, 2, 2));
  REQUIRE(Vec3f(1, 1, 1) / Vec3f(2, 2, 2) == Vec3f(0.5, 0.5, 0.5));

  // Compound assignment self
  Vec3f addition = Vec3f(10, 10, 10);
  Vec3f subtraction = Vec3f(10, 10, 10);
  Vec3f multipication = Vec3f(10, 10, 10);
  Vec3f division = Vec3f(10, 10, 10);

  addition += Vec3f(10, 10, 10);
  subtraction -= Vec3f(10, 10, 10);
  multipication *= Vec3f(10, 10, 10);
  division /= Vec3f(10, 10, 10);

  REQUIRE(addition == Vec3f(20, 20, 20));
  REQUIRE(subtraction == Vec3f(0, 0, 0));
  REQUIRE(multipication == Vec3f(100, 100, 100));
  REQUIRE(division == Vec3f(1, 1, 1));

  // Arithmetic float
  REQUIRE(Vec3f(1, 1, 1) + 1 == Vec3f(2, 2, 2));
  REQUIRE(Vec3f(1, 1, 1) - 1 == Vec3f(0, 0, 0));
  REQUIRE(Vec3f(1, 1, 1) * 2 == Vec3f(2, 2, 2));
  REQUIRE(Vec3f(1, 1, 1) / 2 == Vec3f(0.5, 0.5, 0.5));

  // Compound assignment float
  addition = Vec3f(10, 10, 10);
  subtraction = Vec3f(10, 10, 10);
  multipication = Vec3f(10, 10, 10);
  division = Vec3f(10, 10, 10);

  addition += 10;
  subtraction -= 10;
  multipication *= 10;
  division /= 10;

  REQUIRE(addition == Vec3f(20, 20, 20));
  REQUIRE(subtraction == Vec3f(0, 0, 0));
  REQUIRE(multipication == Vec3f(100, 100, 100));
  REQUIRE(division == Vec3f(1, 1, 1));

  // Functions
  REQUIRE(Vec3f(10, 10, 10).length() == 17.3205080757f);
  REQUIRE(Vec3f(10, 10, 10).dot(Vec3f(10, 10, 10)) == 300);
  REQUIRE(Vec3f(10, 10, 10).distance(Vec3f(0, 0, 0)) == 17.3205080757f);
  REQUIRE(Vec3f(10, 10, 10).cross(Vec3f(10, 10, 10)) == Vec3f(0, 0, 0));
  REQUIRE(Vec3f(1, 1, 1).angle_rad(Vec3f(10, 10, 10)) == 1.570796371f);
  REQUIRE(Vec3f(1, 1, 1).angle_deg(Vec3f(10, 10, 10)) == 90);
  REQUIRE(Vec3f(10, 10, 10).perpendicular() == Vec3f(0, 10, -10));
  REQUIRE(Vec3f(10, 10, 10).normalize()
      == Vec3f(0.5773502f, 0.5773502f, 0.5773502f));
  REQUIRE(Vec3f(10, 10, 10).project(Vec3f(5, 5, 5))
      == Vec3f(9.999999, 9.999999, 9.999999));
  // REQUIRE(Vec3f(10, 10, 10).reject(Vec3f(5, 5, 5))
  //    == Vec3f(0.70710682f, 0.70710682f, 10));
  // REQUIRE(Vec3f(10, 10, 10).transform() == Vec3f());
  // REQUIRE(Vec3f(10, 10, 10).rotate_quaternion() == Vec3f());
  REQUIRE(Vec3f(10, 10, 10).rotate(Vec3f(0, 10, 10), 90) == Vec3f(0, 20, 10));
  // REQUIRE(Vec3f( 0, 0, 10).rotate_axis(Vec3f(0, 1, 0), 3.141593)
  //    == Vec3f(-40, 0, 0));
  REQUIRE(Vec3f(10, 10, 10).lerp(Vec3f(20, 20, 20), 0.5) == Vec3f(15, 15, 15));
  REQUIRE(Vec3f(10, 10, 10).reflect(Vec3f(0, 1, 0)) == Vec3f(10, -10, 10));
  REQUIRE(Vec3f(10, 10, 10).move_towards(Vec3f(20, 20, 20), 5)
      == Vec3f(12.886751f, 12.886751f, 12.886751f));
  REQUIRE(Vec3f(10, 10, 10).invert() == Vec3f(0.1, 0.1, 0.1));
  REQUIRE(Vec3f(10, 10, 10).clamp(Vec3f(5, -5, 5), Vec3f(7, -2, 10))
      == Vec3f(7, -2, 10));

  // orthonormalize
}

