// 5. Применяйте алгоритмы и ranges
#include <numeric>
int total = std::accumulate(sa.begin(), sa.end(), 0);
auto mx = *std::ranges::max_element(sa);
