#include <functional>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
// MyClass ==> to use "std::function"
template <typename T>
class MyClass
{
private:
    T val_;

public:
    MyClass(T n){};
    ~MyClass(){};
    void operator()()
    {
        cout << "call operator()" << endl;
    }

    //**********************************************************************
    // universal reference
    //**********************************************************************
    template <typename U>
    void Init(U &&val)
    {
        cout << "decltype: " << typeid(val).name() << endl;
        val_ = val;
    }
    friend ostream &operator<<(ostream &ost, const MyClass &c)
    {
        ost << c.val_;
        return ost;
    }
};
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************

int main(int argc, char const *argv[])
{
    // lvalue<int>
    {
        int val = 10;
        MyClass c{val};
        c.Init(val);
        cout << "(int): " << c << endl;
    }

    // lvalue <string>
    {
        string val{"test string"};
        MyClass c{val};
        c.Init(val);
        cout << "(string): " << c << endl;
    }

    // rvalue <string>
    {
        MyClass c{string{"test string"}};
        c.Init("text");
        cout << "(string): " << c << endl;
    }
    return 0;
}