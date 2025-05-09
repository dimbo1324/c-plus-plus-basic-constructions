// Задание №1
// Объявите массив для хранения температуры(дробное число) каждого дня в году(всего 365 дней).Проинициализируйте массив значением 0.0 для каждого дня.
#include <iostream>
using namespace std;
int main()
{
    const unsigned short int days = 365;
    const double defaultTemp = 0.0;
    double temp[days] = {defaultTemp};
    for (int i = 0; i < days; i++)
    {
        cout << "Day " << i + 1 << "temperature is " << temp[i] << " degrees" << endl;
    }
    return 0;
}