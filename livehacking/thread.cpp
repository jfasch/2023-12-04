#include <thread>
#include <functional>
#include <iostream>

using namespace std;

void threadfunc(std::string msg)
{
    for (int i=0; i<100; i++)
        cout << i << ':' << msg << endl;
}

int main()
{
    thread t(threadfunc, "blah");

    t.join();
    return 0;
}
