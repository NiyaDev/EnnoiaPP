
// Copyright 2026 NiyaDev


#ifndef INCLUDE_GRAPHICS_MESH_HPP_
#define INCLUDE_GRAPHICS_MESH_HPP_


#include <unordered_map>
#include "../../include/utils/array.hpp"
#include "../../include/vectors/vec3.hpp"
#include "../../include/vectors/vec4.hpp"
#include "../graphics/shader.hpp"


struct Vertex {
  Vec3f position;
  Vec3f normal;
  Vec2f tex;
  Vec4f color;
};

struct Index {
  unsigned int x;
  unsigned int y;
  unsigned int z;
};

struct Mesh {
  Array<Vertex> vertices;
  Array<Index>  indices;

  unsigned int vao, vbo, ebo;

  Shader shader;
  String materialName;
  Texture* texture;

  Mesh();
  explicit Mesh(String filename);
  explicit Mesh(unsigned int type);
  Mesh(char* data, size_t size);
  ~Mesh();

  // void Mesh::Draw(Vec3f position, Vec3f scale, Vec3f rotation);
  void Print();
};


#define MESH_TRI  1
#define MESH_QUAD 2
#define MESH_CUBE 3


#endif  // INCLUDE_GRAPHICS_MESH_HPP_

