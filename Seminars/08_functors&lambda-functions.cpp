#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct F
{
    bool operator() (int a, int b, int c, int d)
    {
        return a + b + c + d < 0;
    }
};

struct Crit
{
    bool dir = false;
    Crit(bool dir = false) : dir(dir) {}
    bool operator() (int x, int y)
    {
        if (dir) {
            return __builtin_popcount(x) > __builtin_popcount(y);
        }
        return __builtin_popcount(x) < __builtin_popcount(y);
    }
};

auto func(int a, int b) -> bool // альтернативная форма записи функции
{
    return a < b;
}

auto func(double a, double b) -> auto
{
    return a < b;
}

auto func(char a, char b)
{
    return a < b;
}

struct S
{
    bool val = false;
    void sort(std::vector<int> z)
    {
        std::sort(z.begin(), z.end(), [this](auto a, auto b) { // предоставляет доступ к полям структуры
            if (val) return a < b; else return a > b;
        });
    }
};
 
int
main(void)
{
    F f;
    auto r1 = f(1, 2, 3, 4);
    auto r2 = F()(1, 2, 3, 4);
    std::cout << r1 << ' ' << r2 << std::endl;

    std::vector<int> z;
    int x, cnt{};
    while (std::cin >> x && cnt++ == 10) {
        z.push_back(x);
    }
    //std::sort(z.begin(), z.end());
    //std::stable_sort(z.begin(), z.end()); // равные ключи сохраняют положение отн-но друг друга
    std::sort(z.begin(), z.end(), Crit(true)); // сортировка по кол-ву единичных битов
    for (auto x : z) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    // lambda funtions
    std::sort(z.begin(), z.end(), [](int x, int y) -> bool {
        return __builtin_popcount(x) < __builtin_popcount(y);
    });

    std::sort(z.begin(), z.end(), [](int x, int y) {
        return __builtin_popcount(x) < __builtin_popcount(y);
    });

    std::sort(z.begin(), z.end(), [](auto x, auto y) {
        return __builtin_popcount(x) < __builtin_popcount(y);
    });

    bool flag = false;
    std::sort(z.begin(), z.end(), [flag](int x, int y) {
        if (flag) {
            return __builtin_popcount(x) > __builtin_popcount(y);
        }
        return __builtin_popcount(x) < __builtin_popcount(y);
    });

    int res = 1;
    std::for_each(z.begin(), z.end(), [&res](auto x) { res *= x; }); // получаем res = произведение эл-ов вектора
    //std::for_each(z.begin(), z.end(), [=](auto x) { res *= x; }); // "=" копирует все локальные переменные, которые используются в ф-ии
    std::for_each(z.begin(), z.end(), [&](auto x) { res *= x; }); // "&" по ссылке

    auto res2 = std::accumulate(z.begin(), z.end(), 1, std::multiplies<int>()); // res2 = произведение, accumulate лежит в <numeric>

    for (auto x : z) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    std::cout << res << ' ' << res2 << std::endl;

    int a;
    std::cin >> a;
    auto foo = [&res, a](int b) {
        res = a + b;
    };
    int c;
    std::cin >> c;
    foo(c);
    std::cout << res << std::endl;

    return 0;
}
