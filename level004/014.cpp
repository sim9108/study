import std;
using namespace std;

struct Score {
    string name;
    int value;
    explicit operator bool() { return value > 50; }
};

auto main() -> int {
    vector<Score> scores{ { "Alice", 60 }, { "Dave", 45 } };

    for (auto&& s : scores) {
        if (auto&& [name, value] = s; s) {
            println("name:{} score: {} passed", name, value);
        }
        else {
            println("name:{} score: {} not passed", name, value);
        }
    }
    return 0;
}