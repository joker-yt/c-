#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    string s = {"My name is Yasuyuki"};
    string s_ = {s.substr(s.find('n'), 4)};
    cout << s_.size() << endl;

    string ss[] = {"my", "name", "is", "Yasuyuki"};

    vector<string *> vi;
    vector<string> vi2;
    for (int i = 0; i < 4; i++)
    {
        cout << ss[i] << " : " << &ss[i] << endl;
        vi.push_back(&ss[i]);
        vi2.push_back(ss[i]);
    }

    cout << "#################### try" << endl;
    for_each(
        vi.begin(), vi.end(), [](auto s) {
            cout << s << endl;
        });
    cout << "#################### try" << endl;
    for_each(
        vi2.begin(), vi2.end(), [](auto s) {
            cout << s << " : " << &s << endl;
        });

    string str{"Penpinappleapplepen"};

    string tmp;
    tmp.resize(str.size());
    transform(str.begin(), str.end(), tmp.begin(), ::toupper);
    cout << str << endl;
    cout << tmp << endl;

    return 0;
}
