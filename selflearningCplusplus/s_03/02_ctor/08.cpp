#include <iostream>
#include <optional>

using namespace std;

class Person
{
public:
    Person();
    Person(optional<int> age);

    void show()
    {
        cout << __func__ << ": " << age_.value() << endl;
    }

private:
    optional<int> age_;
};

Person::Person() : Person(-1)
{
    cout << "default ctor" << endl;
}
Person::Person(optional<int> age) : age_(age)
{
    cout << "delegating ctor" << endl;
}

int main(int argc, const char **argv)
{
    Person cl;
    cl.show();
    return 0;
}