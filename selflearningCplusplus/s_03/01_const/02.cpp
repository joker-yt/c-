#include <iostream>

using namespace std;

class MyClass
{
public:
    void show() const
    {
        cout << "const " << __FUNCTION__ << " : " << a_ << endl;
        a_ = 3;
        cout << __FUNCTION__ << " : " << a_ << endl;
    }

    void show()
    {
        cout << "non-const " << __FUNCTION__ << " : " << a_ << endl;
    }

    void non_const_change_member(int d)
    {
        cout << "const " << __FUNCTION__ << " : " << d << endl;
        a_ = d;
    }

private:
    static int a_;
};

int MyClass::a_ = 5;

int main(int argc, char const *argv[])
{
    {
        const MyClass cl;
        cl.show();
        // cl.non_const_change_member(10); // compile error!
    }
    {
        MyClass cl;
        cl.show();
        cl.non_const_change_member(10);
    }

    return 0;
}
