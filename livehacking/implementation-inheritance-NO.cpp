#include <iostream>
using namespace std;

class MyCuteClass
{
public:
    MyCuteClass(std::string msg)
    {
        cout << "MyCuteClass(" << msg << ")" << endl;
    }
};

class MyCuterClass : public MyCuteClass
{
public:
    MyCuterClass()
    : MyCuteClass("blah")
    { 
        cout << "MyCuterClass" << endl;
    }
};

int main()
{
    MyCuterClass c;
    (void)c;
    return 0;
}
