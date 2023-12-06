#include <iostream>
#include <cstring>


class Interface
{
public:
    virtual ~Interface() {}
    virtual void method() const = 0;
};

class Derived1 : public Interface
{
public:
    Derived1(const char* msg) : _msg(new char[strlen(msg)+1])
    {
        strcpy(_msg, msg);
    }
    ~Derived1()
    {
        std::cout << "~Derived1()" << std::endl;
        delete[] _msg;
    }
    void method() const
    {
        std::cout << "Derived1::method(): " << _msg << std::endl;
    }
private:
    char* _msg;
};

class Derived2 : public Interface
{
public:
    Derived2(const char* msg) : _msg(new char[strlen(msg)+1])
    {
        strcpy(_msg, msg);
    }
    ~Derived2()
    {
        std::cout << "~Derived1()" << std::endl;
        delete[] _msg;
    }
    void method() const
    {
        std::cout << "Derived2::method(): " << _msg << std::endl;
    }
private:
    char* _msg;
};

class Derived3 : public Interface
{
public:
    void method() const
    {
        std::cout << "Derived3::method()" << std::endl;
    }
};

class Derived3Derived : public Derived3
{
public:
    void method() const override
    {
        std::cout << "Derived3Derived::method()" << std::endl;
    }
};

int main()
{
    // setup phase
    Interface* objects[] = {new Derived1("hallo"), new Derived2("hello"), new Derived3(), new Derived3Derived()};

    // runtime phase
    for (Interface* objp: objects)
        objp->method();

    // cleanup phase
    for (Interface* objp: objects)
        delete objp;

    return 0;
}
