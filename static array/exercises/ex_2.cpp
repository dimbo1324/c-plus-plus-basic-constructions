// Задание №2
// Создайте перечисление со следующими перечислителями : chicken, lion, giraffe, elephant, duck и snake.Поместите перечисление в пространство имен.Объявите массив, где элементами будут эти перечислители и, используя список инициализаторов, инициализируйте каждый элемент соответствующим количеством лап определенного животного.В функции main() выведите количество ног у слона, используя перечислитель.
#include <iostream>
using namespace std;
namespace Animals
{
    enum Animals
    {
        chicken,
        lion,
        giraffe,
        elephant,
        duck,
        snake,
        MAX_ANIMALS
    };
}
int main()
{
    int legs[Animals::MAX_ANIMALS] = {2, 4, 4, 4, 2, 0};
    cout << "The number of legs an elephant has: " << legs[Animals::elephant] << endl;
    return 0;
}