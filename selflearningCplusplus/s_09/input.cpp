#include <functional>
#include <fstream>
#include <iostream>
#include <string>


class MyInput
{
private:
    function<string(void)> _f;

public:
    MyInput(function<string(void)> func) : _f(func) {}
    ~MyInput() {}
    string read()
    {
        return _f();
    }
};

int main(int argc, char const *argv[])
{
    MyInput input([]() -> string {
        string s;
        std::getline(cin, s);
        return s;
    });
    cout << input.read() << endl;

    MyInput input2([fname = "data.txt"]() -> string {
        static ifstream ifs{fname};
        string s;
        std::getline(ifs, s);
        return s;
    });
    cout << input2.read() << endl;
    return 0;
}

