#include <string>
#include "specialization_inst.h"

template <typename T>
T TemplClass<T>::func(T x)
{
    return x;
}

// specialization for method above.
template <>
int TemplClass<int>::func(int x)
{
    return x;
}

// function template
template <typename T>
T templ_func(T x)
{
    return std::move(x);
}

// specialization for function above.
template <>
std::string templ_func(std::string x)
{
    return std::move(x);
}
