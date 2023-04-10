#include <stdlib.h>

template <int N>
struct Factorial
{
    enum
    {
        value = N * Factorial<N - 1>::value
    };
};

template <>
struct Factorial<0>
{
    enum
    {
        value = 1
    };
};

// Factorial<4>::value == 24
// Factorial<0>::value == 1
void foo()
{
    int x = Factorial<4>::value; // == 24
    int y = Factorial<0>::value; // == 1
}

int main(int argc, const char **argv)
{

    for (size_t i = 0; i < 1000000; i++)
    {
        foo();
    }

    return 0;
}