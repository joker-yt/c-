#include <iostream>

using namespace std;

struct MyStruct1
{
    int n_;
    size_t size() { return sizeof(n_); }
};

///////////////basic
template <typename T>
size_t ret_size(T in)
{
    cout << "basic <typename T>\n";

    return in.size(); // condition that "T" needs "size()".
}

template <>
size_t ret_size<int>(int in)
{
    cout << "<int>\n";

    return 4;
}

template <>
size_t ret_size<char>(char in)
{
    cout << "<char>\n";

    return 4;
}

int main(int argc, const char **argv)
{
    size_t sz;
    {
        // basic
        sz = ret_size<MyStruct1>(MyStruct1{5});
        cout << sz << endl;

        sz = ret_size<char>(char{'c'});
    }
    return 0;
}