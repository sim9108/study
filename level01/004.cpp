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
    return 0;
}