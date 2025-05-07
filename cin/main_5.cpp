#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    /*=====================================================*/
    //  5. Обработка исключений при необходимости
    /*=====================================================*/
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    try {
        std::cout << "Введите число с выбросом исключения: ";
        int exNum;
        std::cin >> exNum;
        std::cout << "Введено: " << exNum << "\n";
    } catch (const std::ios_base::failure &e) {
        std::cout << "Исключение при вводе: " << e.what() << "\n";
        // поток можно восстановить
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    /*=====================================================*/
    return 0;
}
