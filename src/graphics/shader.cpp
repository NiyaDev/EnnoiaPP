
// Copyright 2026 NiyaDev


#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include "../../include/graphics/shader.hpp"
#include "../../include/utils/debug.hpp"


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

void Shader::use() {
  glUseProgram(id);
}

