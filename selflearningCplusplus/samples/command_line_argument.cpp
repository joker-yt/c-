#include <boost/program_options.hpp>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    namespace po = boost::program_options;

    po::options_description desc{"option"};
    desc.add_options()("arg1,a", po::value<string>(), "secret?")("arg2,b", "2nd")("arg3,c", "3nd");

    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("arg1"))
            cout << vm["arg1"].as<string>() << endl;
        if (vm.count("arg2"))
            cout << desc << endl;
        if (vm.count("arg3"))
            cout << "vm[arg3]" << endl;
    }
    catch (...)
    {
        cout << "any exception occurrs." << endl;
    }
    cout << "test" << endl;

    return 0;
}
