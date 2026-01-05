

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
};


template<int x, int y>
Matrix<x,y>::Matrix() {
  for (int x2 = 0; x2 < x; x2++) {
    for (int y2 = 0; y2 < y; y2++) {
      if (x2 == y2) m[x2][y2] = 1;
    }
  }
}
template<int x, int y>
Matrix<x,y>::Matrix(Array<float> arr) {
  if (arr.len != x * y)
    debug::FATAL("Matrix out of bounds.", 0);

  for (int y2 = 0; y2 < y; y2++) {
    for (int x2 = 0; x2 < x; x2++) {
      std::cout << "[x:" << x2 << ",y:" << y2 << "] " << x2+y2 << std::endl;
      std::cout << m[x2][y2] << " " << arr[x2+y2] << std::endl;
      m[x2][y2] = arr[x2+y2];
    }
  }
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
  //os << "{x=" << rhs.x << ",y=" << rhs.y << "}";
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

