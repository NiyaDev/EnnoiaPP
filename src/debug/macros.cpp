

namespace debug {
  using namespace std;
  #define FATAL(x,y)   cout << "[FATAL] - "   << x << " " << y << std::endl; exit(1);
  #define ERROR(x,y)   cout << "[ERROR] - "   << x << " " << y << std::endl;
  #define WARNING(x,y) cout << "[WARNING] - " << x << " " << y << std::endl;
  //#define INFO(x,y)    std::cout << "[INFO] - "    << x << " " << y << std::endl;
}

