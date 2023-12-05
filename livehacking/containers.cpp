#include <string>
#include <vector>
#include <iostream>
#include <cstddef>
using namespace std;

template <typename Iterator>
void print_container(Iterator begin, Iterator end)
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
