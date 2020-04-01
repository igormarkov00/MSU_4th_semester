#include <algorithm>
#include <set>
template<typename T, typename F>
auto
myremove(F del_beg, F del_end, T bg, T en)
{
    std::set <typename F::value_type> s{del_beg, del_end};
    auto del = std::lower_bound(s.begin(), s.end(), 0);
    auto rd = bg, wr = bg;
    for (; rd != en && del != s.end(); ++rd) {
        if (int(*del) == distance(bg, rd)) {
            del++;
        } else {
            auto tmp = wr;
            std::swap(*rd, *tmp);
            std::swap(*tmp, *wr);
            ++wr;
        }
    }
    for (; rd != en; ++rd, ++wr) {
        auto tmp = wr;
        std::swap(*rd, *tmp);
        std::swap(*tmp, *wr);
    }
    return wr;
}
