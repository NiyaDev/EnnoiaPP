
// Copyright 2026 NiyaDev


#include "../../include/system/ennoia.hpp"
#include "../../include/system/keybinds.hpp"


void Ennoia::updateKeybinds() {
  mouse_delta = Vec2f(0,0);

  for (int i = 0; i < keyqueue.size(); i++) {
    keyqueue[i].repeat = true;
    if (keyqueue[i].down == false) {
      keyqueue
    }
  }
}

