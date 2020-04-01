#include <functional>

template<typename T>
T
myfilter(const T& cont, std::function<bool (typename T::value_type)> predicate)
{
    T res;
    for (auto x : cont) {
        if (predicate(x)) {
            res.insert(res.end(), x);
        }
    }
    return res;
}
