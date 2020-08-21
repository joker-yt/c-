#include <string>
#include "simple_example.h"

int main(int argc, char const *argv[])
{
    MyClass<int> cl_n;

    cl_n.method(int{100}); // right value
    int n = 10;
    cl_n.method(n); // left value

    MyClass<std::string> cl_s;
    cl_s.method(std::string{"string"}); // right value
    // method for lvalue undefined, but no error because it isn't used.
    // therefore, compile error occured coding like below.
#if 0
    std::string str{"string"};
    cl_s.method(str); // left value
#endif
    return 0;
}
