#include <iostream>
#include <functional>

std::function<void (int)>
func(void)
{
    int res, a;
    std::cin >> a;
    return [&res, a](int x) { res = a + x; };
}
 
int
main(void)
{
    auto f = func();

    int c;
    std::cin >> c;

    f(c);

    return 0;
}
