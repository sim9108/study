import std;
using namespace std;

auto main() -> int {
    for (vector v = { 1, 2, 3, 4, 5 }; auto x : v) {
        println("{}", x);
    }

    return 0;
}