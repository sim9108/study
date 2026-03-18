import std;
using namespace std;

auto main() -> int {
    vector v = { 1, 2, 3, 4, 5 };

    for (auto window : v | views::slide(3)) {
        println("{}", window);
    }
    return 0;
}