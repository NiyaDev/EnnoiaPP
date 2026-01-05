

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
  Mesh(String filename);
  Mesh(char* data, size_t size);
  Mesh(unsigned int type);
  ~Mesh();

  void Print();
};

#include"mesh_const.hpp"


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

  //Print();

  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.len * sizeof(Vertex), vertices.buffer, GL_STATIC_DRAW);

  if (vertices.len > 0) {
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.len * sizeof(Index), indices.buffer, GL_STATIC_DRAW);
  }
  
  // Position
  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);
  glEnableVertexAttribArray(0);
  // Normal
  glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)(sizeof(Vec3f)));
  glEnableVertexAttribArray(1);
  // Texcoord
  glVertexAttribPointer(2, 2, GL_FLOAT, false, sizeof(Vertex), (void*)(sizeof(Vec3f) * 2));
  glEnableVertexAttribArray(2);
  // Texcoord
  glVertexAttribPointer(3, 4, GL_FLOAT, false, sizeof(Vertex), (void*)((sizeof(Vec3f) * 2) + sizeof(Vec2f)));
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
/*
void Mesh::Draw(Vec3f position = {0,0,0}, Vec3f scale = {1,1,1}, Vec3f roation = {0,0,0}) {
  if (shader.id != 0) {
    shader.Use();
    //shader.SetUniform("view", camera::main.GetMatrix());
    //shader.SetUniform("model", )
  }
}*/

void Mesh::Print() {
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
    std::cout << "    " << indices[i].x << "," << indices[i].y << "," << indices[i].z << std::endl;
  }

  std::cout << "  vao: " << vao << "  vbo: " << vbo << "  ebo: " << ebo << std::endl;
}

