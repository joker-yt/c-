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
    // std::getline(ifs, s);
    std::getline(cin, s);
    size_t k = stoi(s.substr(0, s.find(' ')));
    int n = stoi(s.substr(s.find(' ') + 1));
    int sc = 100 / n;

    for (size_t i = 0; i < k; i++)
    {
        std::getline(cin, s);
        int d = stoi(s.substr(0, s.find(' ')));
        int c = stoi(s.substr(s.find(' ') + 1));

        int score = c * sc;
        if (0 < d && d <= 9)
        {
            score *= 80;
            score /= 100;
        }
        else if (d > 9)
            score = 0;

        if (score <= 59)
            cout << "D" << endl;
        else if (60 <= score && score <= 69)
            cout << "C" << endl;
        else if (70 <= score && score <= 79)
            cout << "B" << endl;
        else
            cout << "A" << endl;
    }

    return 0;
}

