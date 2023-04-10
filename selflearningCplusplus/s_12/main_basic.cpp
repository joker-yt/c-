#include <iostream>
using namespace std;

//########################################
/** \ @class Base
 * @brief brief comment.
 * @detail detail comment.
 */
//########################################
class Base
{
public:
    Base(int n);
    // move ctor
    Base(Base &&b)
    {
        cout << "move ctor" << endl;
        *this = move(b);
    };
    // copy ctor
    Base(const Base &c)
    {
        this->_n = c._n;
        cout << "copy ctor: " << this->_n << endl;
    };
    // move operator
    Base &operator=(Base &&b) noexcept
    {
        cout << "move operator" << endl;
        if (this != &b)
        {
            this->_n = move(b._n);
        }
        return *this;
    };
    // copy operator
    Base &operator=(const Base &b)
    {
        cout << "copy operator" << endl;
        this->_n = b._n;
    };
    ~Base();

    int value()
    {
        return _n;
    }

private:
    int _n;
};

Base::Base(int n) : _n(n)
{
    cout << "ctor" << endl;
}

Base::~Base()
{
}

void test_func(Base b)
{
    cout << __FUNCTION__ << endl;
    cout << b.value() << endl;
}

void test_lifecycle_rvalue_reference(Base &&b)
{
    cout << __FUNCTION__ << endl;
    cout << b.value() << endl;
    // if without "move", copy ctor is invoked.
    Base tmp = move(b);
}

void test_lifecycle_rvalue_reference_invalid(Base &b)
{
    cout << __FUNCTION__ << endl;
    cout << b.value() << endl;
    Base tmp = b;
}

int main(int argc, char const *argv[])
{
    Base b_first{1};
    Base b_copy = b_first;

    cout << "b_first: " << b_first.value() << endl;
    cout << "b_copy: " << b_copy.value() << endl;

    cout << "move ctor ##################" << endl;
    test_func(move(b_first));
    cout << "copy ctor ##################" << endl;
    test_func(b_copy);

    cout << "reference (nothing happen) ##################" << endl;
    {
        Base &b_ref = b_copy;
    }
    cout << "what happen ##################" << endl;
    {
        Base a{10};
        Base &a_lref = a;
        Base &&a_rref = Base{20};
        Base b = move(a_lref);
        Base c = move(a_rref);
    }

    cout << "how long does the lifecycle of rvalue reference continue? ##################" << endl;
    {
        Base b{100};
        // test_lifecycle_rvalue_reference_invalid(b);
        test_lifecycle_rvalue_reference(move(b));
    }
    cout << "end of lifecycle of rvalue reference bracket ##################" << endl;

    return 0;
}
