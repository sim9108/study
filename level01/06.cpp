import std;
using namespace std;

auto main() -> int {
    vector v = { 1, 2, 3, 4, 5, 6, 7 };

    auto chunk = v | std::views::chunk(2);
    println("{}", chunk);
    return 0;
}