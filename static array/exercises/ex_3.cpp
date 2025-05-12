// Задание №1 Выведите на экран следующий массив с помощью цикла: int array[] = {7, 5, 6, 4, 9, 8, 2, 1, 3};
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// Вариант 1
// #include <iostream>
// using namespace std;
// int main()
// {
//     int array[] = {7, 5, 6, 4, 9, 8, 2, 1, 3};
//     for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//     {
//         cout << array[i] << endl;
//     }
//     return 0;
// }
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// Вариант 2
#include <iostream>
#include <array>
#include <span>
#include <ranges>    // std::ranges::for_each
#include <algorithm> // std::copy
#include <iterator>  // std::ostream_iterator

int main()
{
    // исходный массив
    int raw[] = {7, 5, 6, 4, 9, 8, 2, 1, 3};

    // 1) Через std::ranges::for_each и std::span (C++20)
    //    — std::span хранит и длину, и ptr, не деградирует
    // std::cout << "Вывод через ranges::for_each + span:\n";
    // std::ranges::for_each(std::span(raw), [](int x)
    //                       { std::cout << x << '\n'; });

    std::cout << '\n';

    // 2) Через std::copy и ostream_iterator (универсально с любым контейнером)
    std::cout << "Вывод через std::copy + ostream_iterator:\n";
    std::copy(
        std::begin(raw),
        std::end(raw),
        std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}