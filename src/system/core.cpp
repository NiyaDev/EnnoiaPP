

class Ennoia {
  private:
    struct { // SDL objects
      SDL_Window* window;
      SDL_GLContext* context;
      SDL_Event event;
    };

  public:
    int screenWidth, screenHeight;
    int renderWidth, renderHeight;

    bool borderless, fullscreen;

    Ennoia* init();

    Ennoia* set_screen(int width, int height);
    Ennoia* set_render(int width, int height);
};

Ennoia* Ennoia::init() {
  // Load all options + default
  // Initialize SDL3
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == false) {
    std::cout << "Failed to initialize SDL3. " << SDL_GetError();
    return this;
  }

  return this;
}

Ennoia* Ennoia::set_screen(int width, int height) {
  screenWidth = width;
  screenHeight = height;

  // Reset screen texture
  return this;
}
Ennoia* Ennoia::set_render(int width, int height) {
  renderWidth = width;
  renderHeight = height;

  // Reset screen texture
  return this;
}

static Ennoia ennoia;

