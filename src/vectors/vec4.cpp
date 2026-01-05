

struct Vec4f {
  union {
    Vec2f v2;
    Vec3f v3;
    struct {
      float x;
      float y;
      float z;
    };
  };
  float w;

  // Constructors
  Vec4f();
  Vec4f(float x, float y, float z, float w);

  // Operators
  bool operator==(const Vec4f& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Vec4f& rhs);
};

Vec4f::Vec4f() {
  x = 0;
  y = 0;
  z = 0;
  w = 0;
}
Vec4f::Vec4f(float x2, float y2, float z2, float w2) {
  x = x2;
  y = y2;
  z = z2;
  w = w2;
}

bool Vec4f::operator==(const Vec4f& rhs) const {
  return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}
std::ostream& operator<<(std::ostream& os, const Vec4f& rhs) {
  os << "{x=" << rhs.x << ",y=" << rhs.y << ",z=" << rhs.z << ",w=" << rhs.w << "}";
  return os;
}

