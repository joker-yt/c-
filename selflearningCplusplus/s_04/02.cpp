#include <iostream>

using namespace std;
namespace n0::n1::n2
{
    class MyClass
    {
    public:
        void method()
        {
            cout << __func__ << endl;
        }
    };
} // namespace n0::n1::n2

int main(int argc, const char **argv)
{
    n0::n1::n2::MyClass cl;

    cl.method();

    return 0;
}