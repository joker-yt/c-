#include <iostream>
#include <memory>

using namespace std;

class CTest {
public:
  CTest() : _n(0) { cout << "constructor" << endl; };

  virtual ~CTest() { cout << "destructor" << endl; };
  CTest(const CTest &other) { cout << "copy constructor(const)" << endl; };
  CTest(CTest &&other) { cout << "copy constructor" << endl; };
  CTest &operator=(const CTest &other) {
    cout << "operator(copy const)" << endl;
    return *this;
  };
  CTest &operator=(CTest &&other) {
    cout << "operator(copy)" << endl;
    return *this;
  };

  void method() { _n++; }
  int value() { return _n; };
  int _n;
};

int main(int argc, char *argv[]) {
  CTest cl;
  cl.method();
  CTest cl2{move(cl)};

  unique_ptr<CTest> p{new CTest};
  p->method();
  p->method();
  CTest *pp = p.get();
  cout << pp->value() << endl;

  return 0;
}
