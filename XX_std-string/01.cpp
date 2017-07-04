#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define __PATTERN5__

// ---------------------------------------------------
void func1_1() {
  std::cout << "(1)Enter the message:" << std::endl;

  std::string str;
  std::cin >> str;

  std::cout << "your message is : " << str << std::endl;
}
// ---------------------------------------------------
void func1_2() {
  std::cout << "(2)Enter the message:" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  std::cout << "your message is : " << str << std::endl;
}
// ---------------------------------------------------
void func1_3() {
  std::cout << "(3)Enter the message:" << std::endl;
  char buf[64] = {0};
  std::cin.getline(buf, sizeof(buf));
  std::cout << "your message is : " << buf << std::endl;
}
//====================================================
void func2_1() {
  std::cout << "(1)Enter the message with two of ',':" << std::endl;
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
  std::cout << "search 'c' from :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  std::vector<int>::size_type n = str.find_first_of('c', 0);
  std::cout << "Offset : " << n << std::endl;
}
//====================================================
void func4_1() {
  std::cout << "search \"abc\" from :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  auto n = str.find("abc", 0);
  std::cout << "Offset : " << n << std::endl;
}
//====================================================
void func5_1() {
  std::cout << "Enter the message without \"abc\" :" << std::endl;
  std::string str;
  std::getline(std::cin, str);
  if (std::string::npos == str.find("abc", 0)) {
    std::cout << "can't find \"abc\"!" << std::endl;
  }
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
  return 0;
}
