import std;
using namespace std;

auto main() -> int {
    // [[fill]align][sign][#][0][width][.precision][L][type] =>format-spec
    // {[arg-id]:[[range-fill]align][width][n][range-type][:format-spec]}
    // [[range-fill]align] range-fill로 { } : 불가능
    // [range-type]: m s ?s
    vector data{ 1, 2, 3 };
    println("{}", data);               // "[1, 2, 3]"
    println("{:*^30}", data);          // "**********[1, 2, 3]***********"
    println("{:*^30:-^5}", data);      // "****[--1--, --2--, --3--]*****"
    println("{:*^30n:-^5}", data);     // "*****--1--, --2--, --3--******"

    vector<char> sdata{ 'A','B','C' };
    println("{}", sdata);              // "['A', 'B', 'C']"
    println("{:s}", sdata);            // "ABC"
    println("{:?s}", sdata);           // ""ABC""

    println("{}", pair{ 1, "hi" });    // "(1, hi)"
    println("{:m}", pair{ 1, "hi" });  // "1: "hi""
    println("{:n}", pair{ 1, "hi" });  // "1, "hi""
    return 0;
}