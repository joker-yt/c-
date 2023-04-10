#include <iostream>

using namespace std;

///////////////basic
template <typename T>
size_t ret_size(T in)
{
    cout << "basic <typename T>\n";

    return in.size(); // condition that "T" needs "size()".
}

//// specialized for int
template <>
size_t ret_size<int>(int in)
{
    cout << "<int>\n";

    return 4;
}

//// specialized for char
template <>
size_t ret_size<char>(char in)
{
    cout << "<char>\n";

    return 4;
}

template <typename T>
size_t ret_size_int(int in)
{
    cout << __func__ << "<int>\n";

    return 0;
}

template <int N>
size_t ret_size_int()
{
    cout << __func__ << "<int>\n";

    return 0;
}

template <>
size_t ret_size_int<0>()
{
    cout << __func__ << "<int = 0>\n";

    return 0;
}
// equivalent to <int>
// template <>
// size_t ret_size<const int>(const int in)
// template <>
// size_t ret_size<int &>(int &in)

struct MyStruct1
{
    int n_;
    size_t size() { return sizeof(n_); }
};

int main(int argc, const char **argv)
{
    size_t sz;
    {
        sz = ret_size<MyStruct1>(MyStruct1{5});
        cout << sz << endl;

        sz = ret_size<char>(char{'c'});
    }
    {
        sz = ret_size_int<0>();
    }
    {
        template <int>
        class
        {
        public:
            T var_;
        } cl;
        cl<int>.var_ = 9;
    }
    return 0;
}