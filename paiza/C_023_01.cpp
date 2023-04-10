#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;
class MySplit
{
private:
    string _s;
    set<int> _set;

public:
    MySplit(string s) : _s(s)
    {
        string::size_type pos = 0;
        while (1)
        {
            string::size_type end = s.find(string{" "}, pos);
            if (end == string::npos)
            {
                _set.emplace(::stoi(s.substr(pos)));
                break;
            }

            string tmp = s.substr(pos, end - pos);
            _set.emplace(::stoi(tmp));
            pos = end + 1;
        }
    }
    ~MySplit() {}
    set<int> value()
    {
        return move(_set);
    }
};

class Input
{
public:
    Input(){};
    Input(string);
    Input(Input &&) = default;
    Input(const Input &) = default;
    Input &operator=(Input &&) = default;
    Input &operator=(const Input &) = default;
    ~Input();

private:
    size_t _n;
    set<int> _set;
};

Input::Input(string fname)
{
    string s;
    // ifstream ifs{fname};
    // std::getline(ifs, s);
    std::getline(cin, s);
    _set = MySplit{s}.value();

    // std::getline(ifs, s);
    std::getline(cin, s);
    _n = stoi(s);

    for (size_t i = 0; i < _n; i++)
    {
        int sum = 0;
        // std::getline(ifs, s);
        std::getline(cin, s);
        set<int> st = MySplit{s}.value();
        for_each(_set.begin(), _set.end(), [&sum, &st](int x) {
            sum += count_if(st.begin(), st.end(), [&x](int y) {
                return x == y;
            });
        });
        cout << sum << endl;
    }
}

Input::~Input()
{
}

int main(int argc, char const *argv[])
{
    Input cl{"data1.txt"};
    return 0;
}

