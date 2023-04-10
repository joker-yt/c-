#include <stdlib.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void foo()
{
    int x = factorial(4); // == (4 * 3 * 2 * 1) == 24
    int y = factorial(0); // == 0! == 1
}

int main(int argc, const char **argv)
{

    for (size_t i = 0; i < 1000000; i++)
    {
        foo();
    }

    return 0;
}