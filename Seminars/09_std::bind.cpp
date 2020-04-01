#include <iostream>
#include <functional>
#include <string>
#include <tuple>

void
f(const std::string &s, int a, int b) {
    std::cout << "f: " << s << ' ' << a + b << std::endl;
}

struct func
{
    int operator() (std::string s, int a) {
        std::cout << "func(int): " << s << ' ' << a << std::endl;
        return 3;
    }
    std::string operator() (std::string s, double f) {
        std::cout << "func(double): " << f << std::endl;
        return s;
    }
};

struct A
{
    int f(int a) {
        std::cout << "A::f: " << a << std::endl;
        return 0;
    }
};

int g(int a, int b) {
    std::cout << "g: " << std::endl;
    return 42;
}

int
main(void)
{
    std::string big_str = "44444444";
    auto f1 = std::bind(f, big_str, std::placeholders::_2, std::placeholders::_1);
    // первые два аргумента известны сейчас, посследний передается потом (ff - функтор от двух переменной(_1, _2))
    f1(2, 40); // строка копируется, несмотря на то, что была передана по ссылке

    auto ff = std::bind(f, std::cref(big_str), std::placeholders::_2, std::placeholders::_1);
    ff(2, 40);

    auto f2 = std::bind(func(), "aaa", std::placeholders::_1);
    f2(3, 4); // второй аргумент просто ничего не будет значить
    f2(3.);

    auto f3 = std::bind(f, std::placeholders::_1, bind(func(), std::placeholders::_1, 4), std::placeholders::_2);
    f3(big_str, 5);
    f(big_str, func()(big_str, 4), 5); // эквивалентно двум строчкам выше

    auto f4 = std::bind(&A::f, std::placeholders::_1, 15);
    A a;
    f4(a);

    A b;
    auto ff4 = std::bind(&A::f, b, 15);
    ff4();

    auto f5 = std::mem_fn(&A::f); // профит в том, что мы получаем из метода класса функтор => можем его исп-ть
    f5(a, 228);

    std::apply<int(int, int), std::tuple<int, int>>, std::placeholders::_1,
            std::forward_as_tuple(4, 5);
    auto f6 = std::bind(std::apply<int(int, int), std::tuple<int, int>>, std::placeholders::_1,
            std::forward_as_tuple(4, 5));
    f6(g);

    return 0;
}
