
// Copyright 2026 NiyaDev


#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include "../../include/graphics/shader.hpp"
#include "../../include/graphics/texture.hpp"
#include "../../include/utils/debug.hpp"
#include "../../include/vectors/vec2.hpp"
#include "../../include/vectors/vec3.hpp"
#include "../../include/vectors/vec4.hpp"


Shader::Shader() {}
Shader::Shader(const char* vs, const char* fs) {
  int success = 0;
  id = glCreateProgram();

  // Vertex Shader
  unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  if (vs != nullptr) {
    glShaderSource(vertex_shader, 1, &vs, NULL);
  } else {
    const char* vs_src = FB_VERTEX;
    glShaderSource(vertex_shader, 1, &vs_src, nullptr);
  }
  glCompileShader(vertex_shader);
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (success == 0) {
    char* log = reinterpret_cast<char*>(malloc(512));
    glGetShaderInfoLog(vertex_shader, 512, NULL, log);
    debug::ERROR("Failed to compile Vertex shader.", log);
    free(log);
  }
  glAttachShader(id, vertex_shader);

  // Fragment Shader
  unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  if (fs != nullptr) {
    glShaderSource(fragment_shader, 1, &fs, NULL);
  } else {
    const char* fs_src = FB_FRAGMENT;
    glShaderSource(fragment_shader, 1, &fs_src, nullptr);
  }
  glCompileShader(fragment_shader);
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (success == 0) {
    char* log = reinterpret_cast<char*>(malloc(512));
    glGetShaderInfoLog(fragment_shader, 512, NULL, log);
    debug::ERROR("Failed to compile Fragment shader.", log);
    free(log);
  }
  glAttachShader(id, fragment_shader);

  // Linking
  glLinkProgram(id);
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (success == 0) {
    char* log = reinterpret_cast<char*>(malloc(512));
    glGetProgramInfoLog(id, 512, NULL, log);
    debug::ERROR("Failed to compile Shader.", log);
    free(log);
  }

  // Cleanup
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}
Shader::~Shader() {
  if (id != 0)
    glDeleteProgram(id);
  locs.clear();
}

void Shader::Use() {
  glUseProgram(id);
}

template<typename T>
void Shader::SetUniform(String key, T data) {
  unsigned int loc;
  if (locs.find(key) != locs.end()) {
    loc = locs[key];
  } else {
    loc = glGetUniformLocation(id, key.c_str());
    locs[key] = loc;
  }

  if constexpr(std::is_same<T, int>::value)
    glProgramUniform1i(id, locs[key], data);
  if constexpr(std::is_same<T, float>::value)
    glProgramUniform1f(id, locs[key], data);
  if constexpr(std::is_same<T, Vec2f>::value)
    glProgramUniform2f(id, locs[key], data.x, data.y);
  if constexpr(std::is_same<T, Vec3f>::value)
    glProgramUniform2f(id, locs[key], data.x, data.y, data.z);
  if constexpr(std::is_same<T, Vec4f>::value)
    glProgramUniform2f(id, locs[key], data.x, data.y, data.z, data.w);
  // if constexpr(std::is_same<T, Matrix<4,4>>::value)
  //  std::cout << "is Matrix" << std::endl;
  if constexpr(std::is_same<T, Texture>::value)
    glProgramUniformi(id, locs[key], data.id);
}

