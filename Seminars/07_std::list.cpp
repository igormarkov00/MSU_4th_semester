#include <iostream>
#include <list>
#include <algorithm>

struct Data
{
    std::string x;
};

struct ListItem
{
    ListItem *prev{}, *next{};
    Data *elem;
};

struct List
{
    ListItem *first{}, *last{};
    size_t size; // since C++11?
}; // реализация списка

int
main(void)
{
    std::list lst{1, 2, 3, 4};
    //std::next, std::prev, std::distance;
    lst.push_front(0);
    for (auto x : lst) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    lst.front();
    lst.back();
    lst.size();
    //sort(lst.begin(), lst.end()); не компилится, т.к. в реализации вычитаются итераторы
    lst.sort();

    std::list<Data> lst2;

    return 0;
}
