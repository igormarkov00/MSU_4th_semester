#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    constexpr int APPR = 10;
    double avg = 0, qdr1 = 0, qdr2 = 0, cur, cnt = 0;
    while (std::cin >> cur) {
        avg += cur;
        cnt++;
        qdr1 += cur * cur;
        qdr2 += cur;
    }
    avg /= cnt;
    qdr1 = sqrt((qdr1 - 2 * avg * qdr2) / cnt + avg * avg);
    std::cout << std::fixed << std::setprecision(APPR) << avg << std::endl << qdr1 << std::endl;

    return 0;
}
