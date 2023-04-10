#include <iostream>
#include <utility>

using namespace std;

int func(int &i)
{
    cout << "lvalue reference" << endl;
}

int func(int &&i)
{
    cout << "rvalue reference" << endl;
}
int main(int argc, const char **argv)
{
    int i = 5;
    func(i);  // copy
    func(42); // temporary object will be created.

    // how about using "move"?
    func(move(i)); // cast to xvalue

    return 0;
}

#if 0 // 
lvalue reference
rvalue reference
rvalue reference
#endif