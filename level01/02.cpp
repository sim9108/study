import std;
using namespace std;

auto main() -> int {
    for (vector v = { 1, 2, 3, 4, 5 }; auto x : v) {
        println("{}", x);
    }

    //{[arg-id]:[fill-and-align][sign][#][0][width][.precision][L][type]}
    //:[fill-and-align][width]
    vector data{ 1, 2, 3 };
    println("{}", data);            // "[1, 2, 3]"
    println("{::>5}", data);        // "[    1,     2,     3]"
    println("{}", pair{ 1, "hi" }); // "(1, hi)"
    return 0;
}