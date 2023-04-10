#include <functional>
#include <iostream>

using namespace std;

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
// MyClass1 ==> to use "std::function"
class MyClass
{
private:
    function<void(void)> fn_;
    void (*f_)(void);

public:
    MyClass(){};
    ~MyClass(){};
    void operator()()
    {
        cout << "call operator()" << endl;
        f_();
        // fn_();
    }
    void Init(function<void(void)> &f)
    {
        fn_ = f;
    }
    void Init(function<void(void)> &&f)
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
    MyClass c;
    // =====
    // function + lvalue::lambda
    // =====
    std::function<void(void)> f = []()
    {
        cout << "lvalue::lambda" << endl;
    };

    c.Init(f);
    // =====
    // function + rvalue::lambda
    // =====
    c.Init([=]()
           { cout << "rvalue::lambda" << endl; });

    // =====
    // function pointer + rvalue::lambda --> compile ok ()
    // function pointer + rvalue::lambda(with capture) --> compile error
    // =====
    c.Init2([]()
            { cout << "lambda" << endl; });
    // c.Init2([=]()
    //         { cout << "lambda" << endl; });

    return 0;
}
