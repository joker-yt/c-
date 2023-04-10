#include <iostream>

using namespace std;

class MyClass
{
public:
    friend void v_func();

private:
    int n_ = 10;
};

// not member function, so no need to add "class name".
void v_func()
{
    MyClass cl;

    // access private member.
    cout << __FUNCTION__ << " " << cl.n_ << endl;
};

int main(int argc, const char **argv)
{

    v_func();

    return 0;
}