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
    int n = stoi(s);
    int sr, er, hr = 0, lr = 65536;
    for (size_t i = 0; i < n; i++)
    {
        std::getline(cin, s);
        size_t s1 = s.find(' ');
        size_t s2 = s.find(' ', s1 + 1);
        size_t s3 = s.find(' ', s2 + 1);

        int sd = stoi(s.substr(0, s1));
        int ed = stoi(s.substr(s1 + 1, s2));
        int hd = stoi(s.substr(s2 + 1, s3));
        int ld = stoi(s.substr(s3 + 1));

        if (i == 0)
            sr = sd;
        if (i == n - 1)
            er = ed;
        hr = max(hr, hd);
        lr = min(lr, ld);
    }

    cout << sr << " " << er << " " << hr << " " << lr << endl;
    return 0;
}

