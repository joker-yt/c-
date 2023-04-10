#include <iostream>

using namespace std;

class Base
{
public:
    void func()
    {
        cout << "Base::" << __FUNCTION__ << endl;
    }
};

class Derive : public Base
{
public:
    using Base::func;

    void func(int i)
    {
        cout << "Derive::" << __FUNCTION__ << " with arg" << endl;
    }
};

int main(int argc, const char **argv)
{
    Derive cl;

    cl.func(5); // overload
    cl.func();  // name hiking. resolved by "using" directive.

    return 0;
}