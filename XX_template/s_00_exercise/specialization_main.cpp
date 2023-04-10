#include <iostream>
#include <string>
#include "specialization_inst.h"

using namespace std;

int main(int argc, char const *argv[])
{
    TemplClass<int> cl;

    cout << cl.func(10) << endl; // link error occurred if specialization has been done.

    cout << templ_func<string>(string("test string")) << endl;
    return 0;
}
