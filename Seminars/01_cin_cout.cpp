#include <iostream>
#include <cstdint>
#include <iomanip>

int
main(void)
{
	/*//int32_t a = {0}, b = int32_t();
	int32_t a(0), b{};// зануляем при инициализации
	std::cin.operator>>(a).operator>>(b);
	std::cout.operator<<(a).operator<<(b).operator<<(std::endl);*/

	int64_t sum{};
	/*while (1) {
		int a;
		std::cin >> a;
		if (std::cin.eof()) {
			break;
		}
		sum += a;
	}*/
	int a;
	/*while (!(std::cin >> a).eof()) {
		sum += a;
	}*/
	while (std::cin >> a) {
		sum += a;
	}
	std::cout << std::hex << std::setw(10) << std::setfill('0') << sum << ' ' << std::dec << sum << std::endl; // setw - ширина поля вывода
	//printf("%010lx %ld\n", sum, sum);

	/*[[maybe_unused]]
	bool huy = (bool) std::cin;
	bool huy = static_cast<bool>(std::cin);*/

	return 0;
}
