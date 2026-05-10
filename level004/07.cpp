import std;
using namespace std;

expected<int, string> divide(int a, int b) {
    if (b == 0) return unexpected("b is 0"s);
    return a / b;
}

auto main() -> int {
    auto r = divide(10, 0);
    if (r) {
        println("result: {}", *r);
    }
    else {
        println("error: {}", r.error());
    }
    return 0;
}