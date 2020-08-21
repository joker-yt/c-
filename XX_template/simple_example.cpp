#include <iostream>
#include <string>
#include "simple_example.h"

template <typename T>
void MyClass<T>::method(T &&v)
{
    std::cout << "implementation w/o instanciation(r) -> " << v << std::endl;
};

template <typename T>
void MyClass<T>::method(T &v)
{
    std::cout << "implementation w/o instanciation(l) -> " << v << std::endl;
};

// undefined reference error occurred if templated methods are implemented separetaly from definition of those.
// in this case, template specification is needed.
// it makes instances from templates.
// instanciation is not needed if those method isn't used.

template <>
void MyClass<int>::method(int &n)
{
    std::cout << "instanced template(l)" << std::endl;
}
template <>
void MyClass<int>::method(int &&n)
{
    std::cout << "instanced template(r)" << std::endl;
}

template <>
void MyClass<std::string>::method(std::string &&str)
{
    std::cout << "instanced template(r) (type = string)" << std::endl;
}
