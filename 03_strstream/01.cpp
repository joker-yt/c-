#include <fstream>

int main(int argc, char const *argv[]) {
  std::ofstream ofs("test.dt",
                    std::ios::out | std::ios::binary | std::ios::ate);

  char buf[32] = {"this is a test"};
  size_t sz = sizeof(buf);

  ofs.write((char *)buf, sz);

  ofs.close();
  return 0;
}
