#include <iostream>
#include <array>
#include <vector>

int
main(void)
{
    constexpr int SIZE = 10;
    std::array<int, SIZE> arr  // присваивание по названию, изначально обнулен
                               //передается по значению полностью
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    int arr2[SIZE];
    std::array arr3{1, 2, 3};
    //классификация указателей:
    // 1) random access iterator (~сишные указатели, т.е. доступ к произвольному эл-ту по итер-ру)
    // 2) bidirectional oterator (ходим только на один шаг вперед или назад)
    // 3) input/output iterator (ходим только в одну сторону)
    std::array<int, SIZE>::iterator i1 = arr.begin();
    std::array<int, SIZE>::const_iterator i2 = arr.cbegin();
    std::array<int, SIZE>::reverse_iterator i3 = arr.rbegin();
    std::array<int, SIZE>::const_reverse_iterator i4 = arr.crbegin(); //писать auto

    for (auto ii = arr.begin(); ii != arr.end(); ++ii) {
        std::cout << ++*ii << std::endl; // 2 3 4...
    }
    for (auto ii = arr.cbegin() + 2; ii != arr.cend() - 3; ++ii) {
        std::cout << *ii << std::endl; // 4 5 6 7 8
    }
    for (auto ii = arr.rbegin(); ii != arr.rend(); ++ii) {
        std::cout << *ii << std::endl; // 10 9 8...
    }
    for (auto ii = std::next(arr.begin(), 3); ii != std::prev(arr.end() - 2); std::advance(ii, 1)) {
        std::cout << ++*ii << std::endl; // 2 3 4...
    }
    for (auto v : arr) {
        std::cout << ++v << std::endl; // 2 3 4...
    }
    for (auto &v : arr) {
        std::cout << ++v << std::endl; // 2 3 4... с присвоением
    }

    std::vector v1{1, 2, 3};
    std::vector <std::string> v2{"a", "b", "c"};
    std::vector<double> v3(10, 0.5); // 0.5 0.5...
    std::cout << v2.size() << std::endl;
    std::cout << v2.capacity() << std::endl;

    double z;
    while (std::cin >> z) {
        v3.push_back(z);
        // v3.shrink_to_fit(); // уменьшить capacity до size
        std::cout << v3.size() << ", " << v3.capacity() << std::endl;
        if (!z) {
            break;
        }
    }
    v3.erase(v3.begin(), v3.begin() + 3);
    //v2.insert(v2.begin(), v2.begin(), v2.end()); // так не надо
    std::cout << v2.front() << ' ' << v2.back() << std::endl; // a c
    v2.pop_back(); // void-функция

    return 0;
}
