#ifndef __SIMPLE_EX_H__
#define __SIMPLE_EX_H__

#include <iostream>

template <typename T>
class MyClass
{
public:
    MyClass() = default;
    ~MyClass() = default;
    void method(T &&v);
    void method(T &v);
};

#endif // !__SIMPLE_EX_H__