
// Copyright 2026 NiyaDev


#include <cmath>
#include "../../include/vectors/vec3.hpp"


Vec3f::Vec3f() { x = 0; y = 0; z = 0; }
Vec3f::Vec3f(float x2, float y2, float z2) { x = x2; y = y2; z = z2; }

// Relational
bool Vec3f::operator==(const Vec3f& rhs) const
  { return x == rhs.x && y == rhs.y && z == rhs.z; }
// Arithmetic self
Vec3f Vec3f::operator+(const Vec3f& rhs) const
  { return Vec3f(x+rhs.x, y+rhs.y, z+rhs.z); }
Vec3f Vec3f::operator-(const Vec3f& rhs) const
  { return Vec3f(x-rhs.x, y-rhs.y, z-rhs.z); }
Vec3f Vec3f::operator*(const Vec3f& rhs) const
  { return Vec3f(x*rhs.x, y*rhs.y, z*rhs.z); }
Vec3f Vec3f::operator/(const Vec3f& rhs) const
  { return Vec3f(x/rhs.x, y/rhs.y, z/rhs.z); }
// Compound assignment self
void  Vec3f::operator+=(const Vec3f& rhs)
  { x += rhs.x; y += rhs.y; z += rhs.z; }
void  Vec3f::operator-=(const Vec3f& rhs)
  { x -= rhs.x; y -= rhs.y; z -= rhs.z; }
void  Vec3f::operator*=(const Vec3f& rhs)
  { x *= rhs.x; y *= rhs.y; z *= rhs.z; }
void  Vec3f::operator/=(const Vec3f& rhs)
  { x /= rhs.x; y /= rhs.y; z /= rhs.z; }
// Arithmetic float
Vec3f Vec3f::operator+(float rhs) const
  { return Vec3f(x+rhs, y+rhs, z+rhs); }
Vec3f Vec3f::operator-(float rhs) const
  { return Vec3f(x-rhs, y-rhs, z-rhs); }
Vec3f Vec3f::operator*(float rhs) const
  { return Vec3f(x*rhs, y*rhs, z*rhs); }
Vec3f Vec3f::operator/(float rhs) const
  { return Vec3f(x/rhs, y/rhs, z/rhs); }
// Compound assignment float
void  Vec3f::operator+=(float rhs) { x += rhs; y += rhs; z += rhs; }
void  Vec3f::operator-=(float rhs) { x -= rhs; y -= rhs; z -= rhs; }
void  Vec3f::operator*=(float rhs) { x *= rhs; y *= rhs; z *= rhs; }
void  Vec3f::operator/=(float rhs) { x /= rhs; y /= rhs; z /= rhs; }
// To string
std::ostream& operator<<(std::ostream& os, const Vec3f& rhs) {
  os << "{x=" << rhs.x << ",y=" << rhs.y << ",z=" << rhs.z << "}";
  return os;
}

// Functions
float Vec3f::length()
  { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }
float Vec3f::dot(Vec3f v3)
  { return x * v3.x + y * v3.y + z * v3.z; }
float Vec3f::distance(Vec3f v3)
  { return sqrt(pow(x-v3.x, 2) + pow(y-v3.y, 2) + pow(z-v3.z, 2)); }
float Vec3f::angle_rad(Vec3f v3) {
  Vec3f cr = cross(v3);
  float ln = cr.length();
  float dt = dot(v3);

  return atan2(dt, ln);
}
float Vec3f::angle_deg(Vec3f v3) {
  Vec3f cr = cross(v3);
  float ln = cr.length();
  float dt = dot(v3);

  return atan2(dt, ln) * (180 / M_PI);
}
Vec3f Vec3f::cross(Vec3f v3) {
  return Vec3f(
    y * v3.z - z * v3.y,
    z * v3.x - x * v3.z,
    x * v3.y - y * v3.x);
}
Vec3f Vec3f::perpendicular() {
  float min = abs(x);
  Vec3f cardinal = Vec3f(1, 0, 0);

  if (abs(y) < min) {
    min = abs(y);
    cardinal = Vec3f(0, 1, 0);
  }
  if (abs(z) < min) {
    cardinal = Vec3f(0, 1, 0);
  }

  return cross(cardinal);
}
Vec3f Vec3f::normalize() {
  float len = length();
  if (len > 0) {
    float ilen = 1 / len;
    return *this * ilen;
  }
  return *this;
}
Vec3f Vec3f::project(Vec3f v3) {
  float v1dv2 = x*v3.x + y*v3.y + z*v3.z;
  float v2dv2 = pow(v3.length(), 2);
  float mag = v1dv2 / v2dv2;

  return v3 * mag;
}
Vec3f Vec3f::reject(Vec3f v3) {
  float v1dv2 = x*v3.x + y*v3.y + z*v3.z;
  float v2dv2 = pow(v3.length(), 2);
  float mag = v1dv2 / v2dv2;

  return *this - (v3 * mag);
}
void  Vec3f::orthonormalize(Vec3f* v3) {
  *this = normalize();
  Vec3f vn1 = cross(*v3).normalize();
  Vec3f vn2 = vn1.cross(*this);

  *v3 = vn2;
}
// Vec3f Vec3f::transform(Matrix mat) { return (self.v4() * mat).v3(); }??
// Vec3f Vec3f::rotate_quaternion(Quaternion q) {
//  Quaternion normed = q.normalize();
//  Quaternion new = *this.q();
//  Quaternion normedNeg = Quaternion(
//    -normed.x, -normed.y,
//    -normed.z,  normed.w);
//
//  return (normed * new * normedNeg).v3;
// }
Vec3f Vec3f::rotate(Vec3f dist, float rot) {
  Vec3f pos;

  pos.x = dist.x * cos(rot / (180 / M_PI)) - dist.z * sin(rot / (180 / M_PI));
  pos.z = dist.x * sin(rot / (180 / M_PI)) + dist.z * cos(rot / (180 / M_PI));

  pos.x += x;
  pos.y  = y + dist.y;
  pos.z += z;

  return pos;
}
Vec3f Vec3f::rotate_axis(Vec3f axis, float angle) {
  Vec3f newAxis = axis.normalize();
  float a = sin(angle /2);
  newAxis *= a;
  a = cos(angle);

  Vec3f wv  = newAxis.cross(*this);
  Vec3f wwv = newAxis.cross(wv);

  a  *= 2;
  wv *= a;
  wv *= 2;

  return *this + wv + wwv;
}
Vec3f Vec3f::lerp(Vec3f target, float amount)
  { return *this + (target - *this) * amount; }
Vec3f Vec3f::reflect(Vec3f normal)
  { return *this - (normal * 2) * dot(normal); }
Vec3f Vec3f::move_towards(Vec3f target, float max_distance) {
  Vec3f d = target - *this;
  float value = pow(d.length(), 2);

  if (value == 0 || (max_distance >= 0 && value <= pow(max_distance, 2)))
    return Vec3f();

  float dist = sqrt(value);

  Vec3f res = *this + d / dist * max_distance;

  return *this + d / dist * max_distance;
}
Vec3f Vec3f::invert() { return Vec3f(1/x, 1/y, 1/z); }
Vec3f Vec3f::clamp(Vec3f min, Vec3f max) {
  float x2 = x;
  float y2 = y;
  float z2 = z;

  if (x > max.x) x2 = max.x;
  if (x < min.x) x2 = min.x;

  if (y > max.y) y2 = max.y;
  if (y < min.y) y2 = min.y;

  if (z > max.z) z2 = max.z;
  if (z < min.z) z2 = min.z;

  return Vec3f(x2, y2, z2);
}

