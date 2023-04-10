#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

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
    void show_items()
    {
        for (auto x : _cont)
        {
            cout << x << endl;
        }
    }

    void search_list()
    {
        T s = _target;
        bool b = false;
        for_each(_cont.begin(), _cont.end(), [&s, &b](T t) {
            if (t.find(s) != -1)
            {
                cout << t << endl;
                b = true;
            }
        });

        if (!b)
            cout << "None" << endl;
        return;
    }

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
    Object<string, Container> read(string fname)
    {
        ifstream ifs{fname};
        char buf[64] = {0};
        ifs.getline(buf, sizeof(buf));
        int n = ::atoi(buf);
        ifs.getline(buf, sizeof(buf));
        string s{buf};
        Container<string, std::allocator<string>> c;
        for (size_t i = 0; i < n; i++)
        {
            ifs.getline(buf, sizeof(buf));
            c.emplace_back(buf);
        }
        return Object<string, Container>{move(c), move(s), n};
    }

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
    Input<list> cl;
    Object<string, list> obj = cl.read("data.txt");
    obj.search_list();

    return 0;
}
