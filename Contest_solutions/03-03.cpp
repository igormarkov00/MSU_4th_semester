#include <iostream>
#include <vector>
#include <algorithm>

void
process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> nums{v1.begin(), v1.end()};
    std::sort(nums.begin(), nums.end());
    auto new_end = std::unique(nums.begin(), nums.end());
    nums.erase(new_end, nums.end());
    int sz = v2.size();
    auto rd = v2.begin(), wr = v2.begin();
    auto cur = nums.begin();
    while (cur != nums.end() && *cur < 0) {
        cur++;
    }
    int i;
    for (i = 0; i < sz; ++i) {
        if (cur == nums.end()) {
            break;
        }
        if (i == *cur) {
            rd++;
            cur++;
            continue;
        }
        *wr = *rd;
        wr++;
        rd++;
    }
    for (int j = i; j < sz; ++j) {
        *wr = *rd;
        wr++;
        rd++;
    }
    v2.erase(wr, v2.end());
}
