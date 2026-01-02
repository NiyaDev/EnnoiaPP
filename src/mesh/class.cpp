

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
  Vertex vertices[];
  Index indices[];

  unsigned int vao, vbo, ebo;

  //Shader shader;
  String materialName;
  Texture* texture;

  Mesh(String filename);
  Mesh(char* data, size_t size);
  Mesh(unsigned int type);
  ~Mesh();
};

#include"constants.hpp"


Mesh::Mesh(unsigned int type) {
  switch (type) {
    case MESH_TRI:
      vertices = BASIC_TRI;
    case MESH_QUAD:
    case MESH_CUBE:
    default: break;
  }
}

