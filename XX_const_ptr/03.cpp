#include <functional>
#include <iostream>
#include <memory> // make_unique
#include <time.h>
#include <unistd.h>

class CTest {
private:
public:
  CTest() {
    time_t t = time(NULL);
    char buf[32] = {0};
    struct tm *ptm = localtime(&t);
    strftime(buf, sizeof(buf), "%A %Y-%m-%d %H:%M:%S", ptm);

    std::cout << "[" << buf << "]" << __FUNCTION__ << std::endl;
  };
  virtual ~CTest() {
    time_t t = time(NULL);
    struct tm *ptm = localtime(&t);
    char buf[32] = {0};
    strftime(buf, sizeof(buf), "%A %Y-%m-%d %H:%M:%S", ptm);

    std::cout << "[" << buf << "]" << __FUNCTION__ << std::endl;
  };
  void method() { std::cout << __FUNCTION__ << std::endl; }
};

void unique_ptr_test() {
  std::cout << __FUNCTION__ << " start" << std::endl;
  std::unique_ptr<CTest> p = std::make_unique<CTest>();
  p->method();
  std::cout << __FUNCTION__ << " end" << std::endl;
}

int main(int argc, char const *argv[]) {
  std::cout << "-------------------" << std::endl;
  unique_ptr_test();
  std::cout << "-------------------" << std::endl;
  return 0;
}
