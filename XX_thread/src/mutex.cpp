#include <thread>
#include <unistd.h>
#include <iostream>
#include <mutex>

using namespace std;
mutex _mtx;

int main(int argc, char *argv[]) {

  int x = 0;
  thread t([&] {
    {
      lock_guard<mutex> lock(_mtx);
      x++;
      cout << "thread: " << x << endl;
    }
    sleep(3);
    {
      lock_guard<mutex> lock(_mtx);
      x++;
      cout << "thread: " << x << endl;
    }
  });

  {
    sleep(1);
    lock_guard<mutex> lock(_mtx);
    x++;
    cout << "main: " << x << endl;
  }

  t.join();
  return 0;
}
