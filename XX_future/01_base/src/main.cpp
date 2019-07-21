#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

using namespace std;

void th_func(std::promise<int> &p, int x)
{
  int rslt = x + 1;
  std::cout << __FUNCTION__ << "result: " << rslt << " was set." << std::endl;

  p.set_value(rslt);
}

int main(int argc, char *argv[])
{
  cout << __FUNCTION__ << " starts" << endl;

  std::promise<int> p;
  std::future<int> f = p.get_future();

  int x = 0;

  thread th(th_func, ref(p), x);

  cout << __FUNCTION__ << " f.get() --> " << f.get() << endl; // f.get() is waiting for p.set_value().
  cout << __FUNCTION__ << " ends" << endl;

  th.join();

  return 0;
}
