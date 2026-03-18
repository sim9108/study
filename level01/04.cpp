import std;
using namespace std;

auto main() -> int {
    vector keys = { 1, 2, 3 };
    vector values = { "one", "two", "three" };

    for (auto [k, v] : views::zip(keys, values)) {
        std::println("{} → {}", k, v);
    }
    return 0;
}