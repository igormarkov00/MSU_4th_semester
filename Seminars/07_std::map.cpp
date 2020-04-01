#include <iostream>
#include <map>
#include <string>

int
main(void)
{
    std::map<std::string, int> m1;

    m1.size();
    m1["a"] = 10;
    std::cout << m1["a"] << std::endl;
    std::cout << m1["b"] << std::endl; // новый эл-т добавляется
    std::cout << m1.count("c") << std::endl; // новый эл-т не добавляется

    {
        std::map<std::string, int>::iterator it = m1.find("a");
        if (it != m1.end()) {
            std::cout << it->second << std::endl;
        }
    }
    if (auto it = m1.find("a"); it != m1.end()) {
        std::cout << it->second << std::endl;
    }

    auto const &m2 = m1;
    //std::cout << m2["a"]; // нельзя
    if (auto it = m2.find("a"); it != m2.end()) {
        std::cout << it->second << std::endl;
    }
    m1.insert({ "d", 100500 }); // emplace и insert возвращают пару {итератор, bool был ли элемент в map}
    std::cout << m1["d"] << std::endl;
    static const std::map<double, int> m3{
        { 3.4, 2 },
        { 1.2, 11 }
    };
    for(auto it = m2.begin(); it != m2.end(); ++it) {
        std::cout << it->first << ", " << it->second << std::endl;
    }
    for (const auto &p : m2) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
    for(auto& [ key, value ] : m2) {
        std::cout << key << ", " << value << std::endl;
    }
    // try_emplace вставляет, если эл-та не было в map

    return 0;
}
