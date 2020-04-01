class Sum
{
private:
    long long a;
    long long b;
public:
    Sum(long long c, long long d) : a(c), b(d) {}
    Sum(Sum s, long long c) : a(s.a + s.b), b(c) {}
    long long get(void) const {
        return a + b;
    }
};
