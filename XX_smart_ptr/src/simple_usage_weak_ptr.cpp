
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
T templ_func(T x)
{
    std::shared_ptr<T> p0 = make_shared<T>(x);
    std::weak_ptr<T> p = p0;

    if (p.expired())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    p0.reset();
    if (p.expired())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return x;
}

int main(int argc, char const *argv[])
{
    cout << templ_func<int>(1) << endl;
    return 0;
}
