#include <iostream>
#include <vector>
#include <type_traits>
#include <utility>

template <typename T1, class T2>
void func(T1 a, T2 b) {}

template <typename T1, uint64_t val = 1024>
void func2(T1 a)
{
   std::cout << "func2: " << val << ' ' << a << std::endl;
}

enum class E
    {
        A, B
    };

template <typename T1, E e = E::A>
void func3(T1 a) {}

constexpr int *ff() { return nullptr; }

template <typename T1, int *val = ff()>
void func4(T1 a)
{
   std::cout << "func4: " << a << std::endl;
}

template <typename R, typename T>
auto my_cast(T a) -> R
{
    return R(a);
}

template <typename It>
auto sum(It beg, It end)
{
    auto res = 0;
    for (; beg != end; ++beg){
        res += *beg;
    }
    return res;
}

template <typename It, typename S = typename It::value_type>
auto correct_sum(It beg, It end)
{
    S res{};
    for (; beg != end; ++beg){
        res += *beg;
    }
    return res;
}

template <typename P, typename S = P>
auto correct_sum(const P *beg, const P *end)
{
    S res{};
    for (; beg != end; ++beg) {
        res += *beg;
    }
    return res;
}

template <typename It, typename S = typename std::iterator_traits<It>::value_type>
auto un_sum(It beg, It end)
{
    S res{};
    for (; beg != end; ++beg){
        res += *beg;
    }
    return res;
}

template <typename It, typename S = decltype(*std::declval<It>)>
auto another_sum(It beg, It end)
{
    S res{};
    for (; beg != end; ++beg){
        res += *beg;
    }
    return res;
}

int
main(void)
{
    func2<int, 1000>(1);
    func2(2);
    func4(10);
    
    auto z = my_cast<double>(10);
    std::cout << "z = " << z << std::endl;

    std::vector v1{1, 2, 3};
    std::vector<int>::value_type r = v1.front();
    decltype(v1)::value_type r1 = v1.front(); // auto r1 = v1.front();

    decltype(v1) v2{v1}; // auto v2{v1};
    // отличия auto от decltype:
    // 1) decltype может исп-ся как пространство имен
    // 2) см. ниже
    std::vector<int> &v4{v1};
    const std::vector<int> &v5{v1};
    auto v6{v4};
    v6[0] = 100;
    std::cout << v1[0] << std::endl;
    decltype(v4) v7{v4};
    v7[0] = 100;
    std::cout << v1[0] << std::endl;
    // decltype сохраняет ссылочность, auto - нет

    std::cout << sum(v1.begin(), v1.end()) << std::endl;
    std::vector<std::string> vv8{"a", "b", "cd"};
    //std::cout << sum(vv8.begin(), vv8.end()) << std::endl; // не скомпилится
    std::cout << correct_sum(vv8.begin(), vv8.end()) << std::endl; // скомпилится
    std::vector<int> v{int(1e9), int(1e9), int(1e9)};
    std::cout << correct_sum<decltype(v)::iterator, int64_t> (v.begin(), v.end())
            << std::endl; // суммирую вектор интов в 64-битное число
    int mas[] = {int(1e9), int(1e9), int(1e9)};
    std::cout << correct_sum<int, int64_t> (mas, mas + sizeof(mas) / sizeof(mas[0])) << std::endl;

    std::cout << un_sum<decltype(v)::iterator, int64_t> (v.begin(), v.end()) << std::endl;
    std::cout << un_sum<int*, int64_t> (mas, mas + sizeof(mas) / sizeof(mas[0])) << std::endl;
    
    std::cout << another_sum<int*, int64_t> (mas, mas + sizeof(mas) / sizeof(mas[0])) << std::endl;
    

    return 0;
}
