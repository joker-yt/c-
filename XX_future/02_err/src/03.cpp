#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

// std::future_errc
using namespace std;

void th_func(std::promise<int> &p)
{
    sleep(3);
    cout << "value was set" << endl;
    p.set_value(5);
    // cout << "value was set2" << endl;
    // p.set_value(10);
    cout << "thread was finished" << endl;
    return;
}
int main(int argc, const char **argv)
{
    try
    {
        std::future<int> f, f2;
        std::promise<int> p, p2;
        f = p.get_future();
        f2 = p.get_future();
        thread th(th_func, ref(p));

        cout << "1" << endl;
        int ret_val1 = f.get();

        sleep(3);
        cout << "value is:" << ret_val1 << endl;

        // int ret_val2 = f.get();
        // cout << ret_val2 << endl;

        th.join();
    }
    catch (std::future_error &e)
    {
        if (e.code() == std::make_error_condition(std::future_errc::future_already_retrieved))
            std::cerr << e.code().message() << endl; // "Future already retrieved"
        else
            std::cerr << e.code().message() << endl;
    }

    return 0;
}
