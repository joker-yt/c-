#include <iostream>

using namespace std;

class Base
{
public:
    virtual void func()
    {
        cout << "Base::" << __FUNCTION__ << endl;
    }
};

class Derive : public Base
{
public:
    void func() override
    {
        cout << "Derive::" << __FUNCTION__ << endl;
    }
    void func(int i)
    {
        cout << "Derive::" << __FUNCTION__ << " with arg" << endl;
    }
};

int main(int argc, const char **argv)
{
    Derive cl;

    cl.func();
    cl.func(5); // overload

    return 0;
}