
// Copyright 2026 NiyaDev


#include <cmath>
#include <ostream>
#include "../../include/vectors/vec2.hpp"


Vec2f::Vec2f() { x = 0; y = 0; }
Vec2f::Vec2f(float x2, float y2) { x = x2; y = y2; }

// Relational
bool Vec2f::operator==(const Vec2f& rhs) const
  { return x == rhs.x && y == rhs.y; }
// Arithmetic self
Vec2f Vec2f::operator+(const Vec2f& rhs) const
  { return Vec2f(x+rhs.x, y+rhs.y); }
Vec2f Vec2f::operator-(const Vec2f& rhs) const
  { return Vec2f(x-rhs.x, y-rhs.y); }
Vec2f Vec2f::operator*(const Vec2f& rhs) const
  { return Vec2f(x*rhs.x, y*rhs.y); }
Vec2f Vec2f::operator/(const Vec2f& rhs) const
  { return Vec2f(x/rhs.x, y/rhs.y); }
// Compound assignment self
void  Vec2f::operator+=(const Vec2f& rhs) { x += rhs.x; y += rhs.y; }
void  Vec2f::operator-=(const Vec2f& rhs) { x -= rhs.x; y -= rhs.y; }
void  Vec2f::operator*=(const Vec2f& rhs) { x *= rhs.x; y *= rhs.y; }
void  Vec2f::operator/=(const Vec2f& rhs) { x /= rhs.x; y /= rhs.y; }
// Arithmetic float
Vec2f Vec2f::operator+(float rhs) const
  { return Vec2f(x+rhs, y+rhs); }
Vec2f Vec2f::operator-(float rhs) const
  { return Vec2f(x-rhs, y-rhs); }
Vec2f Vec2f::operator*(float rhs) const
  { return Vec2f(x*rhs, y*rhs); }
Vec2f Vec2f::operator/(float rhs) const
  { return Vec2f(x/rhs, y/rhs); }
// Compound assignment float
void  Vec2f::operator+=(float rhs) { x += rhs; y += rhs; }
void  Vec2f::operator-=(float rhs) { x -= rhs; y -= rhs; }
void  Vec2f::operator*=(float rhs) { x *= rhs; y *= rhs; }
void  Vec2f::operator/=(float rhs) { x /= rhs; y /= rhs; }
// Arithmetic Matrix
// Vec2f Vec2f::operator*(Matrix<4,4> rhs) const {
//  return Vec2f(
//    (rhs.m[0][0] * x) + (rhs.m[1][0] * y) + (rhs.m[3][0] * 1),
//    (rhs.m[0][1] * x) + (rhs.m[1][1] * y) + (rhs.m[3][1] * 1)
//  );
// }
// To string
std::ostream& operator<<(std::ostream& os, const Vec2f& rhs) {
  os << "{x=" << rhs.x << ",y=" << rhs.y << "}";
  return os;
}

// Functions
float Vec2f::length()
  { return sqrt(pow(x, 2) + pow(y, 2)); }
float Vec2f::dot(Vec2f v2)
  { return (x * v2.x) + (y * v2.y); }
float Vec2f::distance(Vec2f v2)
  { return sqrt(pow(x - v2.x, 2) + pow(y - v2.y, 2)); }
float Vec2f::angle_rad(Vec2f v2)
  { return atan2(v2.y - y, v2.x - x); }
float Vec2f::angle_deg(Vec2f v2)
  { return atan2(v2.y - y, v2.x - x) * (180 / M_PI); }
Vec2f Vec2f::normalize() {
  float len = length();
  if (len > 0) {
    float ilen = 1 / len;
    return *this * ilen;
  }
  return *this;
}
Vec2f Vec2f::lerp(Vec2f v2, float amount)
  { return *this + ((v2 - *this) * amount); }
Vec2f Vec2f::reflect(Vec2f normal)
  { return *this - ((*this * normal) * 2) * normal; }
Vec2f Vec2f::rotate_rad(float angle) {
  float cosres = cos(angle);
  float sinres = sin(angle);

  return Vec2f(
    (x * cosres) - (y * sinres),
    (x * sinres) + (y * cosres));
}
Vec2f Vec2f::rotate_deg(float angle) {
  float cosres = cos(angle / (180 / M_PI));
  float sinres = sin(angle / (180 / M_PI));

  return Vec2f(
    (x * cosres) - (y * sinres),
    (x * sinres) + (y * cosres));
}
Vec2f Vec2f::move_towards(Vec2f target, float max_distance) {
  Vec2f d = target - *this;
  float value = pow(d.length(), 2);

  if (value == 0 || (max_distance >= 0 && value <= pow(max_distance, 2)))
    return target;
  float dist = distance(target);

  return *this + ((d / dist) * max_distance);
}
Vec2f Vec2f::invert() { return Vec2f(1/x, 1/y); }
Vec2f Vec2f::clamp(Vec2f min, Vec2f max) {
  float x2 = x;
  float y2 = y;

  if (x > max.x) x2 = max.x;
  if (x < min.x) x2 = min.x;

  if (y > max.y) y2 = max.y;
  if (y < min.y) y2 = min.y;

  return Vec2f(x2, y2);
}

