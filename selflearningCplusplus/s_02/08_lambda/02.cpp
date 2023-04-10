#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    { // copy capture
        int var = 50;
        int foo = 100;

        auto m = [var]() -> int {
            return var;
        };

        //  @@ captured variable has been taken inside lambda, so no affects if original variable has been changed.
        cout << "copy capture before increment: " << m() << endl;
        var += 1;
        cout << "copy capture after increment: " << m() << endl;

        // @@ captured multiple values at the same time.
        auto n1 = [var, foo]() -> int {
            return var + foo;
        };
        auto n2 = [=]() -> int {
            return var + foo;
        };
        cout << "call [var,foo]" << n1() << endl;
        cout << "call [=]" << n2() << endl;

        // @@ mutable = changable copy capture
        auto n3 = [var]() mutable -> int {
            var += 200;
            return var;
        };
        cout << "var before calling lambda w/ mutable: " << var << endl;
        cout << "mutable :" << n3() << endl;
        cout << "var after calling lambda w/ mutable (unchanged): " << var << endl;
    }

    { // reference capture
        int var = 50;

        auto n1 = [&var]() -> int {
            return var;
        };

        auto n2 = [&var]() -> int {
            var++;
            return var;
        };
        cout << "initial var: " << var << endl;
        cout << "reference capture: " << n1() << endl;
        cout << "reference capture w/ changing value inside: " << n2() << endl;
        cout << "var after lambda(changed): " << var << endl;
    }
    return 0;
}