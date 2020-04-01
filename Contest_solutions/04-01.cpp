#include <iostream>

template<typename T>
typename T::value_type
process(const T& cont)
{
    typename T::value_type res{};
    if (cont.begin() == cont.end()) {
        return res;
    }
    auto it = cont.rbegin();
    res = *it;
    do {
        if (std::distance(it, cont.rend()) <= 2 || distance(cont.rbegin(), it) >= 4) {
            break;
        }
        ++it;
        ++it;
        res += *it;
    } while (1);
    return res;
}
