
class Vec3f {
  public:
    union {
      Vec2f v2;
      struct {
        float x;
        float y;
      };
    };
    float z;

    // Constructors
    Vec3f();
    Vec3f(float x, float y, float z);

    // Operators
    bool operator==(const Vec3f& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Vec3f& rhs);
};

Vec3f::Vec3f() {
  x = 0;
  y = 0;
  z = 0;
}
Vec3f::Vec3f(float x2, float y2, float z2) {
  x = x2;
  y = y2;
  z = z2;
}

bool Vec3f::operator==(const Vec3f& rhs) const {
  return x == rhs.x && y == rhs.y && z == rhs.z;
}
std::ostream& operator<<(std::ostream& os, const Vec3f& rhs) {
  os << "{x=" << rhs.x << ",y=" << rhs.y << ",z=" << rhs.z << "}";
  return os;
}

