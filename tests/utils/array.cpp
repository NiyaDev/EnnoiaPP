
// Copyright 2026 NiyaDev


#include <catch2/catch_test_macros.hpp>
#include "../../include/utils/array.hpp"
#include "../../include/vectors/vec3.hpp"
#include "../../include/utils/debug.hpp"


TEST_CASE("Array", "[ARRAY]") {
  Array<Vec3f> arr1(5);
  arr1[0] = {1, 2, 3};
  arr1[1] = {4, 5, 6};
  REQUIRE(arr1.len == 5);
  REQUIRE(arr1[0] == Vec3f(1, 2, 3));
  REQUIRE(arr1[1] == Vec3f(4, 5, 6));
  REQUIRE(arr1[2] == Vec3f(0, 0, 0));

  Array<int> arr2(10);
  REQUIRE(arr2.len == 10);
  int count = 0;
  for (int i = 0; i < arr2.len; i++) {
    REQUIRE(arr2[i] == 0);
    count++;
  }

  REQUIRE(count == 10);
  count = 0;
  arr2.Expand(20);
  for (int i = 0; i < arr2.len; i++) {
    REQUIRE(arr2[i] == 0);
    count++;
  }
  REQUIRE(count == 20);

  count = 0;
  arr2.Expand(5);
  for (int i = 0; i < arr2.len; i++) {
    REQUIRE(arr2[i] == 0);
    count++;
  }
  REQUIRE(count == 5);

  // Reading array like a standard one
  REQUIRE(((float*)arr1.buffer)[0] == 1);
  REQUIRE(((float*)arr1.buffer)[1] == 2);
  REQUIRE(((float*)arr1.buffer)[2] == 3);
  REQUIRE(((float*)arr1.buffer)[3] == 4);
  REQUIRE(((float*)arr1.buffer)[4] == 5);
  REQUIRE(((float*)arr1.buffer)[5] == 6);
}

