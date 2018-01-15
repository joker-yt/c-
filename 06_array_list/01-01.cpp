#include <list>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <type T> void func() {}

int main(int argc, char *argv[]) {
  std::list<string> lt = {"name1", "name2"};

  size_t sz;
  bool bl;

  sz = lt.size();
  bl = lt.empty();
  string answer;

  // Initial data
  cout << "size: " << sz << endl;
  answer = bl == true ? "true" : "false";
  cout << "empty?: " << answer << endl;

  // remove entry
  string st = lt.front();
  cout << "head: " << st << endl;
  lt.pop_front();
  st = lt.front();
  cout << "head: " << st << endl;
  lt.pop_front();
  bl = lt.empty();
  answer = bl == true ? "true" : "false";
  cout << "empty?: " << answer << endl;
  sz = lt.size();
  cout << "size: " << sz << endl;

  // swap
  std::list<string> lt2 = {"name3", "name4"};
  lt.swap(lt2);
  for (auto it = lt.begin(); it != lt.end(); ++it) {
    cout << "str:" << *it << endl;
  }

  // lt2 after swapping?
  bl = lt2.empty();
  answer = bl == true ? "true" : "false";
  cout << "lt2 is empty?: " << answer << endl;

  return 0;
}
