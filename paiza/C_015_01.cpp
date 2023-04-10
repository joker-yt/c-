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
    int n = stoi(s);
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        // std::getline(ifs, s);
        std::getline(cin, s);
        string d = s.substr(0, s.find(' '));
        long int p = stoi(s.substr(s.find(' ') + 1));

        int po;
        if (d.find('3') != string::npos)
        {
            po = p * 3;
            po /= 100;
        }
        else if (d.find('5') != string::npos)
        {
            po = p * 5;
            po /= 100;
        }
        else
            po = p / 100;
        sum += po;
    }
    cout << sum << endl;

    return 0;
}

