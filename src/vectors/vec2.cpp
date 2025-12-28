

class Vec2f {
  public:
    float x;
    float y;

    // Constructors
    Vec2f();
    Vec2f(float x, float y);

    // Operators
    bool operator==(const Vec2f& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Vec2f& rhs);
};

Vec2f::Vec2f() {
  x = 0;
  y = 0;
}
Vec2f::Vec2f(float x2, float y2) {
  x = x2;
  y = y2;
}

bool Vec2f::operator==(const Vec2f& rhs) const {
  return x == rhs.x && y == rhs.y;
}
std::ostream& operator<<(std::ostream& os, const Vec2f& rhs) {
  os << "{x=" << rhs.x << ",y=" << rhs.y << "}";
  return os;
}

