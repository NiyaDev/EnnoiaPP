
// Copyright 2026 NiyaDev


#include <cstdio>
#include <cstring>
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <spng.h>
#include "../../include/graphics/texture.hpp"
#include "../../include/utils/debug.hpp"


Texture::Texture(String filename) {
  FILE* file = fopen(filename.c_str(), "rb");

  spng_ctx* ctx = spng_ctx_new(0);
  size_t size;

  if (spng_set_png_file(ctx, file) != 0)
    debug::ERROR("Failed to load PNG.", filename);
  if (spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &size))
    debug::ERROR("Failed to decode PNG.", filename);

  spng_ihdr ihdr;
  if (spng_get_ihdr(ctx, &ihdr))
    debug::ERROR("Failed to create IHDR.", filename);
  width  = ihdr.width;
  height = ihdr.height;

  char* data = new char[size];
  if (spng_decode_image(ctx, data, size, SPNG_FMT_RGBA8, 0))
    debug::ERROR("Failed to decode png.", filename);
  // ReverseData(data, size, width, height, 4); // TODO: Test without first

  // OpenGL
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGBA,
    width, height, 0, GL_RGBA,
    GL_UNSIGNED_BYTE, data);
  // glGenerateMipmap(GL_TEXTURE_2D);
  if (id == 0) debug::ERROR("Failed to upload texture.", filename);

  // Cleanup
  spng_ctx_free(ctx);
  free(data);
  fclose(file);
}

Texture::Texture(char* data, size_t len) {
  spng_ctx* ctx = spng_ctx_new(0);
  size_t size;

  if (spng_set_png_buffer(ctx, data, len))
    debug::ERROR("Failed to set png buffer.", 0);
  if (spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &size))
    debug::ERROR("Failed to decode image.", 0);

  spng_ihdr ihdr;
  if (spng_get_ihdr(ctx, &ihdr))
    debug::ERROR("Failed to create IHDR.", 0);
  width  = ihdr.width;
  height = ihdr.height;

  char* newdata = new char[size];
  if (spng_decode_image(ctx, newdata, size, SPNG_FMT_RGBA8, 0))
    debug::ERROR("Failed to decode png.", 0);
  // ReverseData(newdata, size, width, height, 4); // TODO: Test without first

  // OpenGL
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGBA,
    width, height, 0, GL_RGBA,
    GL_UNSIGNED_BYTE, data);
  // glGenerateMipmap(GL_TEXTURE_2D);
  if (id == 0) debug::ERROR("Failed to upload texture.", 0);

  // Cleanup
  spng_ctx_free(ctx);
  free(newdata);
}

Texture::Texture(unsigned int w, unsigned int h) {
  width = w;
  height = h;

  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGBA,
    width, height, 0, GL_RGBA,
    GL_UNSIGNED_BYTE, 0);
}

Texture::Texture() {}

Texture::~Texture() {
  glDeleteTextures(1, &id);
}


void ReverseData(
    char* data, size_t len,
    unsigned int width, unsigned int height,
    int bytesPerPixel) {
  size_t stride = width * bytesPerPixel;
  char* row = new char[stride];

  for (int y = 0; y < height / 2; y++) {
    char* top = data + (y * stride);
    char* bot = data + (height - y - 1) * stride;

    memcpy(row, top, stride);
    memcpy(top, bot, stride);
    memcpy(bot, row, stride);
  }
  free(row);
}

