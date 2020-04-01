#include <iostream>

class A
{
private:
    int a;
    bool is_sum = false;
public:
    A(void) {
        std::cin >> a;
    }
    A(A &other) {
        std::cin >> a;
        a += other.a;
        is_sum = true;
    }
    ~A(void) {
        if (is_sum == true) {
            std::cout << a << std::endl;
        }
    }
};
