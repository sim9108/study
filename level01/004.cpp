import std;
using namespace std;

auto main() -> int {
    //{[arg-id]:[[fill]align][sign][#][0][width][.precision][L][type]}
    //:[[fill]align][width]
    println("{}", pair{ 1, "hi" });   // "(1, hi)"
    println("{:m}", pair{ 1, "hi" }); // "1: "hi""
    println("{:n}", pair{ 1, "hi" }); // "1, "hi""

    vector data{ 1, 2, 3 };
    println("{}", data);              // "[1, 2, 3]"
    println("{::>5}", data);          // "[    1,     2,     3]"
    return 0;
}