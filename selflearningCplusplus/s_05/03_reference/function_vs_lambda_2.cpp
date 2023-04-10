#include <functional>
#include <iostream>

using namespace std;

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
// MyClass1 ==> to use "std::function"
template <typename T>
class MyClass
{
private:
    T fn_;
    void (*f_)(void);

public:
    MyClass(){};
    ~MyClass(){};
    void operator()()
    {
        cout << "call operator()" << endl;
        fn_();
        // f_();
    }
    ////////////////////////////////////////////////////////////////////
    // definition for rvalue and lvalue are put together.
    ////////////////////////////////////////////////////////////////////
    void Init(T &&f)
    {
        fn_ = f;
    }
    void Init2(void (*f)(void))
    {
        f_ = f;
    }
};
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************

int main(int argc, char const *argv[])
{
    MyClass<function<void(void)>> c;
    // =====
    function<void(void)> f = []()
    {
        cout << "lvalue::lambda" << endl;
    };
    c.Init(ref(f));
    c();

    function<void(void)> f2 = []()
    {
        cout << "lvalue::lambda" << endl;
    };
    c.Init(move(f2));
    c();

    c.Init([]()
           { cout << "rvalue::lambda" << endl; });
    c();

    return 0;
}