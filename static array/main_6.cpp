#include <iostream>
#include <array>
#include <span>
#include <numeric>      // std::accumulate
#include <algorithm>    // std::ranges::max_element
#include <iterator>     // std::size
#include <ranges>       // C++20 ranges
#include <type_traits>  // для std::to_array

int foo(const int raw[], std::size_t n) {
    // просто считает сумму, не меняя исходный массив
    int sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += raw[i];
    }
    return sum;
}

int bar(std::span<const int> s) {
    // считает сумму с помощью std::accumulate
    return std::accumulate(s.begin(), s.end(), 0);
}

int main() {
    // 1. Uniform init & zero-fill
    int a1[5]{4, 5, 8, 9, 12};
    int a2[5]{}; // все нули

    std::cout << "a1: ";
    for (auto x : a1) std::cout << x << ' ';
    std::cout << "\na2: ";
    for (auto x : a2) std::cout << x << ' ';
    std::cout << "\n\n";

    // 2. Авто-длина через std::to_array (C++20)
    constexpr auto arr = std::to_array<int>({10, 20, 30});
    std::cout << "arr: ";
    for (auto x : arr) std::cout << x << ' ';
    std::cout << "\narr.size() = " << arr.size() << "\n\n";

    // 3. Именованные индексы через enum
    namespace St {
        enum Names { A, B, C, COUNT };
    }
    std::array<int, St::COUNT> scores{}; // все нули
    scores[St::B] = 42;
    std::cout << "scores: ";
    for (auto x : scores) std::cout << x << ' ';
    std::cout << "\n(scores[B] = " << scores[St::B] << ")\n\n";

    // 4. Защита функции от изменения
    int raw[] = {1, 2, 3, 4, 5};
    std::size_t raw_n = std::size(raw); // безопасно получаем длину

    int sum1 = foo(raw, raw_n);
    int sum2 = bar(std::span<const int>(raw, raw_n));

    std::cout << "sum via foo(raw): " << sum1 << "\n";
    std::cout << "sum via bar(span): " << sum2 << "\n\n";

    // 5. Итерация и алгоритмы
    std::array<int, 5> sa{1, 4, 6, 8, 10};

    // 5.1 Ручной цикл
    int total = 0;
    for (std::size_t i = 0; i < sa.size(); ++i) {
        total += sa[i];
    }
    std::cout << "total via for-loop: " << total << "\n";

    // 5.2 std::accumulate
    int total2 = std::accumulate(sa.begin(), sa.end(), 0);
    std::cout << "total via accumulate: " << total2 << "\n";

    // 5.3 std::ranges::max_element
    auto maxIt = std::ranges::max_element(sa);
    if (maxIt != sa.end()) {
        std::cout << "max via ranges::max_element: " << *maxIt << "\n";
    }

    return 0;
}
