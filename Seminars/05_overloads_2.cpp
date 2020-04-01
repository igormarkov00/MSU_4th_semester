#include <iostream>
#include <cstring>
#include <vector>

//еще немного перегрузки (для осатльных операторов)

class Huy {
    int f();
    friend bool operator< (const Huy &a, const Huy &b);
    // при определении функции в классе компилятор старается ее инлайнить
};

bool operator< (const Huy &a, const Huy&b) {
    /* ... */
}

bool operator== (const Huy &a, const Huy &b) {
    return !(a < b) && !(b < a);
} // все остальные операторы сравнения аналогично через <

class Salam {
public:
    Salam& operator% (const Salam &a) const;
    void f();
};

Salam& operator% (const Salam &a, int);

void Salam::f() {
    Salam &tmp = *this;
    tmp % 12;
    tmp = tmp % 12; // разные вещи (будет ошибка компиляции)
}

class String {
    char *s{};
    int len{};
public:
    /* ... */
    char operator[] (size_t idx) const {
        return s[idx];
    } // для случаев типа   auto c = s[i]
    char& operator[] (size_t idx) {
        return s[idx];
    } // для случаев типа   s[i] = c;
};

class Huli { // класс-функтор
    int sum{};
public:
    void operator()(int a) {
        sum += a;
    }
};

void zamut(void) { // использование функтора
    std::vector <int> zbs;
    Huli yopta;
    for (auto it = zbs.begin(); it < zbs.end(); ++it) {
        yopta(*it);
        yopta.operator()(*it); // то же самое
    }
}

struct T {};

class Ptr {
    T *tp;
public:
    Ptr(T *init) {}
    T operator-> () {}

};

class Vector {
    T *s{};
    int size{}, cap{100};
public:
    Vector() {
        s = static_cast<T*> (::operator new (sizeof(T) * cap));
    }

    void push_back(const T& t) {
        // s[size++] = t; - неверно, тк оператор присвоения нельзя определить над сырой памятью
        new (&s[size++]) T(t); // при условии, что память уже выделена (по-хорошему нужна проверка)
    }

    void pop(void) {
        --size;
        s[size].~T();
    }
};

/*
int main()
{

    return 0;
}
*/
