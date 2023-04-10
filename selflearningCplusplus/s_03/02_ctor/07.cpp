#include <iostream>

using namespace std;

class S
{
public:
    S()
    {
        s_count_++;
    }
    ~S()
    {
        s_count_--;
    }

    int show_count() const
    {
        return s_count_;
    }

private:
    static int s_count_;
};

int S::s_count_ = 0;

int main(int argc, const char **argv)
{
    // cout << "static member:" << S::s_count_ << endl; // can't access static private member except from member function.

    S s1;
    cout << "first instanciation: " << s1.show_count() << endl;

    S s2;
    cout << "second instanciation: " << s2.show_count() << endl;
    cout << "second instanciation from s1: " << s1.show_count() << endl;

    // compile error! you can define static member as const.
    // then, the chance to set value is only at initialization.
    // S::s_var_ = 100;
    // cout << "static member:" << S::s_var_ << endl;
    return 0;
}
