

template<int x, int y>
struct Matrix {
  float m[x][y];

  // Constructors
  Matrix();
  Matrix(Array<float> arr);

  // Operators
  // Relational
  bool  operator==(const Matrix<x,y>& rhs) const;
  // To string
  //std::ostream& operator<<(std::ostream& os, const Matrix<x,y>& rhs);
  
  Matrix<4,4> transpose();
  void print();
};


template<int x, int y>
Matrix<x,y>::Matrix() {
  for (int x2 = 0; x2 < x; x2++) {
    for (int y2 = 0; y2 < y; y2++) {
      if (x2 == y2) {
        m[x2][y2] = 1;
      } else {
        m[x2][y2] = 0;
      }
    }
  }
}
template<int x, int y>
Matrix<x,y>::Matrix(Array<float> arr) {
  if (arr.len != x * y)
    debug::FATAL("Matrix out of bounds.", 0);

  for (int y2 = 0; y2 < y; y2++) {
    for (int x2 = 0; x2 < x; x2++) {
      m[x2][y2] = arr[x2+y2];
    }
  }
}
Matrix<4,4> lookAt(Vec3f eye, Vec3f target, Vec3f up) {
  float length, ilength;

  Vec3f vz = eye - target;
  
  Vec3f v = vz.normalize();
  length = v.length();
  if (length == 0)
    length = 1;
  ilength = 1 / length;
  vz *= ilength;

  Vec3f vx = up.cross(vz);
  
  v = vx.normalize();
  length = v.length();
  if (length == 0)
    length = 1;
  ilength = 1 / length;
  vx *= ilength;

  Vec3f vy = vz.cross(vz);

  return Matrix<4,4>(
    {
      vx.x, vy.x, vz.x, 0,
      vx.y, vy.y, vz.y, 0,
      vx.z, vy.z, vz.z, 0,
      -vx.dot(eye), -vy.dot(eye), -vz.dot(eye), 1
    }
  );
}
template<int x, int y>
Matrix<4,4> Matrix<x,y>::transpose() {
  if (x != 4 || y != 4)
    debug::FATAL("Attempting to transpose a non-4x4 matrix", 0);
  
  return Matrix<4,4>(
    {
      m[0][0], m[1][0], m[2][0], m[3][0],
      m[0][1], m[1][1], m[2][1], m[3][1],
      m[0][2], m[1][2], m[2][2], m[3][2],
      m[0][3], m[1][3], m[2][3], m[3][3],
    }
  );
}

// Relational
template<int x, int y>
bool Matrix<x,y>::operator==(const Matrix<x,y>& rhs) const {
  for (int y2 = 0; y2 < y; y2++) {
    for (int x2 = 0; x2 < x; x2++) {
      if (m[x][y] != rhs.m[x][y]) return false;
    }
  }
  return true;
}
// To string
template<int x, int y>
std::ostream& operator<<(std::ostream& os, const Matrix<x,y>& rhs) {
  os << "{\n";
  for (int y2 = 0; y2 < y; y2++) {
    os << "  ";
    for (int x2 = 0; x2 < x; x2++) {
      os << rhs.m[x][y] << ",";
    }
    os << "\n";
  }
  os << "}";
  return os;
}

template<int x, int y>
void Matrix<x,y>::print() {
  std::cout << "{\n";
  for (int y2 = 0; y2 < y; y2++) {
    std::cout << "  ";
    for (int x2 = 0; x2 < x; x2++) {
      std::cout << m[x][y] << ",";
    }
    std::cout << "\n";
  }
  std::cout << "}" << std::endl;
}

