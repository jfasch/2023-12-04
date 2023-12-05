#include <variant>
#include <iostream>
using namespace std;

struct point
{
    int x{}, y{};
};

int main()
{
    std::variant<point, int> v(point(1, 2));
    point p = std::get<point>(v);

    if (std::holds_alternative<point>(v))
        point p = std::get<point>(v);
    else if (std::holds_alternative<int>(v))
        cout << << endl;

    return 0;
}
