#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

class Person
{
public:
    Person()
    {
        p_land_ = new unsigned char[100]{0xFFU};
    }
    ~Person()
    {
        delete (p_land_);
    }
    Person(Person &&);

    void show()
    {
        cout << static_cast<void *>(p_land_) << endl;
    }

private:
    unsigned char *p_land_ = nullptr;
};

Person::Person(Person &&t) : p_land_(t.p_land_)
{
    cout << "move ctor" << endl;
    t.p_land_ = nullptr;
}

int main(int argc, const char **argv)
{
    Person a;
    a.show();

    Person b(move(a));
    a.show();
    b.show();

    return 0;
}

#if 0 // expected output
address of a.p_land_
move ctor
0 // address of a.p_land_
address of b.p_land_ // equals previous address of a.p_land_
#endif