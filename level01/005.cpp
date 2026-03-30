import std;
using namespace std;

auto main() -> int {
    // [[tuple-fill]align][width][n][tuple-type] =>tuple-format-spec
    // [[tuple-fill]align] tuple-fill로 { } : 불가능
    // [tuple-type]: m s ?s

    println("{}", pair{ 1, "hi" });    // "(1, hi)"
    println("{:m}", pair{ 1, "hi" });  // "1: "hi""
    println("{:n}", pair{ 1, "hi" });  // "1, "hi""

    vector<tuple<int, string>> m = { {1, "a"}, {2, "b"} };
    println("{}", m);                 // "[(1, "a"), (2, "b")]"
    println("{:m}", m);               // "{1: "a", 2: "b"}"
    println("{:nm}", m);               // "1: "a", 2: "b""

    return 0;
}