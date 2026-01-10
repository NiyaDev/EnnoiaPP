
// Copyright 2026 NiyaDev


#include <catch2/catch_test_macros.hpp>
#include "../../include/vectors/vec2.hpp"
//#include"../../src/vectors/vec2.cpp"


TEST_CASE("Vector2", "[VEC2]") {
  REQUIRE(sizeof(Vec2f) == 8);

  // Relational
  REQUIRE(Vec2f() == Vec2f(0, 0));

  // Arithmetic self
  REQUIRE(Vec2f(1, 1) + Vec2f(1, 1) == Vec2f(2, 2));
  REQUIRE(Vec2f(1, 1) - Vec2f(1, 1) == Vec2f(0, 0));
  REQUIRE(Vec2f(1, 1) * Vec2f(2, 2) == Vec2f(2, 2));
  REQUIRE(Vec2f(1, 1) / Vec2f(2, 2) == Vec2f(0.5, 0.5));

  // Compound assignment self
  Vec2f addition = Vec2f(10, 10);
  Vec2f subtraction = Vec2f(10, 10);
  Vec2f multipication = Vec2f(10, 10);
  Vec2f division = Vec2f(10, 10);

  addition += Vec2f(10, 10);
  subtraction -= Vec2f(10, 10);
  multipication *= Vec2f(10, 10);
  division /= Vec2f(10, 10);

  REQUIRE(addition == Vec2f(20, 20));
  REQUIRE(subtraction == Vec2f(0, 0));
  REQUIRE(multipication == Vec2f(100, 100));
  REQUIRE(division == Vec2f(1, 1));

  // Arithmetic float
  REQUIRE(Vec2f(1, 1) + 1 == Vec2f(2, 2));
  REQUIRE(Vec2f(1, 1) - 1 == Vec2f(0, 0));
  REQUIRE(Vec2f(1, 1) * 2 == Vec2f(2, 2));
  REQUIRE(Vec2f(1, 1) / 2 == Vec2f(0.5, 0.5));

  // Compound assignment float
  addition = Vec2f(10, 10);
  subtraction = Vec2f(10, 10);
  multipication = Vec2f(10, 10);
  division = Vec2f(10, 10);

  addition += 10;
  subtraction -= 10;
  multipication *= 10;
  division /= 10;

  REQUIRE(addition == Vec2f(20, 20));
  REQUIRE(subtraction == Vec2f(0, 0));
  REQUIRE(multipication == Vec2f(100, 100));
  REQUIRE(division == Vec2f(1, 1));

  // Functions
  REQUIRE(Vec2f(10, 10).length() == 14.14213562f);
  REQUIRE(Vec2f(10, 10).dot(Vec2f(10, 10)) == 200);
  REQUIRE(Vec2f(10, 10).distance(Vec2f(0, 0)) == 14.14213562f);
  REQUIRE(Vec2f(0, 0).angle_rad(Vec2f(10, 10)) == 0.7853982f);
  REQUIRE(Vec2f(0, 0).angle_deg(Vec2f(10, 10)) == 45);
  REQUIRE(Vec2f(10, 10).normalize() == Vec2f(0.70710682f, 0.70710682f));
  // REQUIRE(Vec2f(10, 10).transform(Matrix<4,4>()) == Vec2f(11, 11));
  REQUIRE(Vec2f(10, 10).lerp(Vec2f(20, 20), 0.5f) == Vec2f(15, 15));
  REQUIRE(Vec2f(10, 10).reflect(Vec2f(0, 1)) == Vec2f(10, -10));
  REQUIRE(Vec2f(10, 10).rotate_rad(0.7853982) == Vec2f(0, 14.14213562));
  REQUIRE(Vec2f(10, 10).rotate_deg(45) == Vec2f(0, 14.14213562));
  REQUIRE(Vec2f(10, 10).move_towards(Vec2f(20, 20), 5)
      == Vec2f(13.535534, 13.535534));
  REQUIRE(Vec2f(10, 10).invert() == Vec2f(0.1, 0.1));
  REQUIRE(Vec2f(-10, 10).clamp(Vec2f(0, 0), Vec2f(5, 5)) == Vec2f(0, 5));
}

