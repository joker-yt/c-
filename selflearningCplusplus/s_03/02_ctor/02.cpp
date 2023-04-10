#include <iostream>
#include <string>

using namespace std;

class MyClass
{
public:
    explicit MyClass();
    explicit MyClass(int x) : val_(x)
    {
        cout << "with arg ctor" << endl;
    }
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) = default;
    MyClass &operator=(MyClass &&) = default;
    MyClass &operator=(const MyClass &) = default;
    ~MyClass();

    void set(int x)
    {
        val_ = x;
        cout << __FUNCTION__ << " val: " << val_ << endl;
    }

    void show() const
    {
        cout << __FUNCTION__ << " val: " << val_ << endl;
        cout << __FUNCTION__ << " str: " << str_ << endl;
    }

private:
    int val_ = 10;
    string str_{"default"};
};

MyClass::MyClass()
{
    cout << "non with ctor" << endl;
}

MyClass::~MyClass()
{
    cout << "dtor" << endl;
}

int main(int argc, const char **argv)
{
    {
        MyClass cl; // NSDMI
        cl.show();
    }
    cout << "------------------" << endl;
    {
        MyClass cl{100}; // initializer list
        cl.show();
    }
    return 0;
}