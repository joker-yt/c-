#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

int x = 0;
void output_x(string funcname) { cout << funcname << " : " << x << endl; }

//#############################################################
// test1
// simple thread. as parameter, passes lambda
//#############################################################
void test1() {
  string str{"test string"};
  thread t([&] {
    x++;
    output_x(__FUNCTION__);
    cout << __FUNCTION__ << "[message] -> " << str << endl;
  });

  thread::id tid = t.get_id();
  cout << __FUNCTION__ << ": child thread_id: " << tid << endl;

  t.join();
  cout << __FUNCTION__ << " comment after join" << endl;
}

//#############################################################
// test2
// simple thread. as parameter, passes  class for thread
//#############################################################
class C_test2 {
private:
  /* data */
public:
  C_test2(){};
  virtual ~C_test2(){};
  void operator()() { cout << "this is C_test2 operator()." << endl; };
};

void test2() {
  C_test2 cl;
  thread t(cl);

  t.join();
  cout << __FUNCTION__ << " comment after join" << endl;
}

//#############################################################
// test3
// using mutex
//#############################################################
mutex mtx_t3;

class C_test3 {
public:
  C_test3() {
    cout << __FUNCTION__ << "[" << _n << "]"
         << ": constructor" << endl;
  };
  C_test3(int n) : _n(n) {
    cout << __FUNCTION__ << "[" << _n << "]"
         << ": constructor(param)" << endl;
  };
  ~C_test3() {
    cout << __FUNCTION__ << "[" << _n << "]"
         << ": destructor" << endl;
  };
  C_test3(const C_test3 &other) {
    cout << __FUNCTION__ << "[" << _n << "]"
         << ":copy constructor" << endl;
    // *this = other;
  };
  C_test3 &operator=(const C_test3 &other) {
    cout << __FUNCTION__ << "[" << _n << "]"
         << ":assignment operator" << endl;
  }
  void operator()() {
    mtx_t3.lock();
    cout << __FUNCTION__ << "[" << _n << "]" << this_thread::get_id() << endl;
    mtx_t3.unlock();
  };

private:
  int _n = 0;
};

void func1_t3(int n) {
  mtx_t3.lock();
  cout << __FUNCTION__ << "[" << n << "]" << this_thread::get_id() << endl;
  mtx_t3.unlock();
}

void func2_t3(int n) {
  lock_guard<mutex> lock(mtx_t3);
  cout << __FUNCTION__ << "[" << n << "]" << this_thread::get_id() << endl;
}

void test3() {
  cout << __FUNCTION__ << "construct vectors start" << endl;
  vector<thread> v_thread(4);
  cout << __FUNCTION__ << "construct vectors end" << endl;
  int i = 1;

#if 0 // pattern1: passes class object to thread
  for (auto &th : v_thread) {
    C_test3 cl(i++);
    th = thread(cl);
  }
#endif

#if 0 // pattern2: passes func pointer to thread
  for(auto &th : v_thread)
  th = thread(func1_t3, i++);
#endif

#if 1 // pattern3: passes func pointer which is using
  // lock_guard in it
  for (auto &th : v_thread)
    th = thread(func2_t3, i++);
#endif

  for (auto &th : v_thread) {
    th.join();
  }
}

//#############################################################
// main
//#############################################################
int main(int argc, char *argv[]) {
  cout << "start" << endl;

  test1();
  cout << "--------------------------" << endl;
  test2();
  cout << "--------------------------" << endl;
  test3();
  return 0;
}
