#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
template <typename T>
class MyClass
{
public:
    using Func = void (*)(T val);
    MyClass() {}
    ~MyClass() {}
    void Init(Func f) { func_ = f; }
    void call(T val)
    {
        cout << "call" << endl;
        func_(val);
    }

private:
    Func func_;
};

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
class interface_from
{
public:
    interface_from(){};
    virtual ~interface_from(){};
    virtual void method(){};
};

class from : public interface_from
{
private:
public:
    from(){};
    ~from(){};
    void method(void)
    {
        cout << "from::method" << endl;
    }
};

class to
{
private:
    function<void(void)> f_;

public:
    to(){};
    ~to(){};
    void Init(function<void(void)> f) { f_ = f; }
    void call(void)
    {
        cout << "to::call" << endl;
        f_();
    }
};

class to2
{
private:
    interface_from dummy_;
    reference_wrapper<interface_from> itf_{dummy_};

public:
    to2(){};
    ~to2(){};
    void Init(reference_wrapper<interface_from> itf)
    {
        itf_ = itf.get();
    }
    // void Init(reference_wrapper<function<void(void)>> f) { if_ = f.get(); }
    void call(void)
    {
        cout << "to2::call" << endl;
        itf_.get().method();
    }
};
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************

int main(int argc, char const *argv[])
{
    int m = 10;
    int &x = m;
    reference_wrapper<int> wrap = ref(x);
    cout << wrap.get() << endl;

    auto r = wrap;
    cout << typeid(r).name() << endl;
    cout << typeid(x).name() << endl;

    // array<reference_wrapper<string>, 3> ar;
    string str1{"Bob"};
    string str2{"Kate"};
    string str3{"Mike"};

    // vector is OK, array is NG -> use "reference_wrapper<T> arr[]", if array is needed.
    vector<reference_wrapper<string>> v;
    v.emplace_back(ref(str1));
    v.emplace_back(ref(str2));
    v.emplace_back(ref(str3));
    // ar[0] = ref(str1);
    // ar[1] = ref(str2);
    // ar[2] = ref(str3);

    // for (auto x : ar)
    // {
    //     cout << x.get() << endl;
    // }
    for (auto x : v)
    {
        cout << x.get() << endl;
    }

    //**********************************************************************
    //**********************************************************************
    MyClass<int> cl;
    cl.Init([](int) -> void
            { cout << "lambda" << endl; });
    cl.call(100);
    //**********************************************************************
    //**********************************************************************
    from fm;
    to to;
    to.Init([&fm](void)
            { fm.method(); });

    to.call();

    to2 to2;
    to2.Init(ref(fm));
    to2.call();

    return 0;
}
