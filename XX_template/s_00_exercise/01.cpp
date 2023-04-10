#include <iostream>
#include <optional>
#include <utility>

using namespace std;

///////////// function template
template <typename T>
T func_template(T x, T y)
{
    return x + y;
}

///////////// class template
template <class T>
class MyClass
{
    T *data_;
    optional<int> idx_;
    void mypush(T x)
    {
        idx_ == nullopt ? idx_ = 0 : idx++;
        T *p = new T;
        *p = x;
        data_[idx_] = move(p);
    };
    T mypop()
    {
        T tmp = move(data_[idx_]);
    }
};

int main(int argc, const char **argv)
{
    cout << func_template<int>(1, 2) << endl;

    return 0;
}