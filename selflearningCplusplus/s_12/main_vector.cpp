#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

#include "../test/MyClass.h"
using namespace std;

int main(int argc, char const *argv[])
{
    cout << " vector ##########################" << endl;
    { // push_back with lvalue
        // copy ctor during push_back
        vector<MyClass> v0;
        MyClass a{0};

        cout << " $$ starting push back of MyClass" << endl;
        v0.push_back(a);
        v0.push_back(a);
        v0.push_back(a);
        cout << " $$ end of push back" << endl;
    }
    { // push_back with lvalue, move
        vector<MyClass> v0;
        MyClass b{0};
        MyClass c{0};
        MyClass d{0};
        cout << " $$ starting push back of MyClass with move" << endl;
        v0.push_back(move(b));
        v0.push_back(move(c));
        v0.push_back(move(d));
        cout << " $$ end of push back with move" << endl;
    }
    { // push_back with rvalue
        vector<MyClass> v0;
        cout << " $$ starting push back of MyClass with rvalue" << endl;
        v0.push_back(MyClass{1});
        v0.push_back(MyClass{1});
        v0.push_back(MyClass{1});
        cout << " $$ end of push back with rvalue" << endl;
    }
    { // push_back with rvalue, move

        vector<MyClass> v0;
        cout << " $$ starting push back of MyClass with rvalue, move" << endl;
        v0.push_back(move(MyClass{1}));
        v0.push_back(move(MyClass{1}));
        v0.push_back(move(MyClass{1}));
        cout << " $$ end of push back with rvalue, move" << endl;
    }

    { //find and sort
        //  initializer_list = {}
        std::vector<std::string> v = {"apple",
                                      "orange",
                                      "kiwi"};
        auto r = std::find(v.begin(), v.end(), "kiwi");
        std::cout << *r << std::endl;

        std::cout << typeid(r).name() << std::endl;
        std::cout << typeid(MyClass).name() << std::endl;

        for (const auto &x : v)
            cout << x << endl;

        cout << "#############" << endl;
        sort(v.begin(), v.end());
        for (auto x : v)
            cout << x << endl;
    }

    { // string with
        string s = {"apple"};
        vector<char> cv = {s.begin(), s.end()};

        for (auto c : cv)
        {
            cout << c << endl;
        }
    }
    { // size specified
        vector<int> vi{};
        cout << vi.size() << endl;
        vi.resize(10);
        cout << vi.size() << endl;
        vi.resize(10);
        cout << vi.size() << endl;

        size_t n = vi.size();
        vector<int>::iterator it = vi.begin();
        for (size_t i = 0; i < n; i++)
        {
            *it++ = i;
        }

        cout << "####################" << endl;
        for (auto x : vi)
            cout << x << endl;
    }
    { // assign
        cout << "start ########### assign" << endl;
        vector<int> values = {2, 4, 6, 8};
        vector<int> v0;
        v0.assign(values.begin(), values.end());
        for_each(v0.begin(), v0.end(), [](auto x) {
            cout << x << " ";
        });
        cout << endl;
        cout << "reverse" << endl;
        for_each(v0.rbegin(), v0.rend(), [](auto x) {
            cout << x << " ";
        });
        cout << endl;
        cout << "end ########### assign" << endl;
    }
    { // insert, emplace
        // insert
        vector<int> v;
        for (int i = 1; i < 10; i++)
            v.push_back(i);

        for_each(v.begin(), v.end(), [](auto x) {
            cout << x << " ";
        });
        cout << endl;

        v.insert(v.begin(), 0);
        v.insert(v.end(), 10);

        for_each(v.begin(), v.end(), [](auto x) {
            cout << x << " ";
        });
        cout << endl;

        // insert vs emplace
        cout << " insert vs emplace" << endl;
        {
            cout << "insert;" << endl;
            MyClass a{10};
            vector<MyClass> v;
            v.insert(v.begin(), a);
        }
        {
            cout << "emplace;" << endl;
            MyClass a{10};
            vector<MyClass> v;
            v.emplace(v.begin(), 10);
        }
    }
    return 0;
}
