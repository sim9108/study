import std;
using namespace std;

template <typename T>
void check_type(T val) {
    if constexpr (integral<T>) {
        println("integral");
    }
    else {
        println("not integral");
    }
}

auto main() -> int {
    check_type(10);
    check_type(3.14);
    return 0;
}