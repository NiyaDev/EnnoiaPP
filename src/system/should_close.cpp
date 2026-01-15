
// Copyright 2026 NiyaDev


#include <SDL3/SDL.h>
#include "../../include/system/ennoia.hpp"


bool Ennoia::shouldClose() {
  // Calculate deltatime
  double current_frame = (double)SDL_GetTicks() / 1000;
  deltatime = current_frame - lastframe;
  lastframe = current_frame;

  // Update keybinds
  // Poll event handler
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_EVENT_QUIT:
      case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        return true;

      case SDL_EVENT_KEY_DOWN:
      case SDL_EVENT_KEY_UP:
        // TODO:
        break;

      case SDL_EVENT_WINDOW_HDR_STATE_CHANGED:
      case SDL_EVENT_WINDOW_SHOWN:
      case SDL_EVENT_WINDOW_EXPOSED:
      case SDL_EVENT_WINDOW_MOVED:
      case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
      case SDL_EVENT_WINDOW_MINIMIZED:
      case SDL_EVENT_WINDOW_RESTORED:
      case SDL_EVENT_WINDOW_MOUSE_ENTER:
      case SDL_EVENT_WINDOW_MOUSE_LEAVE:
      case SDL_EVENT_WINDOW_FOCUS_GAINED:
      case SDL_EVENT_WINDOW_FOCUS_LOST:
      case SDL_EVENT_WINDOW_SAFE_AREA_CHANGED:
      case SDL_EVENT_WINDOW_OCCLUDED:
      case SDL_EVENT_KEYMAP_CHANGED:
      case SDL_EVENT_CLIPBOARD_UPDATE:
        break;

      case SDL_EVENT_AUDIO_DEVICE_ADDED:
        break;

      case SDL_EVENT_MOUSE_MOTION:
      case SDL_EVENT_MOUSE_BUTTON_DOWN:
      case SDL_EVENT_MOUSE_BUTTON_UP:
      case SDL_EVENT_MOUSE_WHEEL:
        // TODO:
        break;

      case SDL_EVENT_SENSOR_UPDATE: break;
      
      default:
        debug::ERROR("Unhandled event: ", event.type);
        break;
    }
  }

  // Default exit button

  return false;
}

