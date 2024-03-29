
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
T templ_func(T x)
{
    // basic usage
    // x = size of area
    std::unique_ptr<T> p = make_unique<T>(x);
    cout << *p << endl;

    // "move"
    // unique_ptr can not be copied, so that move is used to forward the ownership.
    std::unique_ptr<T> q = std::move(p);
    cout << *q << endl;

    // return false if it doesn't have ownership.
    const string s = p ? "true" : "false";
    cout << s << endl;
    p.reset(new T(x + 20));
    cout << *p << endl;

    return *p;
}

int main(int argc, char const *argv[])
{
    cout << templ_func<int>(1) << endl;
    return 0;
}
