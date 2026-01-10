
// Copyright 2026 NiyaDev


#ifndef INCLUDE_SYSTEM_CAMERA_HPP_
#define INCLUDE_SYSTEM_CAMERA_HPP_


#include "../utils/floats.hpp"
#include "../vectors/vec3.hpp"
#include "../vectors/matrix.hpp"
#include "../system/ennoia.hpp"


struct Camera {
  Vec3f target, distance, up;
  float fov, rotation, rotationTarget;

  Camera();

  void update();
  Matrix getMatrix();
  void rotate(float target);
  void print();
};

static Camera camera;


#endif  // INCLUDE_SYSTEM_CAMERA_HPP_

