#include <bits/stdc++.h>

class huy {
    int length;
public:
    huy(int l) : length(l){

    }
    int get_len(void) const {
        return length;
    }
};

class Year {
    int year_;
public:
    explicit Year (int year) : year_(year) {}
    int get();
};

class Date {
    int day_;
    int mon_;
    int year_;
public:
    
};

class Station {
/// code
};

class Ticket
{
    static int totalCount;
public:
    Ticket(const Station &from, const Station &to) {
        ++totalCount;
    }
    ~Ticket() {
        --totalCount;
    }
};

int
main(void)
{
    huy mine(20);
    std::cout << mine.get_len() << std::endl;

    return 0;
}
