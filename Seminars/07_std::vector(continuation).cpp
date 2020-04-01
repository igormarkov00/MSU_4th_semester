#include <iostream>
#include <vector>
#include <algorithm>

class A
{
public:
    A(const A&) = delete;
    A(int, int) {}
    int a;
};

struct reversed
{
    std::vector <int> &v;
    reversed(std::vector<int>& a) : v(a) {}
    auto begin(void) {
        return v.rbegin();
    }
    auto end(void) {
        return v.rend();
    }
};

struct proxy
{
    std::vector<int> &v;
    proxy(std::vector<int>& v) : v(v) {}
    auto operator= (int a) {
        v.push_back(a);
    }
};

struct inserter
{
    typedef int value_type;
    std::vector<int> &v;
    inserter(std::vector<int>& v) : v(v) {}
    auto operator++ (void) {
        return *this;
    }
    proxy operator* (void) {
        return proxy(v);
    }
};

template<>
struct std::iterator_traits<inserter>
{
    typedef int value_type;
};

struct Unit
{
    std::string s{};
    Unit(std::string s) : s(s) {}
    Unit(void) {}
};

int
main(void)
{
    //std::vector<A> v;//компилируется
    //v.emplace_back(A{1, 1}); // тоже
    std::vector<int> a = {1, 2, 3};
    for (auto x : reversed(a)) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for_each(a.begin(), a.end(), [](int &a) { ++a; }); // можно менять эл-ты

    std::vector<int> b;
    copy(a.rbegin(), a.rend(), inserter(b)); // b = 4 3 2
    copy(a.rbegin(), a.rend(), back_inserter(b));// то же самое, b = 4 3 2 4 3 2
    b.erase(std::remove(b.begin(), b.end(), 2), b.end()); // b = 4 3 4 3
    for (auto x : b) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    /*std::vector<Unit> e;
    std::copy(istream_iterator<Unit>(cin), istream_iterator<Unit>(),
            back_inserter(e));
    std::vector<Unit>::iterator it = find(e.begin(), e.end(), Unit("Monk"));*/

    return 0;
}
