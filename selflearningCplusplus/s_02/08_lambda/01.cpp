#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    { // return int using explicit declaration
        auto n = [](int n) -> int {
            return n;
        };
        cout << n(50) << endl;
    }

    { // return int using assumption
        auto n = [](int n) {
            return n;
        };
        cout << n(50) << endl;
    }

        return 0;
}