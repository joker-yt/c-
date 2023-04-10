#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    std::getline(cin, s);
    int n = stoi(s.substr(0, s.find(' ')));
    int r = stoi(s.substr(s.find(' ') + 1));
    list<int> l;
    for (size_t i = 0; i < n; i++)
    {
        std::getline(cin, s);
        int s1 = s.find(' ');
        int s2 = s.find(' ', s.find(' ') + 1);
        int h = stoi(s.substr(0, s1));
        if (h < r * 2)
            continue;
        int w = stoi(s.substr(s1 + 1, s2));
        if (w < r * 2)
            continue;
        int d = stoi(s.substr(s2 + 1));
        if (d < r * 2)
            continue;
        l.emplace_back(i + 1);
    }

    for_each(l.begin(), l.end(), [](int n) { cout << n << endl; });

    return 0;
}

