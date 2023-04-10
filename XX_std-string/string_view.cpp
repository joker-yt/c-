#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class MyString
{
public:
    MyString(st ring str) : sv_(str) {}
    ~MyString() {}
    string_view sv_;
    void print()
    {
        for (auto x : sv_)
        {
            cout << x << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    {
        MyString ms{"test string"};
        ms.print();
    }

    return 0;
}
