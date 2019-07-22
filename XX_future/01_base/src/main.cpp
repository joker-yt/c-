#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

using namespace std;

void th_func(std::promise<int> &p, int x)
{
  int rslt = x + 1;
  cout << "[" << __FUNCTION__ << "]"
       << " changed the value passed as arg " << endl;
  cout << "[" << __FUNCTION__ << "]"
       << " now waiting for the delay time to be expired" << endl;

  // delay...
  for (size_t i = 0; i < 4; i++)
  {
    cout << "." << endl;
    sleep(1);
  }
  p.set_value(rslt);
}

int main(int argc, char *argv[])
{
  cout << __FUNCTION__ << " starts" << endl;

  std::promise<int> p;
  std::future<int> f = p.get_future();

  int x = 0;

  thread th(th_func, ref(p), x);

  cout << "[" << __FUNCTION__ << "]"
       << " calls f.get(), but it's been blocked while sleeing thread..." << endl;

  // actually, blocked here!
  int ret = f.get();
  cout
      << "[" << __FUNCTION__ << "]"
      << " got free from to be blocked. future value is: " << ret << endl;

  cout << "[" << __FUNCTION__ << "]"
       << " ends" << endl;

  th.join();

  return 0;
}
