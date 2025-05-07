#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    /*=====================================================*/
    //  2. Очистка буфера после предыдущих операций (если бы они были)
    /*=====================================================*/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*=====================================================*/
    /*=====================================================*/
    return 0;
}