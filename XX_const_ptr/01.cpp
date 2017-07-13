#include <iostream>
#include <time.h>

void timestr(char *buf, size_t sz);

class CMyClass {
private:
public:
  CMyClass() { std::cout << __FUNCTION__ << std::endl; };
  virtual ~CMyClass() = default;
  //==========================================================
  // void method() must be "const"!
  // if without "const",
  // const MyClass obj;
  // obj.method();  <-----compile error!
  //==========================================================
  void method() const {
    char tm_str[32] = {0};
    timestr(tm_str, sizeof(tm_str));
    std::cout << __FUNCTION__ << "[" << tm_str << "] method call" << std::endl;
  }
};

void timestr(char *buf, size_t sz) {
  time_t t;
  t = time(NULL);
  struct tm *tms = localtime(&t);

  strftime(buf, sz, "%a %Y-%m-%d %H:%M:%S %Z", tms);
}

int main(int argc, char const *argv[]) {
  const CMyClass obj1;
  obj1.method();
  return 0;
}
