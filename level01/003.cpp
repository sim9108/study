import std;
using namespace std;

auto main() -> int {
    //{[arg-id]:[fill-and-align][sign][#][0][width][.precision][L][type]}
    //:[fill-and-align][width]
    vector data{ 1, 2, 3 };
    println("{}", data);            // "[1, 2, 3]"
    println("{::>5}", data);        // "[    1,     2,     3]"
    println("{}", pair{ 1, "hi" }); // "(1, hi)"
	return 0;
}