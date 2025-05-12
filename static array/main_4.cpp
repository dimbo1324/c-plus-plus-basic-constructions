// 4. Явные и безопасные параметры функций
#include <span>
void process(std::span<const int> data) {
    for (int v : data) …
}
