// 2. Используйте uniform init и brace-elision
int raw[5]{};              // все 0
std::array<int,5> sa{5,6}; // первые два заданы, остальные 0
