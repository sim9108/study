import std;
using namespace std;

auto main() -> int {
    vector a{ 1, 2, 3 };
    vector b{ 10, 20, 30 };

    for (auto x : views::zip_transform(plus{}, a, b)) {
        print("{} ", x);
    }
}