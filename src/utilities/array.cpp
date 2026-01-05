

template<typename T>
struct Array;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& rhs);

template<typename T>
struct Array {
  T* buffer;
  size_t len;

  Array();
  Array(size_t max_len);
  Array(T data[], size_t length);
  Array(std::initializer_list<T> arr);
  ~Array();

  T& operator[](size_t index);
  // To string
  friend std::ostream& operator<< <T>(std::ostream& os, const Array<T>& rhs);

  void Expand(size_t new_len);
  void Print();
};

template<typename T>
Array<T>::Array() {
  buffer = nullptr;
  len = 0;
}
template<typename T>
Array<T>::Array(size_t max_len) {
  buffer = (T*)malloc(sizeof(T) * max_len);
  memset(buffer, 0, sizeof(T) * max_len);
  len = max_len;
}
template<typename T>
Array<T>::Array(T data[], size_t length) {
  buffer = (T*)malloc(sizeof(T) * length);
  len = length;

  for (int i = 0; i < len; i++)
    buffer[i] = data[i];
}
template<typename T>
Array<T>::Array(std::initializer_list<T> arr) {
  buffer = (T*)malloc(sizeof(T) * arr.size());
  len = arr.size();

  int count = 0;
  for (T x : arr) {
    buffer[count] = x;
    count++;
  }
}
// TODO: If i try to free, sometimes it says there's a double free...
//       Makes no sense, but it happens.
template<typename T>
Array<T>::~Array() {
  //if (buffer != nullptr)
  //  free(buffer);
  buffer = nullptr;
  len = 0;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
  if (index >= len)
    debug::FATAL("Array index out of range!", 0);
  return buffer[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& rhs) {
  os << "{";
  for (int i = 0; i < rhs.len; i++)
    os << rhs.buffer[i] << ",";
  os << "}";
  return os;
}

template<typename T>
void Array<T>::Expand(size_t new_len) {
  size_t old_size = sizeof(T) * len;
  size_t new_size = sizeof(T) * new_len;

  T* temp = (T*)realloc(buffer, new_size);
  buffer = temp;
  if (new_size > old_size)
    memset(buffer+len, 0, new_size - old_size);

  len = new_len;
}
template<typename T>
void Array<T>::Print() {
  std::cout << "Array <" << typeid(T).name() << ">" << std::endl;
  for (int i = 0; i < len; i++) {
    std::cout << "  : " << buffer[i] << std::endl;
  }
}
