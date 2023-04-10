#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    // ifstream ifs{"data.txt"};
    std::getline(cin, s);
    // std::getline(ifs, s);
    size_t pos = s.find(' ');
    int n = stoi(s.substr(0, pos));
    size_t head = pos + 1;
    pos = s.find(' ', head);
    int c1 = stoi(s.substr(head, pos - head));
    int c2 = stoi(s.substr(pos + 1));

    int stock = 0;
    int profit = 0;
    for (size_t i = 0; i < n; i++)
    {
        std::getline(cin, s);
        // std::getline(ifs, s);
        int val = stoi(s);
        if (i == n - 1)
        {
            if (stock > 0)
            {
                profit += stock * val;
                stock = 0;
            }
            break;
        }

        if (val <= c1)
        {
            profit -= val;
            stock++;
        }
        else if (val >= c2)
        {
            if (stock > 0)
            {
                profit += stock * val;
                stock = 0;
            }
        }
    }
    cout << profit << endl;

    return 0;
}

