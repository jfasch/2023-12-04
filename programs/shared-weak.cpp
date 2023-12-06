#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> pi1(new int{42});
    auto pi2 = pi1;

    std::cout << pi2.use_count() << std::endl;

    int* i = pi2.get();
    std::cout << *i << std::endl;

    std::weak_ptr<int> wi = pi1;

    pi1.reset();
    pi2.reset();

    if (std::shared_ptr<int> pi = wi.lock())
        std::cout << "locked: " << *pi  << std::endl;
    else
        std::cout << "not locked" << std::endl;

    return 0;
}
