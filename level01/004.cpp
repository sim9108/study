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

    println("{:?}", string("\0 \n \t \x02 \x1b", 9)); // ""\u{0} \n \t \u{2} \u{1b}""
    println("{:?}", "e\u0301");       //""é""

    vector<string> v = { "hello\t\n", "w\norld" };
    println("{}", v);                // ["hello\t\n", "w\norld"]
    println("{:?}", v);              // ["hello\t\n", "w\norld"]
    println("{::}", v);
    /*
    [hello
    , w
    orld]
    */
    vector<tuple<int, string>> m = { {1, "a"}, {2, "b"} };
    println("{}", m);                 // "[(1, "a"), (2, "b")]"
    println("{:m}", m);               // "{1: "a", 2: "b"}"
    println("{:nm}", m);              // "1: "a", 2: "b""

    // {[arg-id]:[[tuple-fill]align][width][tuple-type]
    // [[tuple-fill]align] tuple-fill로 { } : 불가능
    // [tuple-type]: m n
    println("{}", pair{ 1, "hi" });    // "(1, hi)"
    println("{:m}", pair{ 1, "hi" });  // "1: "hi""
    println("{:n}", pair{ 1, "hi" });  // "1, "hi""
    return 0;
}