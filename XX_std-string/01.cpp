#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define __PATTERN12__

// ---------------------------------------------------
void func1_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "(1)Enter the message:" << std::endl;

  std::string str;
  std::cin >> str;

  std::cout << "your message is : " << str << std::endl;
}
// ---------------------------------------------------
void func1_2() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "(2)Enter the message:" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  std::cout << "your message is : " << str << std::endl;
}
// ---------------------------------------------------
void func1_3() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "(3)Enter the message:" << std::endl;
  char buf[64] = {0};
  std::cin.getline(buf, sizeof(buf));
  std::cout << "your message is : " << buf << std::endl;
}
//====================================================
void func2_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "(1)Enter the message with two of ',':" << std::endl;
  char buf[64] = {0};
  std::cin.getline(buf, sizeof(buf));
  char *p = strtok(buf, ",");
  std::cout << "first word : " << p << std::endl;
  p = strtok(NULL, ",");
  std::cout << "second word : " << p << std::endl;
  p = strtok(NULL, ",");
  std::cout << "third word : " << p << std::endl;
}
//====================================================
void func3_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "search 'c' from :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  std::vector<int>::size_type n = str.find_first_of('c', 0);
  std::cout << "Offset : " << n << std::endl;
}
//====================================================
void func4_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "search \"abc\" from :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  auto n = str.find("abc", 0);
  std::cout << "Offset : " << n << std::endl;
}
//====================================================
void func5_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "Enter the message without \"abc\" :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  if (std::string::npos == str.find("abc", 0)) {
    std::cout << "can't find \"abc\"!" << std::endl;
  }
}
//====================================================
void func6_1() {
  std::string str = "this is test string";
  std::cout << "[" << __FUNCTION__ << "]"
            << "string -> " << str << "\n";

  char buf[32] = {0};
  const size_t len{4}, ofst{8};
  str.copy(buf, len, ofst);

  std::cout << "char is :" << buf << "\n";
}
//====================================================
void func7_1() {
  std::string str = "this is test string";
  std::cout << "[" << __FUNCTION__ << "]"
            << "string -> " << str << "\n";

  const char buf[] = "TEST";
  const size_t len{4};
  str.replace(str.find("test"), len, buf);
  std::cout << "replaced string is :" << str << "\n";
}
//====================================================
void func8_1() {
  const std::string str = "123";
  std::cout << "[" << __FUNCTION__ << "]"
            << "string -> " << str << "\n";
  const int n = std::stoi(str);

  std::cout << n << "\n";
}
//====================================================
void func9_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "\n";
  const char *char1 = "char1";
  const char *char2 = "&";
  const char *char3 = "char2";

  std::string str;
  str.append(char1);
  str.append(char2);
  str.append(char3);

  std::cout << "string is -> :" << str << "\n";
}
//====================================================
void func10_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "\n";
  std::string str = "this is test string";

  const size_t ofst{4};
  std::string out = str.substr(str.find("test"), ofst);
  std::cout << out << "\n";
}
//====================================================
void func11_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "\n";

  std::string str = "this q is 1";
  const int n = 11;
  str += std::to_string(n);
  std::cout << str << "\n";
}
//====================================================
void compare_result_is(int result_val) {
  if (result_val == 0) {
    // maybe don't reach at this branch
    std::cout << "same!"
              << "\n";
  } else if (result_val < 0) {
    std::cout << "NOT same!(short!)"
              << "\n";
  } else if (result_val > 0) {
    // maybe don't reach at this branch
    std::cout << "NOT same!(long!)"
              << "\n";
  } else {
    // maybe don't reach at this branch
  }
}
void func12_1() {
  std::cout << "[" << __FUNCTION__ << "]"
            << "\n";

  const std::string str1{"base1"};
  const std::string str2{"base2"};
  const std::string str3{"base0"};
  std::string str4 = str1;

  int result = str1.compare(str2);

  result = str1.compare(str3);
  compare_result_is(result);

  result = str1.compare(str4);
  compare_result_is(result);
}
//====================================================
int main(int argc, char const *argv[]) {
// patter 1
#ifdef __PATTERN1__
  func1_1();
  func1_2();
  func1_3();
#endif

#ifdef __PATTERN2__
  func2_1();
#endif

#ifdef __PATTERN3__
  func3_1();
#endif

#ifdef __PATTERN4__
  func4_1();
#endif

#ifdef __PATTERN5__
  func5_1();
#endif

#ifdef __PATTERN6__
  func6_1();
#endif

#ifdef __PATTERN7__
  func7_1();
#endif

#ifdef __PATTERN8__
  func8_1();
#endif

#ifdef __PATTERN9__
  func9_1();
#endif

#ifdef __PATTERN10__
  func10_1();
#endif

#ifdef __PATTERN11__
  func11_1();
#endif

#ifdef __PATTERN12__
  func12_1();
#endif
  return 0;
}
