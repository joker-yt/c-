#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    // std::ifstream ifs{"data.txt"};
    std::getline(cin, s);
    // std::getline(ifs, s);
    int n = stoi(s);

    list<string> l;
    map<string, int> mp;
    size_t pos;
    for (size_t i = 0; i < n; i++)
    {
        std::getline(cin, s);
        // std::getline(ifs, s);
        pos = s.find(' ');
        l.emplace_back(s.substr(0, pos));
        mp.insert(make_pair<string, int>(s.substr(0, pos), std::stoi(s.substr(pos + 1))));
    }
    std::getline(cin, s);
    // std::getline(ifs, s);
    pos = s.find(' ');
    string country = s.substr(0, pos);
    int h = std::stoi(s.substr(pos + 1, s.find(':') - pos)) - mp[country];
    int m = std::stoi(s.substr(s.find(':', pos + 1) + 1));

    for (auto ss : l)
    {
        int tmp = h + mp[ss];
        if (tmp < 0)
            tmp += 24;
        else if (tmp > 24)
            tmp -= 24;
        cout << std::setfill('0') << std::setw(2) << tmp;
        cout << ":";
        cout << std::setfill('0') << std::setw(2) << m << endl;
    }
    return 0;
}

