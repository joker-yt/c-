#include <iostream>
#include <typeinfo>

using namespace std;

class MyClass
{
public:
    MyClass() = default;
    ~MyClass() = default;
};

template <int i>
void f()
{
    cout << typeid(i).name() << endl;
    return;
}

int main(int argc, char const *argv[])
{
    f<0>();

    int n;
    float f;
    MyClass cl;
    cout << typeid(n).name() << endl;
    cout << typeid(f).name() << endl;
    cout << typeid(cl).name() << endl;
    return 0;
}
