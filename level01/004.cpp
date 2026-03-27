import std;
using namespace std;

auto main() -> int {
    // [[fill]align][sign][#][0][width][.precision][L][type] =>format-spec
    // {[arg-id]:[[range-fill]align][width][n][range-type][:format-spec]} => range-format-spec
    // [[range-fill]align] range-fill로 { } : 불가능
    // [range-type]: m s ?s
    vector data{ 1, 2, 3 };
    println("{}", data);               // "[1, 2, 3]"
    println("{:*^30}", data);          // "**********[1, 2, 3]***********"
    println("{:*^30:-^5}", data);      // "****[--1--, --2--, --3--]*****"
    println("{:*^30n:-^5}", data);     // "*****--1--, --2--, --3--******"

    array sdata{ 'A','B','C','\t','\n' };
    println("{}", sdata);              // "['A', 'B', 'C', '\t', '\n']"
    println("{:s}", sdata);            // "ABC  "<new line>
    println("{:?s}", sdata);           // ""ABC\t\n""

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