#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <bitset>

using namespace std;

void func01();
void func02();
void func03();

int main(int argc, char *argv[])
{
  std::cout << "-------------------"
            << "\n";
  func01();
  std::cout << "-------------------"
            << "\n";
  func02();
  std::cout << "-------------------"
            << "\n";
  func03();
  std::cout << "-------------------"
            << "\n";
  // static_cast<unsigned char>()なども？？

  return 0;
}

/*! \fn func01
 * @brief brief comment
 * @detail detail comment
 */
void func01()
{
  std::cout << __FUNCTION__ << "\n";
  int n = 0xAF;
  cout << "normal: -> " << n << endl;
  cout << "hex: -> " << std::hex << +n << endl;
}

/*! \fn func02
 * @brief brief comment
 * @detail detail comment
 */
void func02()
{
  int n = 0xAF;
  cout << "bin: -> " << static_cast<std::bitset<8>>(n) << endl;
  std::cout << "---"
            << "\n";

  std::stringstream ss;
  ss << static_cast<std::bitset<8>>(n);
  std::string str = ss.str();
  std::cout << "std::string from binary : " << str << "\n";
}

/*! \fn func03
 * @brief brief comment
 * @detail detail comment
 */
void func03()
{
  {
    for (size_t i = 0; i < 0xFFU; i++)
    {
      cout << std::hex << std::setfill('0') << std::setw(2) << i << " ";
    }
    cout << endl;
  }
  {
    // in case of char or unsigned char, unexpected 'character' apears even if using 'std::hex'.
    // cast must be done.
    unsigned char i = static_cast<unsigned char>(0x00U);
    while (i < 0xFFU)
    {
      cout << std::hex << std::setfill('0') << std::setw(2) << int(i) << " ";
      i = static_cast<unsigned char>(i + 1);
    }
    cout << endl;
  }
}
