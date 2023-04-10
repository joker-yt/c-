#include <iostream>

using namespace std;

class MyClass
{
public:
    void show() const
    {
        cout << __FUNCTION__ << " : " << a_ << endl;
        a_ = 3;
        cout << __FUNCTION__ << " : " << a_ << endl;
    }

private:
    static int a_;
};

int MyClass::a_ = 5;

int main(int argc, char const *argv[])
{
    MyClass cl;

    cl.show();

    return 0;
}
