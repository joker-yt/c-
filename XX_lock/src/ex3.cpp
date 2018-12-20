#include <condition_variable>
#include <iostream>
#include <mutex>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>

using namespace std;

mutex mtx;
condition_variable cv;
int sig_no = 0;
bool is_ready = false;

int check_value = 0;
//////////////////////////////////////
// T1
//////////////////////////////////////
void T1() {
  cout << "T1: launched." << endl;

  ///////////////////
  //!!!!!! custom to this example
  sleep(2);
  {
    unique_lock<mutex> lk{mtx};
    cout << __FUNCTION__ << ":get lock" << endl;
    cv.wait(lk, [] { return is_ready; });
  }

  cout << "T1: just before check." << endl;
  if (check_value == 1) {
    cout << "T1: main has been ready, and work will start correctly." << endl;
  } else {
    cout << "T1: main has been not ready yet!!! work failed to start!!!"
         << endl;
  }
  cout << "T1: just after check." << endl;
}

//////////////////////////////////////
// main
//////////////////////////////////////
int main(int argc, char *argv[]) {

  thread t1(T1);

  {
    lock_guard<mutex> lk{mtx};
    is_ready = true;
    check_value = 1;
    cv.notify_all();
  }

  cout << __FUNCTION__ << "main is ready. notified" << endl;
  t1.join();

  return 0;
}
