#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass();
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
    }

private:
    int val_;
};

MyClass::MyClass()
{
    cout << "non with ctor" << endl;
}

MyClass::~MyClass()
{
    cout << "dtor" << endl;
}

////////////////////
class MyClass_inc_const
{
public:
    // return value must be defined as "const" (at the head of definition).
    // the reason why to do so is that it refers to const value.
    const int &ref_n() const
    {
        return n_;
    }

private:
    // const value
    const int n_ = 10;
};

int main(int argc, char const *argv[])
{
    // const MyClass cl = 5; // compile error because of "explicit"
    {
        const MyClass cl{5};
    }
    {
        MyClass_inc_const cl;
        const int n = cl.ref_n();
        cout << n << endl;
    }
    return 0;
}
