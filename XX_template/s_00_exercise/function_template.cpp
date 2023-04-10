#include <iostream>

using namespace std;

template <typename T>
T f(T x, T y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    cout << f<int>(1, 2) << endl;

    return 0;
}
