#include <iostream>
#include <vector>
 
void
process(std::vector<long long> &v, long long lim)
{
    v.reserve(v.size() * 2);
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        if (*it >= lim) {
            v.push_back(*it);
        }
    }
}
