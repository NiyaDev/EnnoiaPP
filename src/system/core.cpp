

class Ennoia {
  private:
    struct { // SDL objects
      SDL_Window* window;
      SDL_GLContext context;
      SDL_Event event;
    };

  public:
    int screenWidth, screenHeight;
    int renderWidth, renderHeight;

    bool borderless, fullscreen;

    double deltatime, lastframe;

    // Constructors
    Ennoia(String title);
    ~Ennoia();

    bool ShouldClose();

    Ennoia* SetScreen(int width, int height);
    Ennoia* SetRender(int width, int height);
};

Ennoia::Ennoia(String title = "Ennoia") {
  // Load all options + default
  screenWidth  = 1280;
  screenHeight =  720;
  renderWidth  =  screenWidth / 1;
  screenHeight = screenHeight / 1;

  // Initialize SDL3
  SDL_SetLogPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);
  SDL_SetLogPriority(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_VERBOSE);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    debug::FATAL("Failed to initialize SDL3.", 0);
  if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3))
    debug::FATAL("Failed to set GL version to 3.X.", 0);
  if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3))
    debug::FATAL("Failed to set GL version to 3.3.", 0);
  if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE))
    debug::FATAL("Failed to set GL context profile to Core.", 0);

  // Create Window
  window = SDL_CreateWindow(title.c_str(), screenWidth, screenHeight, SDL_WINDOW_OPENGL);
  if (window == nullptr)
    debug::FATAL("Failed to create window.", SDL_GetError());

  // Create OpenGL context
  context = SDL_GL_CreateContext(window);
  if (context == nullptr)
    debug::FATAL("Failed to create OpenGL context.", SDL_GetError());
  if (!SDL_GL_MakeCurrent(window, context))
    debug::FATAL("Failed to make OpenGL context current.", SDL_GetError());

  // GL Enables
  

  // Create Default Shaders
  // Framebuffer
  // Load Defaults
  // Keybinds
}
Ennoia::~Ennoia() {
  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_GL_DestroyContext(context);
  event = {};

  SDL_Quit();
}

Ennoia* Ennoia::SetScreen(int width, int height) {
  screenWidth = width;
  screenHeight = height;

  // Reset screen texture
  return this;
}
Ennoia* Ennoia::SetRender(int width, int height) {
  renderWidth = width;
  renderHeight = height;

  // Reset screen texture
  return this;
}

#include"should_close.cpp"

