import std;
using namespace std;

auto main() -> int {
    vector v = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    for (auto x : v | views::stride(3)) {
        print("{} ", x);
    }
    return 0;
}