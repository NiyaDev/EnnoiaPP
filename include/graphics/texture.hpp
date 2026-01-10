
// Copyright 2026 NiyaDev


#ifndef INCLUDE_GRAPHICS_TEXTURE_HPP_
#define INCLUDE_GRAPHICS_TEXTURE_HPP_


#include "../types.h"


struct Texture {
  unsigned int id;
  unsigned int width, height;

  Texture();
  explicit Texture(String filename);
  Texture(char* data, size_t len);
  Texture(unsigned int w, unsigned int h);
  ~Texture();
};


#endif  // INCLUDE_GRAPHICS_TEXTURE_HPP_

