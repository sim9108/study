import std;
using namespace std;


auto main() -> int {
    println("{} {}", 123, 456);                      //"123 456"
    println("{}", formatted_size("{} {}", 123, 456));//"7"
    println("{}", nullptr);                          //0x0
    return 0;
}