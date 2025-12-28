

#include<catch2/catch_test_macros.hpp>
#include"../src/root.cpp"


TEST_CASE("Vector2", "[VEC2]") {
  REQUIRE(sizeof(Vec2f) == 8);

  REQUIRE(Vec2f() == Vec2f(0,0));
}

TEST_CASE("Vector3", "[VEC3]") {
  REQUIRE(sizeof(Vec3f) == 12);

  REQUIRE(Vec3f() == Vec3f(0,0,0));
}

TEST_CASE("Vector4", "[VEC4]") {
  REQUIRE(sizeof(Vec4f) == 16);

  REQUIRE(Vec4f() == Vec4f(0,0,0,0));
}

