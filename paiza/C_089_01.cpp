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
    // ifstream ifs{"data.txt"};
    std::getline(cin, s);
    // std::getline(ifs, s);
    int h = stoi(s.substr(0, s.find(' ')));
    int w = stoi(s.substr(s.find(' ') + 1));

    vector<string> v;
    for (size_t i = 0; i < h; i++)
    {
        std::getline(cin, s);
        // std::getline(ifs, s);
        v.emplace_back(s);
    }

    int sum = 0;
    for (size_t i = 0; i < h; i++)
    {
        int head = 0;
        int pos = 0;
        int n;
        std::getline(cin, s);
        // std::getline(ifs, s);
        for (size_t j = 0; j < w; j++)
        {
            pos = s.find(' ', pos);
            if (pos == string::npos)
                n = stoi(s.substr(head));
            else
                n = stoi(s.substr(head, pos));
            pos += 1;
            head = pos;

            if (v[i][j] == 'o')
                sum += n;
        }
    }

    cout << sum << endl;
    return 0;
}

