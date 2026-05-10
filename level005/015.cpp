import std;
using namespace std;

optional<double> my_div(integral auto&& a, integral auto&& b) {
    if (b == 0) return nullopt;
    return a / b;
}

auto main() -> int {
    vector<optional<double>> data{ my_div(10, 0),my_div(100, 10) };
    for (auto&& datum : data) {
        if (datum) {
            println("{}", *datum);
        }
        else {
            println("arugment error");
        }
    }
    return 0;
}