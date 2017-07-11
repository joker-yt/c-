#ifndef __01_H__
#define __01_H__

#include "common.h"
#include <iostream>

class CTest {
private:
  /* data */
public:
  CTest() { std::cout << strConstructor << std::endl; };
  // copy construcor(parameter needs "const")
  CTest(const CTest &tst) { std::cout << strCopyConstructor << std::endl; };
  // move constructor(parameter doesn't need "const")
  CTest(CTest &&tst) {
    std::cout << strMoveConstructor << std::endl;
    *this = std::move(tst);
  };
  virtual ~CTest() { std::cout << strDestructor << std::endl; };

  // copy assignment
  CTest &operator=(const CTest &obj) {
    std::cout << strAssignmentOperator << std::endl;
    CTest temp = obj;
    return *this = std::move(temp);
  }
  // move assignment
  CTest &operator=(CTest &&) = default;
};

#endif /* end of include guard: __01_H__ */
