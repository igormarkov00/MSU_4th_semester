#include <iostream>
#include <cstring>
#include <algorithm>
//перегрузка функций
void print(long);
void print(const char*);
void print(double);

void
f(void)
{
    print(1L);
    print(2.0);
    print(3); // неоднозначный вызов
}
//критерии поиска подходящей функции:
// 1) точное соответствие (exact match)
// 2) продвижение типов (type promotion)
// 3) пребразование типов (type conversion)
// *4) пользовательское преобразование
// основной критерий - сохранить значение переменной
//если аргументов несколько:
// 1) кол-во параметров
// 2) для каждого параметра свой тип соответствия
// 3) программа компилируется только если сущ. ровно одна функция, 
//      "побеждающая" по всем параметрам

//перегрузка операторов
class Int
{
    int m_Value;
public:
    Int(int in_Value) : m_Value(in_Value) {}
    operator int() { return m_Value; }
};

class Complex
{
    int m_Real;
    int m_Imag;
public:
    Complex(int a) : m_Real(a) {}
    Complex(int a, int b) : m_Real(a), m_Imag(b) {}
    /* ... */
    Complex operator+ (const Complex& in_Target) const {
        return Complex(m_Real + in_Target.m_Real, 
                m_Imag + in_Target.m_Imag);
    }
};

void
g(void)
{
    Int x = 0;
    x = 5;
    x.operator=(5);
    std::cout << x;
    std::cout.operator<<(x.operator int());
    Complex a(0);
    a = a + 2;
    a.operator+(Complex(2));
}
//пишем класс строк с оператором присваивания

class String {
    size_t len{};
    char *s{};
public:
    String(const char *s_) : len(strlen(s_)) {
        s = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            s[i] = s_[i];
        }
        s[len] = '\0';
    }
    
    String (const String &x) : String(x.s) {}

    String& operator= (String x) {
        std::swap(x.s, s);
        std::swap(x.len, len);
        return *this;
    }

    String& operator+= (String x) {
        //на след семе
    }

    ~String() {
        if (s) {
            delete[] s;
        }
    }
};

int main()
{
    

    return 0;
}
