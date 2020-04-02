#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <utility>

void
change(std::set<std::pair<unsigned, std::pair<unsigned, unsigned>>> &mx, 
        std::vector<std::vector<unsigned>> &v, unsigned x, unsigned y, unsigned edit_val)
{
    if (x >= v.size() || y >= v[x].size()) {
        return;
    }
    mx.erase({-1U - v[x][y], {x, y}});
    v[x][y] = (v[x][y] > edit_val? v[x][y] - edit_val : 0);
    mx.insert({-1U - v[x][y], {x, y}});
}

void
make_edit(std::set<std::pair<unsigned, std::pair<unsigned, unsigned>>> &mx, 
        std::vector<std::vector<unsigned>> &v, unsigned edit_val)
{
    auto [x, y] = mx.begin()->second;
    //std::cout << "Edit is being made with value = " << edit_val << " on (" << x << "," << y << ")" << std::endl;
    std::vector<unsigned> x_shift{-1U, -1U, -1U, 0, 0, 0, 1, 1, 1},
            y_shift{-1U, 0, 1, -1U, 0, 1, -1U, 0, 1};
    for (unsigned i = 0; i < x_shift.size(); ++i) {
        change(mx, v, x + x_shift[i], y + y_shift[i],
                edit_val / (1 * (x_shift[i]? 2 : 1) * (y_shift[i]? 2 : 1)));
    }  
}
 
int
main(void)
{
    std::vector<std::vector<unsigned>> v;
    std::set<std::pair<unsigned, std::pair<unsigned, unsigned>>> mx;
    std::string s;
    unsigned x{}, u;
    while (getline(std::cin, s) && !s.empty()) {
        v.push_back({});
        std::stringstream in(s);
        unsigned y{};
        while (in >> u) {
            v.back().push_back(u);
            mx.insert({-1U - u, {x, y}});
            ++y;
        }
        ++x;
    }

    std::vector<unsigned> edit;
    while (std::cin >> u) {
        edit.push_back(u);
    }
    sort(edit.rbegin(), edit.rend());
    for (auto edit_val : edit) {
        make_edit(mx, v, edit_val);
    }

    for (auto x : v) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    } 

    return 0;
}
