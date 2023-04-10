#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void func01()
{
  // append even if the position is at anywhere.
  ofstream ofs("openfile.txt", ios::app);

  string str{"write"};
  ofs.write(str.c_str(), str.length());
  ofs.close();
}

void func02()
{
  // trunc + io = over write
  ofstream ofs("openfile.txt", ios::ate | ios::in);

  string str{"write"};
  ofs.seekp(5);
  ofs.write(str.c_str(), str.length());
  ofs.close();
}

void func03()
{
  ifstream ifs("openfile.txt", ios::in | ios::binary);
  ifs.seekg(0, ios::end);
  cout << ifs.tellg() << endl;
}

int main(int argc, char const *argv[])
{
  std::ofstream ofs("test.dt",
                    std::ios::out | std::ios::binary | std::ios::ate);

  char buf[32] = {"this is a test"};
  size_t sz = sizeof(buf);

  ofs.write((char *)buf, sz);

  ofs.close();

  // func01();
  // func02();
  func03();
  return 0;
}
