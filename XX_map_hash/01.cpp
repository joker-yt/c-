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
  CMyClass() : _idx(99) { std::cout << __FUNCTION__ << " -> " << _idx << "\n"; }
  CMyClass(int n) : _idx(n) {
    std::cout << __FUNCTION__ << "(with param) -> " << _idx << "\n";
  };
  CMyClass(const CMyClass &obj) : _idx(obj._idx) {
    std::cout << __FUNCTION__ << "(copy) -> " << _idx << "\n";
  };
  CMyClass(const CMyClass &&obj) : _idx(obj._idx) {
    std::cout << __FUNCTION__ << "(move) -> " << _idx << "\n";
  };
  virtual ~CMyClass() { std::cout << __FUNCTION__ << " -> " << _idx << "\n"; };
  int Value() { return _idx; }
  CMyClass &operator=(const CMyClass &obj) {
    std::cout << "A"
              << "\n";
    CMyClass tmp = *this;
    std::cout << "B"
              << "\n";
    std::swap(std::move(tmp), std::move(obj));
    std::cout << "C"
              << "\n";
    return *this;
  }
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
  int n = 1;
  mp[std::to_string(n)] = CMyClass{n};
  n++;
  mp[std::to_string(n)] = CMyClass{n};
  n++;

  for (int i = 1; i <= n; i++) {
    std::cout << std::to_string(i) << mp[std::to_string(i)].Value() << "\n";
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
