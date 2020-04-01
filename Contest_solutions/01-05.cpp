int
main()
{
    int count;
    std::cin >> count;
    Holder *mas = new Holder[count];
    for (int i = 0; i < count / 2; ++i) {
        mas[i].swap(mas[count - 1 - i]);
    }
    delete[] mas;

    return 0;
}
