#include <algorithm>
#include <array>
#include <iostream>
#include <span>
#include <vector>

using namespace std;

//**********************************************************************
//**********************************************************************
void handle_buffer(unsigned char *p, size_t size)
{
    span<unsigned char> sp = span{p, size};

    cout << "size is: " << sp.size() << endl;
    for_each(sp.begin(), sp.end(), [](auto x)
             { cout << x << endl; });
}

//**********************************************************************
//**********************************************************************
int main(int argc, char const *argv[])
{
    //**********************************************************************
    //**********************************************************************
    // basic. std::array -> span && subspan
    array<int, 10> ar;
    for_each(ar.begin(), ar.end(), [](int &x)
             { static int i = 0;
             x = i++;
             cout << "[" << x<< "]: " << &x  << endl; });
    cout << "ar: ";
    for_each(ar.begin(), ar.end(), [=](int x)
             { cout << x << ", "; });

    cout << endl;
    span sp = span{ar}.subspan(3, 4);
    cout << "span: ";
    for_each(sp.begin(), sp.end(), [=](int x)
             { cout << x << ", "; });
    cout << endl;
    cout << "size: " << sp.size() << endl;
    cout << "size_bytes: " << sp.size_bytes() << endl;

    //**********************************************************************
    //**********************************************************************
    // first
    span<int, dynamic_extent> s_f = sp.first(2);
    cout << "span.first(2): ";
    for_each(s_f.begin(), s_f.end(), [=](int &x)
             { cout << x << ", "; 
              cout << "[" << x<< "]: " << &x  << endl; });
    cout << endl;

    span<int, dynamic_extent> s_l = sp.last(2);
    cout << "span.last(2): ";
    for_each(s_l.begin(), s_l.end(), [=](int x)
             { cout << x << ", "; });
    cout << endl;

    vector<int> v{1, 2, 3, 4, 5, 6};
    // dynamic_extent is mandatory as template argument.
    span<int, dynamic_extent> s2 = span{v}.subspan(1, 2);

    //**********************************************************************
    //**********************************************************************
    // pointer of primitive type (unsigned char*) into span
    unsigned char buffer[] = {"buffer"};
    handle_buffer(buffer, sizeof(buffer));
    handle_buffer(buffer, 3);

    return 0;
}
