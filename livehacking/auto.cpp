#include <type_traits>
#include <iostream>

using namespace std;

int main()
{
    if constexpr (std::is_same_v<int, int>)
        cout << "jo" << endl;
    return 0;
}
