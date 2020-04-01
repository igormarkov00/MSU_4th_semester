#include <iostream>
#include <vector>
#include <map>
#include <functional>

namespace numbers
{

complex eval(const std::vector<std::string> &args, const complex &z) {
    complex_stack stack;
    std::map<std::string, std::function<void(void)>> op
    {
        {"z", [&stack, &z](void) {
            stack = stack << z;
        }},
        {"+", [&stack](void) {
            complex z2 = +stack;
            stack = ~stack;
            complex z1 = +stack;
            stack = ~stack;
            stack = stack << (z1 + z2);
        }},
        {"-", [&stack](void) {
            complex z2 = +stack;
            stack = ~stack;
            complex z1 = +stack;
            stack = ~stack;
            z1 -= z2;
            stack = stack << z1;
        }},
        {"*", [&stack](void) {
            complex z2 = +stack;
            stack = ~stack;
            complex z1 = +stack;
            stack = ~stack;
            stack = stack << (z1 * z2);
        }},
        {"/", [&stack](void) {
            complex z2 = +stack;
            stack = ~stack;
            complex z1 = +stack;
            stack = ~stack;
            stack = stack << (z1 / z2);
        }},
        {"!", [&stack](void) {
            complex z1 = +stack;
            stack = stack << z1;
        }},
        {";", [&stack](void) {
            stack = ~stack;
        }},
        {"~", [&stack](void) {
            complex z1 = ~(+stack);
            stack = ~stack;
            stack = stack << z1;
        }},
        {"#", [&stack](void) {
            complex z1 = -(+stack);
            stack = ~stack;
            stack = stack << z1;
        }}
    };
    for (auto x : args) {
        if (x.size() == 1) {
            op[x]();
        } else {
            stack = stack << complex(x);
        }
    }
    complex w = +stack;
    return w;
}

}
