#include <array>
#include <bitset>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>

#include <openssl/md5.h>
#include <boost/lexical_cast.hpp>

using namespace std;

void calc_md5()
{
    unsigned char md5[MD5_DIGEST_LENGTH];
    unsigned char buf[16] = {0};

    ifstream ifs("../test.txt", ifstream::binary);
    size_t siz = ifs.seekg(0, ifs.end).tellg();
    ifs.seekg(0, ifs.beg);
    ifs.read((char *)(buf), siz);

    MD5(buf, siz, md5);
    // print md5
    for (size_t i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        cout << hex << int(md5[i]) << " ";
    }

    cout << endl;
    // converts 8 byte from the beginning of md5 to long long int
    unsigned int *n = reinterpret_cast<unsigned int *>(md5);
    cout << *n << endl;
}

struct MyMd5
{
    unsigned char _md5[MD5_DIGEST_LENGTH]{0};

    size_t fsiz(string &fname)
    {
        return ifstream{fname, ifstream::binary}.seekg(0, ifstream::end).tellg();
    }

    unique_ptr<unsigned char> fdata(string &fname, size_t s)
    {
        auto p = make_unique<unsigned char>(s);
        ifstream{fname}.read(reinterpret_cast<char *>(p.get()), s);
        return move(p);
    }

    void calc_md5(unsigned char *buf, size_t s)
    {
        MD5(buf, s, _md5);
    }
    void calc_md5(string &fname)
    {
        size_t s = fsiz(fname);
        calc_md5(fdata(fname, s).get(), s);
    }

public:
    MyMd5(unsigned char *buf, size_t s)
    {
        calc_md5(buf, s);
    };

    MyMd5(string &&fname)
    {
        calc_md5(fname);
    }
    MyMd5(string &fname)
    {
        calc_md5(fname);
    }
    unsigned char *md5_value()
    {
        return _md5;
    }
};

int main(int argc, const char **argv)
{
    calc_md5();

    {
        string data{"test string"};
        MyMd5 m{
            reinterpret_cast<unsigned char *>(const_cast<char *>(data.c_str())),
            data.length()};

        cout << hex << *((unsigned int *)(m.md5_value())) << endl;
    }

    {
        string fname{"../test.txt"};
        MyMd5 m{fname};
        // MyMd5 m{string{"../test.txt"}};

        cout << hex << *((unsigned int *)(m.md5_value())) << endl;
    }
    return 0;
}

#if 0
➜  ~ openssl md5 test.txt  
MD5(test.txt)= 5cd3e81fb747479797b62794c6bf6aaf
#endif
