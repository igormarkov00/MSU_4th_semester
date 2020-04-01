#include <iostream>
#include <functional>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <map>
#include <vector>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

#define _USE_MATH_DEFINES

int
main(int argc, char *argv[])
{
    numbers::complex c{std::string(argv[1])};
    std::stringstream in(std::string(argv[2]) + " " + std::string(argv[3]));
    int n;
    double r;
    in >> r >> n;
    std::vector<std::string> foo{&argv[4], &argv[argc]};
    numbers::complex res{};
    double fi = (-2) * M_PI / n;
    for (int i = 0; i < n; ++i) {
        fi += 2 * M_PI / n;
        numbers::complex f_val = numbers::eval(foo, c + 
                numbers::complex{r * cos(fi), r * sin(fi)});
        res += f_val * numbers::complex
                {2 * M_PI / n * (-sin(fi)), 2 * M_PI / n * (cos(fi))};
    }
    std::cout << res.to_string() << std::endl;

    return 0;
}

