#include <iostream>
#include <string>

using namespace std;

template <typename T>
T temp(T a)
{
    // output each argument 1 by 1.
    // write code to do something by each argument
    cout << "temp: " << a << endl;
    return a;
}

template <typename... Args>
void multi(Args... args)
{
    // just output combined arguments in line.
    (cout << "multi: " << ... << args) << endl;
}

int main(int argc, char const *argv[])
{

    auto fn = [](auto x, auto y)
    {
        cout << "generic lambda::x -> " << x << endl;
        cout << "generic lambda::y -> " << y << endl;
    };

    fn(int{10}, string{"text"});

    auto fn_parameter_pack = [](auto... args)
    {
        multi(temp(args)...);
    };
    fn_parameter_pack(1, "hello world", 1.5f);

    return 0;
}
