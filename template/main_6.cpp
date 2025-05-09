/*
Универсальная функция swap с поддержкой ADL и правильным noexcept
*/
#include <iostream>
#include <utility>
#include <type_traits>
#include <windows.h>
/*=====================================================*/
/*=====================================================*/
template <typename T>
void value_swap(T &t, T &u) noexcept(
    noexcept(std::swap(std::declval<T &>(), std::declval<T &>())))
{
    using std::swap;
    swap(t, u);
}
/*=====================================================*/
/*=====================================================*/
int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    /*=====================================================*/
    /*=====================================================*/
    int a = 10;
    int b = 20;
    std::cout << "До swap: a = " << a << ", b = " << b << '\n';
    value_swap(a, b);
    std::cout << "После swap: a = " << a << ", b = " << b << '\n';
    static_assert(noexcept(value_swap(a, b)), "value_swap должен быть noexcept");
    /*=====================================================*/
    /*=====================================================*/
    return 0;
}
