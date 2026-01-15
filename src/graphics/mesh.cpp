
// Copyright 2026 NiyaDev


#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include "../../include/graphics/texture.hpp"
#include "../../include/graphics/mesh.hpp"
#include "../../include/system/camera.hpp"


Vertex BASIC_TRI[] = {
  {{ 0.0,  0.5, 0.0}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5, 0.0}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{-0.5, -0.5, 0.0}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
};
Vertex BASIC_QUAD[] = {
  {{-1,  1, 0}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{-1, -1, 0}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{ 1, -1, 0}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},

  {{-1,  1, 0}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{ 1, -1, 0}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 1,  1, 0}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
};
Vertex BASIC_CUBE[] = {
  // Back
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{ 0.5, -0.5, -0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 0.5,  0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5,  0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{-0.5,  0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  // Front
  {{-0.5, -0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{ 0.5, -0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{-0.5,  0.5,  0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{-0.5, -0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  // Left
  {{-0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{-0.5,  0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{-0.5, -0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{-0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  // Right
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 0.5,  0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  // Bottom
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5, -0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 0.5, -0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{-0.5, -0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{-0.5, -0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  // Top
  {{-0.5,  0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
  {{ 0.5,  0.5, -0.5}, {0, 0, 1}, {1, 1}, {0, 0, 0, 1}},
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{ 0.5,  0.5,  0.5}, {0, 0, 1}, {1, 0}, {0, 0, 0, 1}},
  {{-0.5,  0.5,  0.5}, {0, 0, 1}, {0, 0}, {0, 0, 0, 1}},
  {{-0.5,  0.5, -0.5}, {0, 0, 1}, {0, 1}, {0, 0, 0, 1}},
};


Mesh::Mesh() {
  vao = 0;
  vbo = 0;
  ebo = 0;
}
Mesh::Mesh(unsigned int type) {
  switch (type) {
    case MESH_TRI:
      vertices = Array(BASIC_TRI, 3);
      break;
    case MESH_QUAD:
      vertices = Array(BASIC_QUAD, 6);
      break;
    case MESH_CUBE:
      vertices = Array(BASIC_CUBE, 36);
      break;
    default: break;
  }
  vao = 0;
  vbo = 0;
  ebo = 0;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(
    GL_ARRAY_BUFFER,
    vertices.len * sizeof(Vertex),
    vertices.buffer, GL_STATIC_DRAW);

  // Position
  glVertexAttribPointer(
    0, 3, GL_FLOAT,
    false, sizeof(Vertex), 0);
  glEnableVertexAttribArray(0);
  // Normal
  glVertexAttribPointer(
    1, 3, GL_FLOAT,
    false, sizeof(Vertex),
    reinterpret_cast<void*>((sizeof(Vec3f))));
  glEnableVertexAttribArray(1);
  // Texcoord
  glVertexAttribPointer(
    2, 2, GL_FLOAT,
    false, sizeof(Vertex),
    reinterpret_cast<void*>((sizeof(Vec3f) * 2)));
  glEnableVertexAttribArray(2);
  // Texcoord
  glVertexAttribPointer(
    3, 4, GL_FLOAT,
    false, sizeof(Vertex),
    reinterpret_cast<void*>(((sizeof(Vec3f) * 2) + sizeof(Vec2f))));
  glEnableVertexAttribArray(3);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
Mesh::~Mesh() {
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &ebo);
}

// TEMP
void Mesh::draw(Vec3f position = {0,0,0}, Vec3f scale = {1,1,1}, Vec3f rotation = {0,0,0}) {
  if (shader.id != 0) {
    shader.setUniform("view", camera.getMatrix());
    shader.setUniform("model", Matrix()
        .translate(position)
        .scale(scale));
    glUseProgram(shader.id);
  }

  if (texture != nullptr)
    glBindTexture(GL_TEXTURE_2D, texture->id);

  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, vertices.len);
}

void Mesh::print() {
  std::cout << "Mesh\n  Verts:\n";

  for (int i = 0; i < vertices.len; i++) {
    std::cout << "    "
      << vertices[i].position << " - "
      << vertices[i].normal << " - "
      << vertices[i].tex << " - "
      << vertices[i].color << std::endl;
  }
  std::cout << "  Index:\n";
  for (int i = 0; i < indices.len; i++) {
    std::cout << "    " << indices[i].x
      << "," << indices[i].y << ","
      << indices[i].z << std::endl;
  }

  std::cout << "  vao: " << vao
    << "  vbo: " << vbo
    << "  ebo: " << ebo
    << std::endl;
}

