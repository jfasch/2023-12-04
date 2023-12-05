#include <iostream>
#include <cstdint>
using namespace std;

struct Foo
{
    int a;
    int b;
    char c;

    void* get_this()
    {
        return this;
    }

    void print_foo()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << this << endl;
        cout << this->a << ' ' << this->b << endl;
    }
};

void print_foo(Foo* f)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << f << endl;
    cout << f->a << ' ' << f->b << endl;
}

int main()
{
    Foo foo = {1, 2};
    Foo foo2 = {42, 666};
    cout << "foo: " << &foo << endl;
    cout << "this: " << foo.get_this() << endl;
    // cout << "offset of foo.a: " << ((uint8_t*)(&foo.a) - (uint8_t*)(&foo)) << endl;
    // cout << "offset of foo.b: " << ((uint8_t*)(&foo.b) - (uint8_t*)(&foo)) << endl;

    cout << "size of Foo: "  << sizeof(foo) << endl;

    // print_foo(&foo);
    foo.print_foo();
    foo2.print_foo();

    Foo* pf1 = (Foo*)((char*)&foo + 1);
    pf1->print_foo();

    (&foo + 1)->print_foo();

    return 0;
}
