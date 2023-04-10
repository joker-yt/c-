#ifndef __MY_INST_H__
#define __MY_INST_H__

// specialization for class template
template <typename T>
class TemplClass
{
public:
    T func(T x);
};

// specialization for function template
template <typename T>
T templ_func(T x);

#endif // !__MY_INST_H__