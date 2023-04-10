#include <algorithm>
#include <iostream>
#include <span>
#include <string>

using namespace std;

struct MyStruct
{
private:
    void PrivateMethod() {} // private method ok
    //  int m; // pvivate member ng
public:
    // MyStruct(){} // constructor ng
    int n;      // public member ok
    string str; // public member ok

    void method() {} // public method ok
    int &getN() { return n; }
    string &getStr() { return str; }
} my_st{
    .n = 10,
    .str{"text"}};

int main(int argc, char const *argv[])
{
    cout << my_st.getN() << endl;
    cout << my_st.getStr() << endl;
    return 0;
}
