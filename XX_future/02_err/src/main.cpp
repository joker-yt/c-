#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

// std::future_errc
using namespace std;

int main(int argc, const char **argv)
{
  try
  {
    std::future<int> f;
    {
      std::promise<int> p;
      f = p.get_future();
    }

    // normally, you should create thread to pass "p" and to set value for "p" here.

    cout << f.get() << endl;
  }
  catch (std::future_error &e)
  {
    if (e.code() == std::make_error_condition(std::future_errc::broken_promise))
      std::cerr << e.code().message() << endl; // "Broken promise"
    else
      std::cerr << e.code().message() << endl;
  }

  return 0;
}
