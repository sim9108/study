import std;
using namespace std;

auto main() -> int {
    vector v = { 1, 1, 2, 2, 2, 3, 1, 1 };

    for (auto group : v | views::chunk_by(std::equal_to{})) {
        println("{} ", group);
    }
    return 0;
}