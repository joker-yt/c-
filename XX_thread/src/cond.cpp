#include <thread>
#include <condition_variable>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

mutex mtx;
condition_variable cond;

struct Obj {
  int _n;
  Obj(){};
  void operator()(int n) {
    unique_lock<mutex> lock(mtx);

    _n = n;
    cout << _n << endl;

    if (_n == 0) {
      sleep(3);
      cond.wait(lock);
      cout << "0: receive unlocked" << endl;
    } else {
      cond.notify_one();
      cout << "1: notified unlocked" << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  struct Obj Obj1, Obj2;
  // unique_lock<mutex> lock(mtx);

  int n = 0;
  thread t1(Obj1, n++);
  thread t2(Obj2, n++);

  t1.join();
  t2.join();

  return 0;
}
