#include <string>
#include <vector>
#include <iostream>
#include <cstddef>
using namespace std;

void print_container(auto begin, auto end)     // <--- Abbreviated Function Template
{
    for (auto run = begin; run < end; ++run)
        cout << *run << endl;
}

int main()
{
    using intv = vector<int>;
    const intv array{1, 2, 3, 4, 5, 6, 7};
    auto begin = array.begin();
    auto end = array.end();
    print_container(begin, end);
    return 0;
}
