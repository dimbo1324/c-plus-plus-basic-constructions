// 3. std::size, std::empty, std::data вместо sizeof
constexpr auto n = std::size(raw);
for (auto& x : sa) { … }
