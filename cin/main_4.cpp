#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    /*=====================================================*/
    //  4. Чтение с помощью stringstream для дополнительной валидации
    /*=====================================================*/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string line;
    std::cout << "Введите целое число (альтернативно): ";
    std::getline(std::cin, line);

    std::istringstream iss(line);
    long long largeNum;
    char extra;
    if ((iss >> largeNum) && !(iss >> extra)) {
        std::cout << "Успешно: " << largeNum << "\n";
    } else {
        std::cout << "Неверный формат ввода!\n";
    }
}

/*=====================================================*/
return
0;
}
