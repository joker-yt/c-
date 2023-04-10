#include <iostream>

using namespace std;

template <typename T>
class TemplClass
{
public:
    TemplClass(T x, T y) : _x(x), _y(y){};
    ~TemplClass(){};

    T const
    show_x() const { return _x; };
    T const show_y() const { return _y; };

    const T _x;
    const T _y;
};

int main(int argc, char const *argv[])
{
    TemplClass<int> cl(1, 2);

    cout << cl.show_x() << endl;
    cout << cl.show_y() << endl;

    return 0;
}
