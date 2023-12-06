def fibo():
    first, second = 1, 1
    yield first
    yield second
    while len(l) < max:
        third = first + second
        yield third
        first, second = second, third

for i in fibo():
    print(i)
