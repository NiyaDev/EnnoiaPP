
// Copyright 2026 NiyaDev


#include <cmath>
#include <catch2/catch_test_macros.hpp>
#include "../../include/vectors/matrix.hpp"
//#include"../../src/vectors/matrix.cpp"


TEST_CASE("Matrix", "[Matrix]") {
  Matrix mat1;
  Matrix mat2({1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1});
  Matrix mat3 = Matrix().translate(Vec3f(2,10,0));

  REQUIRE(mat1 == mat2);

  REQUIRE(mat3.translate(Vec3f(2,-2,1)) == Matrix({1,0,0,0, 0,1,0,0, 0,0,1,0, 4,8,1,1}));
  //REQUIRE(mat3.rotate());
  REQUIRE(mat3.scale({1.5,1.5,1.5}) == Matrix({1.5,0,0,0, 0,1.5,0,0, 0,0,1.5,0, 2,10,0,1}));
  REQUIRE(perspective(70 * (M_PI / 180), 1.77, 0.1, 100) ==
    Matrix({
      0.80686324, 0,              0,            0,
      0,          1.42814800674,  0,            0,
      0,          0,             -1.002002002, -1,
      0,          0,             -0.2002002002, 1,
    }));
  /*
  REQUIRE();
  REQUIRE();
  REQUIRE();
  REQUIRE();
  */

  // mat4x4.print();

  // Matrix mat(Array<float>({1}));

  // REQUIRE(mat1x1 == mat);
}

