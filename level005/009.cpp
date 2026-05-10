import std;
using namespace std;

auto main() -> int {
    vector<string> fruits = { "apple", "banana", "cherry" };

    for (auto [i, fruit] : views::enumerate(fruits)) {
        println("[{}] {}", i, fruit);
    }

    return 0;
}