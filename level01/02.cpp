import std;
using namespace std;

expected<int, string> divide(int a, int b) {
    if (b == 0) return unexpected("b is 0"s);
    return a / b;
}

int main() {
    auto r = divide(10, 0);
    if (r) std::println("결과: {}", *r);
    else   std::println("오류: {}", r.error());
}