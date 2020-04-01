#include <iostream>

class Sub
{
private:
    int a;
    int b;
public:
    Sub(int c, int d) : a(c), b(d) {}
    Sub(Sub s, int c) : a(s.a - s.b), b(c) {}
    Sub(int c, Sub s) : a(c), b(s.a - s.b) {}
    int value(void) const {
        return a - b;
    }
};
