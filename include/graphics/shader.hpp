
// Copyright 2026 NiyaDev


#ifndef INCLUDE_GRAPHICS_SHADER_HPP_
#define INCLUDE_GRAPHICS_SHADER_HPP_


#include <unordered_map>
#include <GL/glew.h>
#include <GL/gl.h>
#include "../types.h"
#include "../graphics/texture.hpp"
#include "../vectors/math.hpp"


struct Shader {
  unsigned int id;
  std::unordered_map<String, unsigned int> locs;

  Shader();
  Shader(const char* vs, const char* fs);
  ~Shader();

  void use();

  template<typename T>
  void setUniform(String key, T data);
};

template<typename T>
void Shader::setUniform(String key, T data) {
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
  if constexpr(std::is_same<T, Matrix>::value)
    glProgramUniformMatrix4fv(id, locs[key], 1, false, reinterpret_cast<float*>(&data.m));
  if constexpr(std::is_same<T, Texture>::value)
    glProgramUniformi(id, locs[key], data.id);
}


const char DEFAULT_VERTEX_3D[] =
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "layout (location = 1) in vec3 norm;\n"
  "layout (location = 2) in vec2 aTexCoord;\n\n"
  "out vec2 TexCoord;\n\n"
  "uniform mat4 model;\n"
  "uniform mat4 view;\n"
  "uniform mat4 projection;\n\n"
  "void main() {\n"
  "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
  "  TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
  "}\n";
const char DEFAULT_FRAGMENT_3D[] =
  "#version 330 core\n"
  "out vec4 FragColor;\n\n"
  "in vec2 TexCoord;\n\n"
  "uniform sampler2D texture1;\n\n"
  "void main() {\n"
  "  FragColor = texture(texture1, TexCoord);\n"
  "}\n";

const char DEFAULT_VERTEX_2D[] =
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "layout (location = 2) in vec2 aTexCoord;\n"
  // "layout (location = 3) in vec4 aColor;\n\n"
  "out vec2 TexCoord;\n"
  "out vec2 fragUV;\n"
  "out vec4 Color;\n\n"
  "uniform vec2 screensize;\n"
  "uniform vec2 position;\n"
  "uniform vec2 scale;\n"
  "uniform vec2 texOffset;\n"
  "uniform vec2 texScale;\n"
  "uniform vec4 texColor;\n"
  "void main() {\n"
  "  vec4 scaled = (vec4(aPos, 1.0f) * vec4(scale.x, scale.y, 1.0f, 1.0f));\n"
  "  vec4 pixel_pos = (vec4(position.x, -position.y, 0.0f, 0.0f)"
  "/ vec4(screensize, 1.0f, 1.0f));\n"
  "  gl_Position = scaled + pixel_pos;\n"
  "  TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
  // "  Color = aColor;"
  "  Color = texColor;\n"
  "  fragUV = (aTexCoord * texScale) + texOffset;\n"
  "}\n";
const char DEFAULT_FRAGMENT_2D[] =
  "#version 330 core\n"
  "out vec4 FragColor;\n\n"
  "in vec2 TexCoord;\n"
  "in vec2 fragUV;"
  "in vec4 Color;\n\n"
  "uniform sampler2D texture1;\n\n"
  "void main() {\n"
  // "  FragColor = mix(texture(texture1, fragUV), Color, 0.75);\n"
  // "  FragColor = texture(texture1, TexCoord) * Color;\n"
  "  FragColor = texture(texture1, fragUV) * Color;\n"
  "}\n";

const char FB_VERTEX[] =
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "layout (location = 1) in vec3 normals;\n"
  "layout (location = 2) in vec2 aTexCoords;\n\n"
  "out vec2 TexCoords;\n\n"
  "void main() {\n"
  "  TexCoords = vec2(aTexCoords.x, aTexCoords.y);\n"
  "  gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
  "}\n";
const char FB_FRAGMENT[] =
  "#version 330 core\n"
  "out vec4 FragColor;\n\n"
  "in vec2 TexCoords;\n\n"
  "uniform sampler2D texture0;\n\n"
  "void main() {\n"
  "  FragColor = texture(texture0, TexCoords);\n"
  "}\n";


#endif  // INCLUDE_GRAPHICS_SHADER_HPP_

