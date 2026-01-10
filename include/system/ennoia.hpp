
// Copyright 2026 NiyaDev


#ifndef INCLUDE_SYSTEM_ENNOIA_HPP_
#define INCLUDE_SYSTEM_ENNOIA_HPP_


#include <SDL3/SDL.h>
#include "../graphics/texture.hpp"
#include "../graphics/mesh.hpp"
#include "../graphics/shader.hpp"


class Ennoia {
  private:
    struct {  // SDL
      SDL_Window* window;
      SDL_GLContext context;
      SDL_Event event;
    };

    struct {  // Framebuffer
      unsigned int fb, rb;
      Texture tex;
      Mesh quad;
    } framebuffer;

    Shader default_shader_2d;
    Shader default_shader_3d;

  public:
    unsigned int screenWidth, screenHeight;
    unsigned int renderWidth, renderHeight;

    bool borderless, fullscreen;

    double deltatime, lastframe;

    // Constructors
    explicit Ennoia(String title);
    ~Ennoia();

    bool ShouldClose();
    void Draw();

    Ennoia* SetScreen(int width, int height);
    Ennoia* SetRender(int width, int height);
};

static Ennoia* ennoia;


#endif  // INCLUDE_SYSTEM_ENNOIA_HPP_

