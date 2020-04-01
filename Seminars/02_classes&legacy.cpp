#include <iostream>

void f(int *a, size_t n); // плохо

struct Range
{
	int *a;
	size_t n;
};

struct Square
{
	int a;
	int b;//a == b
}

void
print(Range r)
{
	for (size_t i = 0; i < r.n; ++i) {
		std::cout << r.a[i] << ' ';
	}
}

///

class RandomGenerator
{
private:
	int call_count_;
	int seed_;
public:
	int next();
	RandomGenerator(int seed);
	~RandomGenerator() {}
	int getCallCount() {
		return call_count_;
	}
};

class String
{
	char *s;
	size_t len;
	//char s[MAXLEN]; // лучше, поскольку фиксированное кол-во памяти
public:
	String(const char seed_);
	~String();
	size_t Length() const{ // не меняем состояние объекта класса внутри
		return len;
	}
};

String::String(const char *s) {
	String::s = new char[strlen(s)];// оператор выделения память в куче, преимущество: выделяется память
	// даже для пользовательских типов данных + сразу вызывается конструктор
	strcpy(this->s, s);
}

//наследие

class Random
{
public:
	virtual int next(int n);
	Random() {};
};

class RandomDev : Random
{
	FILE *f;
public:
	virtual int next(int n)
	{
		unsigned int val;
		fread(&val, sizeof(val), 1, f_);
		return (int)(val / UINT_MAX * n);
	}
	RandomDev();
	~RandomDev()
	{
		fclose(f_);
	}
};

class RandomRand : Random
{
public:
	virtual int next(int n)
	{
		//
	}
}

int
main(void)
{


	return 0;
}
