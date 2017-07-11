#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

class CTest {
private:
  std::string _name;

public:
  CTest() { std::cout << __FUNCTION__ << "(default) : " << _name << "\n"; };
  CTest(std::string name) : _name(name) {
    std::cout << __FUNCTION__ << "(default with param) : " << _name << "\n";
  };
  CTest(const CTest &tst) : _name(tst._name) {
    std::cout << __FUNCTION__ << "(copy) : " << _name << "\n";
  };
  CTest(CTest &&tst) : _name(tst._name) {
    tst._name = "";
    std::cout << __FUNCTION__ << "(move) : " << _name << "\n";
  }
  virtual ~CTest() { std::cout << __FUNCTION__ << " : " << _name << "\n"; };
  CTest &operator=(const CTest &tst) {
    std::cout << __FUNCTION__ << "(operator=copy) : " << _name << "\n";
    return *this;
  }
  CTest &operator=(CTest &&tst) {
    std::cout << __FUNCTION__ << "(operator=move) : " << _name << "\n";
    return *this;
  }
  void WhatsYouName() { std::cout << __FUNCTION__ << " : " << _name << "\n"; }
};

CTest func(CTest tst) {
  std::cout << __FUNCTION__ << "\n";
  return tst;
}
CTest func2() {
  std::cout << __FUNCTION__ << "\n";
  CTest temp("temp");
  return temp;
}

// http://qiita.com/go_astrayer/items/5d85565e992487daa618
int main(int argc, char *argv[]) {
  const CTest tst{"name"};

  CTest tst2 = tst;
  std::cout << "--------------"
            << "\n";
  CTest tst3 = func(std::move(tst2));
  std::cout << "--------------"
            << "\n";
  CTest tst4;
  tst4 = func2();
  return 0;
}
