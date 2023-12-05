#include <iostream>
#include <string>
using namespace std;

struct point
{
    int x, y;
};

auto create_print_function(point p)
{
    return [&](int multiply) -> int
    {
        while (multiply--)
            cout << '(' << p.x << ',' << p.y << ')';
        cout << '\n';
        return 42;
    };
}


int main()
{
    auto f1 = create_print_function({1, 2});
    auto f2 = create_print_function({3, 4});

    f1(5);
    f2(3);

    return 0;
}
