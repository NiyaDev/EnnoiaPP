
// Copyright 2026 NiyaDev


#include<catch2/catch_test_macros.hpp>
#include"../include/system/ennoia.hpp"



TEST_CASE("TEST", "[TEST]") {
  ennoia = new Ennoia("TEST");

  Mesh mesh(MESH_TRI);
  mesh.shader = ennoia->default_shader_3d;
  Vec3f position(0,0,0);
  
  while (!ennoia->shouldClose()) {
    if ()

    glViewport(0, 0, ennoia->renderWidth, ennoia->renderHeight);
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mesh.draw(position, Vec3f(1,1,1), Vec3f(0,90,0));

    ennoia->draw();
  }
}


