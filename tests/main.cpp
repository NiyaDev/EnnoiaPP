
// Copyright 2026 NiyaDev


#include<catch2/catch_test_macros.hpp>
#include"../include/system/ennoia.hpp"



TEST_CASE("TEST", "[TEST]") {
  ennoia = new Ennoia("TEST");

  //Mesh mesh(MESH_CUBE);
  
  while (!ennoia->ShouldClose()) {
    //mesh.draw(Vec3f(0,0,0), Vec3f(0,90,0), Vec3f(1,1,1));

    ennoia->Draw();
  }
}


