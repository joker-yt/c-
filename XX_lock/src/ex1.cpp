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

int check_value = 0;
//////////////////////////////////////
// T1
//////////////////////////////////////
void T1() {
  cout << "T1: launched." << endl;

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

  ///////////////////
  //!!!!!! custom to this example
  sleep(2);
  check_value = 1;

  cout << __FUNCTION__ << "main is ready. notified" << endl;
  t1.join();

  return 0;
}
