

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

    // Constructors
    Ennoia();
    //~Ennoia();
    //Ennoia* init();
    //Ennoia* clean();

    Ennoia* set_screen(int width, int height);
    Ennoia* set_render(int width, int height);
};

Ennoia::Ennoia() {
  // Load all options + default
  // Initialize SDL3
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == false)
    debug::FATAL("Failed to initialize SDL3.", SDL_GetError());

  if (window = SDL_CreateWindow("TEST", 1280, 720, 0); window == nullptr)
    debug::FATAL("Failed to create window.", SDL_GetError());
  //SDL_GLSetAttribute();
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

static Ennoia* ennoia;

