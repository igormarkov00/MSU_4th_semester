#include <iostream>

namespace huy::eba
{

int
foo(int a, int b);

}

int
huy::eba::foo(int a, int b)
{
	return a + b;
}

int
main(void)
{
	auto a = 1;
	auto b = a + 1;
	std::cout << huy::eba::foo(a, b) << std::endl;

	return 0;
}
