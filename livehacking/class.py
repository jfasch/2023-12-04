class Foo:
    def __init__(self, a, b):
        print('__init__', id(self))
        self.a = a
        self.b = b

    def print_foo(self):
        print('print_foo', id(self))
        print(self.a, self.b)

print(Foo.print_foo)

f = Foo(1, 2)
print('main', id(f))
f.print_foo()
