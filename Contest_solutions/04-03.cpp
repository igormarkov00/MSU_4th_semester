#include <algorithm>
#include <functional>
#include <vector>

template<typename I, typename F>
void
myapply (I it_beg, I it_end, F foo)
{
    for (; it_beg != it_end; ++it_beg) {
        foo(*it_beg);
    }
}

template<typename I, typename F>
std::vector<std::reference_wrapper<typename I::value_type>>
myfilter2 (I it_beg, I it_end, F predicate)
{
    std::vector<std::reference_wrapper<typename I::value_type>> res;
    for (; it_beg != it_end; ++it_beg) {
        if (predicate(*it_beg)) {
            res.insert(res.end(), *it_beg);
        }
    }
    return res;
}

template<typename I, typename F>
void
myapply (I *it_beg, I *it_end, F foo)
{
    for (; it_beg != it_end; ++it_beg) {
        foo(*it_beg);
    }
}

template<typename I, typename F>
std::vector<std::reference_wrapper<I>>
myfilter2 (I *it_beg, I *it_end, F predicate)
{
    std::vector<std::reference_wrapper<I>> res;
    for (; it_beg != it_end; ++it_beg) {
        if (predicate(*it_beg)) {
            res.insert(res.end(), *it_beg);
        }
    }
    return res;
}
