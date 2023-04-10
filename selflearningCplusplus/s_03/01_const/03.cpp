#include <iostream>
#include <optional>

using namespace std;

class MyClassBase
{
public:
    virtual int get() const = 0;
    virtual void generate() const = 0;
    virtual void update() const = 0;
};

class MyClass1 : public MyClassBase
{
    enum CACHED_STATUS
    {
        NON_CACHED,
        CACHED
    };

public:
    MyClass1() : val_(2){};
    ~MyClass1() = default;
    int get() const
    {
        cout << __FUNCTION__ << "->" << endl;
        if (cached_ == MyClass1::NON_CACHED)
            generate();

        return val_;
    }
    void generate() const
    {
        cout << __FUNCTION__ << "->" << endl;
        val_ = 10;
        cached_ = MyClass1::CACHED;
    }
    void update() const
    {
        cout << __FUNCTION__ << "->" << endl;
        cached_ = MyClass1::NON_CACHED;
        val_ = 0;
    }

private:
    mutable int val_;
    mutable bool cached_;
};

class MyClass2
{
public:
    optional<int> get() const
    {
        cout << __FUNCTION__ << "->" << endl;
        if (!val_)
            generate();

        return val_.value();
    }
    void generate() const
    {
        cout << __FUNCTION__ << "->" << endl;
        val_ = 10;
    }
    void update() const
    {
        cout << __FUNCTION__ << "->" << endl;
        val_ = nullopt;
    }

private:
    mutable optional<int> val_;
};

template <typename T>
void routine(const T t)
{
    cout << "1st trial  ";
    t.get();

    cout << "2nd trial  ";
    t.get();

    cout << "3rd trial(update)  ";
    t.update();
    t.get();
}

int main(int argc, char const *argv[])
{
#if 0
    const MyClass1 cl;
    cout << "1st trial  ";
    cl.get();

    cout << "2nd trial  ";
    cl.get();

    cout << "3rd trial(update)  ";
    cl.update();
    cl.get();
#else
    const MyClass1 cl1;
    routine<MyClass1>(cl1);

    const MyClass2 cl2;
    routine<MyClass2>(cl2);
#endif

    return 0;
}
