#include "common.h"
#include <iostream>
#include <string>
#include <vector>

class CTest {
private:
  const std::string _name;

public:
  CTest() { std::cout << strConstructor << std::endl; };
  CTest(std::string name) : _name(name) {
    std::cout << strConstructor << " with param[" << _name << "]" << std::endl;
  };
  // copy construcor
  CTest(const CTest &tst) { std::cout << strCopyConstructor << std::endl; };
  // move constructor
  CTest(CTest &&tst) noexcept { std::cout << strMoveConstructor << std::endl; };
  virtual ~CTest() { std::cout << strDestructor << std::endl; };

  // copy assignment
  CTest &operator=(const CTest &obj) {
    std::cout << strAssignmentOperator << std::endl;
    CTest temp = obj;
    return *this = std::move(temp);
  }
  // move assignment
  CTest &operator=(CTest &&obj) {
    std::cout << strMoveAssignmentOperator << std::endl;
    return *this;
  };
};

CTest func() {
  std::cout << __FUNCTION__ << " start" << std::endl;
  CTest local{"name local"};
  std::cout << __FUNCTION__ << " end" << std::endl;
  return std::move(local);
}

int main(int argc, char const *argv[]) {
  { CTest tst; }
  std::cout << "-------------" << std::endl;

  { CTest tst{"it's name"}; }
  std::cout << "-------------" << std::endl;

  {
    CTest tst1{"name1"};
    CTest tst2 = tst1;
  }
  std::cout << "-------------" << std::endl;
  {
    std::vector<CTest> v;
    v.push_back(CTest{"name1"});
    v.push_back(CTest{"name2"});
    v.push_back(CTest{"name3"});
  }

  std::cout << "-------------" << std::endl;
  { CTest tst = func(); }
  return 0;
}
