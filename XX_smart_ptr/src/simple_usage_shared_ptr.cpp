#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

template <typename T>
T templ_func(T x)
{
    shared_ptr<T> p = make_shared<T>(x);
    cout << *p << endl;

    {
        shared_ptr<T> q;
        q = p;

        cout << *q << endl;

        cout << std::hex << p << endl;
        cout << std::hex << q << endl;

        cout << p.use_count() << endl;

        if (p.unique())
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    if (p.unique())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return *p;
}

int main(int argc, char const *argv[])
{
    cout << templ_func(1) << endl;

    return 0;
}
