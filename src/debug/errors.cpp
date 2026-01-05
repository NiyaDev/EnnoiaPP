

namespace debug {
  using namespace std;
  template<typename T>
  void FATAL(String x, T y) {
    cout << "[FATAL] - "   << x << " [" << y << "]" << std::endl;
    exit(1);
  }
  #define ERROR(x,y)   cout << "[ERROR] - "   << x << " [" << y << "]" << std::endl;
  #define WARNING(x,y) cout << "[WARNING] - " << x << " [" << y << "]" << std::endl;
}

