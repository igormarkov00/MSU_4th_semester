namespace numbers
{
    
class complex_stack
{
    complex *st;
    size_t real_sz{};
    size_t sz{1};
public:
    complex_stack(void) {
        st = static_cast<complex*>(::operator new(sizeof(complex)));
        st[0] = complex();
    }
    complex_stack(const complex_stack &cs) {
        real_sz = cs.real_sz;
        sz = cs.sz;
        st = static_cast<complex*>(::operator new(sz * sizeof(complex)));
        for (size_t i = 0; i < real_sz; ++i) {
            st[i] = cs.st[i];
        }
    }
    ~complex_stack(void) {
        ::operator delete(st);
    }
    size_t size(void) const {
        return real_sz;
    }
    complex operator[](int idx) const {
        return st[idx];
    }
    complex_stack operator<< (const complex &z) const {
        complex_stack new_cs = *this;
        if (real_sz == sz) {
            new_cs.sz *= 2;
            complex *new_st = static_cast<complex*> (::operator new(new_cs.sz * sizeof(complex)));
            for (size_t i = 0; i < sz; ++i) {
                new_st[i] = st[i];
            }
            ::operator delete(new_cs.st);
            new_cs.st = new_st;
        }
        new_cs.st[new_cs.real_sz++] = z;
        return new_cs;
    }
    complex operator+ (void) const {
        return st[real_sz - 1];
    }
    complex_stack operator~ (void) const {
        complex_stack new_cs = *this;
        new_cs.st[new_cs.real_sz--] = complex();
        return new_cs;
    }
    
    void operator= (const complex_stack& stack) {
        if (this == &stack) {
            return;
        }
        ::operator delete(st);
        st = static_cast<complex*>(::operator new(stack.sz * sizeof(*stack.st)));
        sz = stack.sz;
        real_sz = stack.real_sz;
        for (size_t i = 0; i < real_sz; ++i) {
            st[i] = stack.st[i];
        }
    }
    friend std::ostream& operator<< (std::ostream& out, const complex_stack& stack);
};

std::ostream& operator<< (std::ostream& out, const complex_stack& stack) {
    out << "STACK: ";
    if (!stack.size()) {
        out << "empty!\n";
        return out;
    }
    for (size_t i = 0; i < stack.size(); ++i) {
        out << stack.st[i] << ' ';
    }
    out << std::endl;
    return out;
}

}