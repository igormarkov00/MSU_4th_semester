#include <iostream>
#include <vector>
 
void
process(const std::vector<unsigned long long> &v, std::vector<unsigned long long> &l, unsigned step)
{
    if (!v.size() || !l.size()) {
        return;
    }
    auto vi = v.begin();
    auto li = l.rbegin();
    do {
        *li += *vi;
        ++li;
        if (li == l.rend() || distance(vi, v.end()) <= int(step)) {
            break;
        }
        advance(vi, step);
    } while (1);
}
