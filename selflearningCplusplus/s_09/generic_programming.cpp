#include <iostream>
#include <list>
#include <string>

using namespace std;

//########################################
/** \ @class MyClass
 * @brief each ctor implemented
 * @detail member: int _n
 * @param[in] int n
 */
//########################################
template <class Container, class T>
class MyClass
{
public:
    MyClass(Container &&con, int n, string &&str) : _con(con), _n(n), _str(str)
    {
        std::cout << "ctor" << std::endl;
    }
    // move ctor
    MyClass(MyClass &&b)
    {
        std::cout << "move ctor" << std::endl;
        *this = move(b);
    };
    // copy ctor
    MyClass(const MyClass &c)
    {
        this->_n = c._n;
        std::cout << "copy ctor: " << this->_n << std::endl;
    };
    // move operator
    MyClass &operator=(MyClass &&b) noexcept
    {
        std::cout << "move operator" << std::endl;
        if (this != &b)
        {
            this->_n = move(b._n);
        }
        return *this;
    };
    // copy operator
    MyClass &operator=(const MyClass &b)
    {
        std::cout << "copy operator" << std::endl;
        this->_n = b._n;
    };
    ~MyClass()
    {
        std::cout << "destructor" << std::endl;
    };
    //****************************************
    /*! \fn int MyClass::value()
     * @brief get member var(int _n)
     * @detail detail comment
     * @ar
     */
    //****************************************
    int value()
    {
        return _n;
    };

private:
    Container _con;
    int _n;
    string _str;
};

//########################################
/** \ @class MyClass2
 * @brief brief comment.
 * @detail detail comment.
 */
//########################################
template <template <class T, class Allocator = allocator<T>> class Container>
class MyClass2
{
private:
    struct MyStruct
    {
        MyStruct(const int &i) : _a(i)
        {
        }
        int _a;
    };

    Container<MyStruct> _cont;

public:
    MyClass2()
    {
        for (size_t i = 0; i < 5; i++)
        {
            _cont.emplace_back(MyStruct{i});
        }
    };
    MyClass2(MyClass2 &&) = default;
    MyClass2(const MyClass2 &) = default;
    MyClass2 &operator=(MyClass2 &&) = default;
    MyClass2 &operator=(const MyClass2 &) = default;
    ~MyClass2(){};
    void show()
    {
        for (auto x : _cont)
        {
            cout << x._a << endl;
        }
    }
};

template <class T, template <class, class> class Container>
class Object
{
public:
    Object(Container<T, allocator<T>> cont, T &&t, int n) : _cont(cont), _target(t), _n(n)
    {
    }
    Object(Object &&) = default;
    Object(const Object &) = default;
    Object &operator=(Object &&) = default;
    Object &operator=(const Object &) = default;
    ~Object(){};

private:
    Container<T, allocator<T>> _cont;
    int _n;
    string _target;
};

template <template <class, class> class Container>
class Input
{
public:
    Input(){};
    Input(Input &&) = default;
    Input(const Input &) = default;
    Input &operator=(Input &&) = default;
    Input &operator=(const Input &) = default;
    ~Input(){};
    Object<string, Container> read()
    {
        int n;
        string s;
        cin >> s;
        n = stoi(s);
        s.clear();
        cin >> s;

        string tmp;
        Container<string, std::allocator<string>> c;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            c.emplace_back(tmp);
        }

        return Object<string, Container>{move(c), move(s), n};
    };

private:
};

int main(int argc, char const *argv[])
{
    int n = 5;
    list<string> l = {"Mike", "Tom", "Jack"};
    l.emplace_back("Takeshi");
    l.emplace_back("Toshi");
    string t{"Jack"};

    {
        MyClass<list<string>, string>
            cl{move(l), n, move(t)};
        cout << cl.value() << endl;
    }

    // {
    //     MyClass2<list> cl;
    //     cl.show();
    //     return 0;
    // }
    {
        Input<list> cl;
        Object<string, list> obj = cl.read();
    }
}
