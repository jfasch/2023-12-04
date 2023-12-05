#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    {
        map<string, int> translation;
        translation["one"] = 1;
        cout << translation["one"] << endl;
        cout << translation["two"] << endl;
        cout << translation.at("three") << endl;
    }
    return 0;
}
