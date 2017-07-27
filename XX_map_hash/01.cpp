#include <iostream>
#include <unordered_map>

void func01();
void func02();
void func03();
void func04();

#define TEST01

class CMyClass {
private:
  int _idx;

public:
  CMyClass() : _idx(-1) { std::cout << __FUNCTION__ << " -> " << _idx << "\n"; }
  CMyClass(int n) : _idx(n) {
    std::cout << __FUNCTION__ << "(with param) -> " << _idx << "\n";
  };
  CMyClass(const CMyClass &obj) : _idx(obj._idx) {
    std::cout << __FUNCTION__ << "(copy) -> " << _idx << "\n";
  };
  CMyClass(CMyClass &&obj) : _idx(obj._idx) {
    std::cout << __FUNCTION__ << "(move) -> " << _idx << " " << std::hex << &obj
              << "\n";
  };
  virtual ~CMyClass() { std::cout << __FUNCTION__ << " -> " << _idx << "\n"; };
  int Value() { return _idx; }
  CMyClass &operator=(CMyClass &&obj) {
    std::cout << "operator=(move) -> " << _idx << "\n";
    this->move(obj);
    return *this;
  }
  CMyClass &operator=(const CMyClass &obj) {
    std::cout << "operator=(copy) " << obj._idx << " " << std::hex << &obj
              << std::endl;
    std::cout << "A"
              << "\n";
    CMyClass tmp = obj;
    std::cout << "B"
              << "\n";
    // infinite loop!
    // std::swap(*this, tmp);
    this->swap(tmp);
    std::cout << "C"
              << "\n";
    return *this;
  }
  void swap(CMyClass obj) { std::swap(_idx, obj._idx); }
  void move(CMyClass obj) { _idx = std::move(obj._idx); }
};

int main(int argc, char *argv[]) {
#ifdef TEST01
  func01();
#endif

#ifdef TEST02
  func02();
#endif

#ifdef TEST03
  func03();
#endif

  return 0;
}
/*! \fn func01
 * @brief brief comment
 * @detail detail comment
 */
void func01() {
  std::unordered_map<std::string, CMyClass> mp;
  int n = 0;
  std::cout << "-------------------"
            << "\n";
  n++;
  mp[std::to_string(n)] = CMyClass{n};
  std::cout << "-------------------"
            << "\n";
  n++;
  mp[std::to_string(n)] = CMyClass{n};
  std::cout << "-------------------"
            << "\n";

  for (int i = 1; i <= n; i++) {
    std::cout << std::to_string(i) << " " << mp[std::to_string(i)].Value()
              << "\n";
  }
}
/*! \fn func
 * @brief brief comment
 * @detail detail comment
 */
void func02() {}
/*! \fn func
 * @brief brief comment
 * @detail detail comment
 */
void func03() {}
/*! \fn func
 * @brief brief comment
 * @detail detail comment
 */
void func04() {}
