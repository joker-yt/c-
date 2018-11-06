#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

/*! void func1()
 * @brief brief comment
 * @detail detail comment
 */
void func1() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  std::string str{"reference"};

  for_each(v.begin(), v.end(),
           [=](int n) { std::cout << str << ":" << n << std::endl; });
}
/*! void func2()
 * @brief brief comment
 * @detail detail comment
 */
void func2() {
  std::string ref{"reference"};
  std::function<std::string(int)> f_lambda = [=](int n) {
    return std::to_string(n);
  };

  std::string ret{"f_lambda returns -> "};
  ret += f_lambda(10);
  std::cout << ret << std::endl;
}

/*! void func3()
 * @brief brief comment
 * @detail detail comment
 */
struct Obj {
  std::string operator()(int n) { return std::to_string(n); }
};
void func3() {
  std::function<std::string(int)> f_lambda = Obj();
  std::string ret = f_lambda(20);
  std::cout << "f_lambda returns -> " << ret << std::endl;
}

/*! void main()
 * @brief brief comment
 * @detail detail comment
 */
int main(int argc, char const *argv[]) {
  std::cout << "-------------------" << std::endl;
  func1();
  std::cout << "-------------------" << std::endl;
  func2();
  std::cout << "-------------------" << std::endl;
  func3();
  std::cout << "-------------------" << std::endl;

  return 0;
}
