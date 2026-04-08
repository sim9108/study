import std;

auto main() -> int {
    using namespace std;
    using namespace std::ranges;

    auto v = views::iota(1, 6)          // 1,2,3,4,5
        | views::transform([](int x) { return x * x; })
        | to<std::vector>();  // {1,4,9,16,25}

    print("{} ", v);
}