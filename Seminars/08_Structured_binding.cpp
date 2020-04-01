#include <iostream>

bool
add_overflow(int val1, int val2, int *res)
{
    return !__builtin_add_overflow(val1, val2, res);
}

struct MathResult
{
    bool ok;
    int value;

};

MathResult
add_overflow(int val1, int val2)
{
    int res;
    bool flag = !__builtin_add_overflow(val1, val2, &res);
    return { flag, res };
}
 
int
main(void)
{
    int a, b;
    std::cin >> a >> b;
    int res;
    bool ovf = add_overflow(a, b, &res); // совет гугла

    auto r = add_overflow(a, b);
    std::cout << r.ok << ' ' << r.value << std::endl;

    if (auto [ ok, value ] = add_overflow(a, b); ok) {
        std::cout << "ok: " << value << std::endl;
    }

    return 0;
}
