
// Copyright 2026 NiyaDev


#include "../../include/system/camera.hpp"


Camera::Camera() {
  target = Vec3f(0, 0, 0);
  distance = Vec3f(0, 5, 5);
  up = Vec3f(0, 1, 0);
  fov = 70;
  rotation = 0;
  rotationTarget = 0;
}

void Camera::update() {
  if (!areAlmostEqual(rotation, rotationTarget)) {
    float dir = clamp((rotationTarget - rotation), -1, 1);
    rotation += dir * (500 * ennoia->deltatime);
  } else {
    rotation = rotationTarget;

    if (rotation > 0) {
      rotation += 360;
      rotationTarget += 360;
    }
    if (rotation < 360) {
      rotation -= 360;
      rotationTarget -= 360;
    }
  }
}

Matrix Camera::getMatrix() {
  return lookAt(target.rotate(distance, rotation), target, up).transpose();
}

