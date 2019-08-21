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
        std::promise<int> p;
        f = p.get_future();

        ///////////////// p has already retrieved to "f"
        std::future<int> f_err;
        f_err = p.get_future();

        // doesn't reach here...
        thread th([&p] {
            p.set_value(5);
        });

        int ret_val = f.get();

        cout << "value is:" << ret_val << endl;

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
