#include <optional>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // optional starts from c++17.
    std::optional<int> d;
    if (!d.has_value())
    {
        cout << "nullopt is assigned." << endl;
    }

    d = 3;
    if (!d.has_value())
    {
        cout << "nullopt is assigned." << endl;
    }
    else
    {
        cout << "optional<int>: " << d.value() << endl;
    }

    cout << "optional<int>: value_or(-1) -> " << d.value_or(-1) << endl;
    d = nullopt;
    cout << "[nullopt is assigned] optional<int>: value_or(-1) -> " << d.value_or(-1) << endl;

    return 0;
}
