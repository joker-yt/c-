#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    std::ifstream ifs{"data.txt"};
    // std::getline(cin, s);
    std::getline(ifs, s);
    int n = stoi(s);
    vector<pair<string, int>> v;
    for (size_t i = 0; i < n; i++)
    {
        // std::getline(cin, s);
        std::getline(ifs, s);
        size_t ind = s.find(' ');
        v.push_back(make_pair(s.substr(0, ind), std::stoi(s.substr(ind + 1))));
    }

    // std::getline(cin, s);
    std::getline(ifs, s);
    string t = s.substr(0, s.find(' '));
    string tmp = s.substr(s.find(' ') + 1);
    int h = std::stoi(tmp.substr(0, tmp.find(':')));
    int m = std::stoi(tmp.substr(tmp.find(':') + 1));

    auto it = find_if(v.begin(), v.end(), [&t](pair<string, int> x) {
        return x.first == t;
    });
    h -= it->second;
    if (h >= 24)
        h -= 24;
    else if (h < 0)
        h += 24;

    for_each(v.begin(), v.end(), [&](pair<string, int> x) {
        cout << setfill('0') << setw(2) << x.second + h;
        cout << ":";
        cout << setfill('0') << setw(2) << m << endl;
    });
    return 0;
}

