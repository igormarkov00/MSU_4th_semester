#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

class Avg
{
    double sum{};
    double cnt{};
public:
    Avg (void) {}
    void operator() (double d) {
        sum += d;
        cnt++;
    }
    double get_avg(void) const {
        return sum / cnt;
    }
};

int
main(int argc, char* argv[])
{
    std::vector<double> v;
    double d;
    while (std::cin >> d) {
        v.push_back(d);
    }
    int shift = v.size() / 10;
    std::sort(v.begin() + shift, v.end() - shift);
    shift += (v.size() - 2 * shift) / 10;
    Avg res = std::for_each(v.begin() + shift, v.end() - shift, Avg());
    std::cout << std::fixed << std::setprecision(10) << res.get_avg() << std::endl;

    return 0;
}
