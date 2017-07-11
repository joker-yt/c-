#include "common.h"

CMyClass func() {
  std::cout << __FUNCTION__ << "\n";
  CMyClass temp("temp");
  return temp;
}

CMyClass func2(CMyClass tst) {
  std::cout << __FUNCTION__ << "\n";
  return tst;
}

CMyClass func3() { return CMyClass{"JILL"}; }

int main(int argc, char const *argv[]) {
  const CMyClass tst1{"name"};
  std::cout << "--------------"
            << "\n";

  CMyClass tst2;
  tst2 = func();

  std::cout << "--------------"
            << "\n";

  CMyClass tst3;
  tst3 = tst1;
  CMyClass tst4 = func2(std::move(tst3));

  std::cout << "--------------"
            << "\n";

  return 0;
}
