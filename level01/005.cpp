import std;
using namespace std;

auto main() -> int {
    // [[tuple-fill]align][width][tuple-type] =>tuple-format-spec
    // [[tuple-fill]align] tuple-fill로 { } : 불가능
    // [tuple-type]: m n

    println("{}", pair{ 1, "hi" });    // "(1, hi)"
    println("{:m}", pair{ 1, "hi" });  // "1: "hi""
    println("{:n}", pair{ 1, "hi" });  // "1, "hi""

    map<string, int> map;
    map["math"] = 10;
    map["lang"] = 100;
    println("{}", map);               // "{"lang": 100, "math": 10}" 
    println("{:n}", map);             // ""lang": 100, "math": 10"

    return 0;
}