#include <iostream>

using namespace std;

template <typename X, typename Y, typename Z>
struct three_types
{
public:
    three_types(X x, Y y, Z z) : _x(x), _y(y), _z(z){};
    ~three_types(){};

    void output()
    {
        cout << _x << endl;
        cout << _y << endl;
        cout << _z << endl;
    }

private:
    const X _x;
    const Y _y;
    const Z _z;
};

template <typename X, typename Z>
struct three_types<X, void, Z>
{
public:
    three_types(X x, Z z) : _x(x), _z(z){};
    ~three_types(){};

    void output()
    {
        cout << _x << endl;
        cout << "default" << endl;
        cout << _z << endl;
    }

private:
    const X _x;
    const Z _z;
};

template <typename X, typename Z>
using partial_three_types = three_types<X, void, Z>;

int main(int argc, char const *argv[])
{
    three_types<int, float, string> tt0(1, 2.1, "test");
    tt0.output();

    three_types<int, void, string> tt1(1, "test");
    tt1.output();

    partial_three_types<string, string> tt2("first", "third");
    tt2.output();

    return 0;
}
