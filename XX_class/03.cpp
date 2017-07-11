#include "common.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

// http://qiita.com/go_astrayer/items/5d85565e992487daa618
int main(int argc, char *argv[]) {
  const CMyClass tst{"name"};

  CMyClass tst2 = tst;
  std::cout << "--------------"
            << "\n";
  return 0;
}
