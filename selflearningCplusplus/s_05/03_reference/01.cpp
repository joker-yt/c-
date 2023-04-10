#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{

    int &&i = 1; // of cource, you can not get "&0".
    int &&j = 0;
    cout << i << endl;
    cout << j << endl;
    cout << &i << endl;
    cout << &j << endl;

    i = j;
    cout << i << endl;
    i = 5;
    cout << i << endl;

    return 0;
}

#if 0  // expected output
1 // i's value
0 // j's value
(some address #1)
(some address next to #1)
0 // i's value copied from j
5 // i's value assigned as 5
#endif // expected output