#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1{3, 42};
    vector<int> v2(3, 42);

    cout << "v1:\n";
    for (int i: v1)
        cout << i << endl;
    cout << "v2:\n";
    for (int i: v2)
        cout << i << endl;
    return 0;
}
