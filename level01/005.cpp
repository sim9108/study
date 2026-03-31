import std;
using namespace std;

auto main() -> int {
    // {[arg-id]:[[tuple-fill]align][width][tuple-type]
    // [[tuple-fill]align] tuple-fill로 { } : 불가능
    // [tuple-type]: m n
    println("{}", pair{ 1, "hi" });    // "(1, hi)"
    println("{:m}", pair{ 1, "hi" });  // "1: "hi""
    println("{:n}", pair{ 1, "hi" });  // "1, "hi""
    return 0;
}