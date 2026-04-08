import std;
using namespace std;

template <typename T>
void integral_type(T val) {
    if constexpr (integral<T>) {
        println("integral");
    }
    else {
        println("not integral");
    }
}

template <typename T>
void test_check(T val) {
    if constexpr (requires {val.test(); }) {
        println("function found");
    }
    else {
        println("function not found");
    }
}

struct A {};
struct B { void test() {} };

auto main() -> int {
    integral_type(10);
    integral_type(3.14);

    test_check(A{});
    test_check(B{});
    return 0;
}