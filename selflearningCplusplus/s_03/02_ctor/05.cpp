#include <iostream>

using namespace std;

class Base
{
public:
    virtual void v_func() = 0;
};

class Derive : public Base
{
public:
    void v_func()
    {
        cout << "Derive::" << __FUNCTION__ << endl;
    }
};

int main(int argc, const char **argv)
{

    // Base cl_b; // compile error!

    Derive cl_d;
    cl_d.v_func();

    return 0;
}