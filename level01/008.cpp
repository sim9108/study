import std;
using namespace std;

auto main() -> int {
    vector v = { 1, 2, 3, 4, 5 };

    for (auto [a, b] : views::adjacent<2>(v)) {
        println("{} {}", a, b);
    }
    return 0;
}