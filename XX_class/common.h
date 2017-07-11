#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>

// constructor & destructor
const char strConstructor[] = "constructor";
const char strCopyConstructor[] = "copy constructor";
const char strMoveConstructor[] = "move constructor";
const char strDestructor[] = "destructor";

// operator
const char strAssignmentOperator[] = "assignment operator";
const char strMoveAssignmentOperator[] = "move assignment operator";

class CMyClass {
private:
  std::string _name;

public:
  CMyClass() { std::cout << __FUNCTION__ << "(default) : " << _name << "\n"; };
  CMyClass(std::string name) : _name(name) {
    std::cout << __FUNCTION__ << "(default with param) : " << _name << "\n";
  };
  CMyClass(const CMyClass &tst) : _name(tst._name) {
    std::cout << __FUNCTION__ << "(copy) : " << _name << "\n";
  };
  CMyClass(CMyClass &&tst) : _name(tst._name) {
    tst._name = "";
    std::cout << __FUNCTION__ << "(move) : " << _name << "\n";
  }
  virtual ~CMyClass() { std::cout << __FUNCTION__ << " : " << _name << "\n"; };
  CMyClass &operator=(const CMyClass &tst) {
    std::cout << __FUNCTION__ << "(operator=copy) : " << _name << "\n";
    return *this;
  }
  CMyClass &operator=(CMyClass &&tst) {
    std::cout << __FUNCTION__ << "(operator=move) : " << _name << "\n";
    return *this;
  }
  void WhatsYouName() { std::cout << __FUNCTION__ << " : " << _name << "\n"; }
};

#endif /* end of include guard: __COMMON_H__ */
