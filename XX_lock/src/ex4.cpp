#include <iostream>
#include <condition_variable>
#include <memory>
#include <thread>
#include <unistd.h>

using namespace std;

//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
// ########################################
/** \ @class THD_OBJ
 * @brief brief comment.
 * @detail detail comment.
 */
// ########################################
class THD_OBJ
{
private:
    void func()
    {
        cout << "THD_OBJ thread" << endl;
        {
            unique_lock<mutex> lock{mtx_};

            cv_.wait(lock);
        }
        cout << "THD_OBJ thread finished" << endl;
    }
    thread t_{[this]()
              { this->func(); }};
    mutex mtx_;
    condition_variable cv_;

public:
    THD_OBJ()
    {
        cout << "ctor" << endl;
    };
    ~THD_OBJ() { t_.join(); };
    void Run() {}
    void notify()
    {
        cout << "THD_OBJ::notify() is called" << endl;
        lock_guard<mutex> lock{mtx_};
        cv_.notify_one();
    }
};
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************

int main(int argc, char const *argv[])
{
    unique_ptr<THD_OBJ> obj = make_unique<THD_OBJ>();

    obj->Run();

    sleep(2);
    obj->notify();

    return 0;
}
