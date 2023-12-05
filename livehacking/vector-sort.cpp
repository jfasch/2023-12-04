#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> data{3, 1, 2, 6, 100, -5};
    sort(data.begin(), data.end(), [](int l, int r) { return l>r; });

    for (int i: data)
        cout << i << endl;

    return 0;
}
