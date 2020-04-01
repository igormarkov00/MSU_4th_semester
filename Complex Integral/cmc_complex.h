namespace numbers
{

constexpr int ACC = 10;

class complex{
    double re_;
    double im_;
public:
    complex(double a = 0, double b = 0) : re_(a), im_(b) {}
    explicit complex (const std::string &s) {
        std::stringstream sin(s);
        sin.ignore(1);
        sin >> re_;
        sin.ignore(1);
        sin >> im_;
    }
    double re(void) const {
        return re_;
    }
    double im(void) const {
        return im_;
    }
    double abs2(void) const {
        return re_ * re_ + im_ * im_;
    }
    double abs(void) const {
        return sqrt(re_ * re_ + im_ * im_);
    }
    std::string to_string (void) const {
        std::stringstream s;
        s << '(' << std::setprecision(10) << re_ <<  ','
                << std::setprecision(10) << im_ << ')';
        return s.str();
    }
    complex operator~ (void) const {
        return {re_, -im_};
    }
    complex operator- (void) const {
        return {-re_, -im_};
    }

    complex operator+= (const complex right) {
        re_ += right.re_;
        im_ += right.im_;
        return *this;
    }
    complex operator-= (const complex right) {
        re_ -= right.re_;
        im_ -= right.im_;
        return *this;
    }
    complex operator*= (const complex right) {
        double old_re = re_;
        re_ = re_ * right.re_ - im_ * right.im_;
        im_ = old_re * right.im_ + im_ * right.re_;
        return *this;
    }
    complex operator/= (const complex right) {
        (*this) *= (~right);
        im_ /= right.abs2();
        re_ /= right.abs2();
        return *this;
    }
};

complex operator+ (complex left, const complex right)
{
    return (left += right);
}

complex operator- (complex left, const complex right)
{
    return (left -= right);
}

complex operator* (complex left, const complex right)
{
    return (left *= right);
}

complex operator/ (complex left, const complex right)
{
    return (left /= right);
}

std::ostream& operator<< (std::ostream &out, const complex z) {
    out << z.to_string();
    return out;
}

}