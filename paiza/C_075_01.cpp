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
    int rest, loop;
    int point = 0;
    std::getline(cin, s);
    size_t pos;
    pos = s.find(' ');
    rest = std::stoi(s.substr(0, pos));
    loop = std::stoi(s.substr(pos + 1));

    for (size_t i = 0; i < loop; i++)
    {
        std::getline(cin, s);
        int fee = std::stoi(s);

        if (point >= fee)
        {
            point -= fee;
        }
        else
        {
            rest -= fee;
            point += fee / 10;
        }
        cout << rest << " " << point << endl;
    }

    return 0;
}

