#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    std::getline(cin, s);
    // ifstream ifs{"data.txt"};
    // std::getline(ifs, s);

    size_t head = 0;
    size_t pos = 0;
    list<int> d;
    while (1)
    {
        pos = s.find(' ', head);
        if (pos == string::npos)
        {
            d.emplace_back(std::stoi(s.substr(head, pos)));
            break;
        }
        d.emplace_back(std::stoi(s.substr(head, pos)));
        head = ++pos;
    }

    std::getline(cin, s);
    // std::getline(ifs, s);
    int n = stoi(s);
    int count = 0;

    for (size_t i = 0; i < n; i++)
    {
        head = 0;
        pos = 0;
        std::getline(cin, s);
        // std::getline(ifs, s);
        pos = s.find(' ', head);
        string name(s.substr(head, pos));
        head = ++pos;
        int min, max;
        bool b = true;
        for (auto x : d)
        {
            pos = s.find(' ', head);
            min = stoi(s.substr(head, pos));
            head = ++pos;
            pos = s.find(' ', head);
            max = stoi(s.substr(head, pos));
            head = ++pos;
            if (min > x || x > max)
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            count++;
            cout << name << endl;
        }
    }
    if (!count)
        cout << "no evolution" << endl;

    return 0;
}

