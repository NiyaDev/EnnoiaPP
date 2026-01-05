

class Ennoia {
  private:
    struct { // SDL
      SDL_Window* window;
      SDL_GLContext context;
      SDL_Event event;
    };

    struct { // Framebuffer
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
    Ennoia(String title);
    ~Ennoia();

    bool ShouldClose();
    void Draw();

    Ennoia* SetScreen(int width, int height);
    Ennoia* SetRender(int width, int height);
};

Ennoia::Ennoia(String title = "Ennoia") {
  // Load all options + default
  screenWidth  = 1280;
  screenHeight =  720;
  renderWidth  = screenWidth / 1;
  renderHeight = screenHeight / 1;

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

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
    debug::FATAL("GLEW Failed to initialize.", 0);

  // GL Enables
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  // Create Default Shaders
  default_shader_2d = Shader(DEFAULT_VERTEX_2D, DEFAULT_FRAGMENT_2D);
  default_shader_2d.SetUniform("screensize", Vec2f((float)renderWidth, (float)renderHeight));
  default_shader_3d = Shader(DEFAULT_VERTEX_3D, DEFAULT_FRAGMENT_3D);
  //default_shader_2d.SetUniform("projection", matrix::perspective{float}(70 * math::PI / 180, (float)renWidth / (float)renHeight, 0.1, 100.0).transpose());

  // Framebuffer
  framebuffer.quad = Mesh(MESH_QUAD);
  framebuffer.quad.shader = Shader(FB_VERTEX, FB_FRAGMENT);
  framebuffer.quad.shader.SetUniform("screenTexture", (int)0);

  glGenFramebuffers(1, &framebuffer.fb);
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer.fb);

  framebuffer.tex = Texture(renderWidth, renderHeight);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebuffer.tex.id, 0);

  glGenRenderbuffers(1, &framebuffer.rb);
  glBindRenderbuffer(GL_RENDERBUFFER, framebuffer.rb);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, renderWidth, renderHeight);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, framebuffer.rb);
  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    debug::FATAL("Failed to setup framebuffer.", 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);

  // Load Defaults
  // Keybinds
}
Ennoia::~Ennoia() {
  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_GL_DestroyContext(context);
  event = {};

  glDeleteFramebuffers(1, &framebuffer.fb);
  glDeleteRenderbuffers(1, &framebuffer.rb);

  SDL_Quit();
}

void Ennoia::Draw() {
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer.fb);
  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, renderWidth, renderHeight);

  glClearColor(0.5, 0.5, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // End
  // scrollwheel = 0;


  
  // Setup default framebuffer
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glDisable(GL_DEPTH_TEST);
  glClearColor(0.5, 0.5, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, screenWidth, screenHeight);
  
  // Draw quad to screen
  framebuffer.quad.shader.Use();
  glActiveTexture(GL_TEXTURE0);
  glBindVertexArray(framebuffer.quad.vao);
  glBindTexture(GL_TEXTURE_2D, framebuffer.tex.id);
  glDrawArrays(GL_TRIANGLES, 0, framebuffer.quad.vertices.len);

  SDL_GL_SwapWindow(window);
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

