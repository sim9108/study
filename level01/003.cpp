import std;
using namespace std;


auto main() -> int {
    println("{} {}", 123, 456);                      // "123 456"
    println("{}", formatted_size("{} {}", 123, 456));// "7"
    println("{}", nullptr);                          // "0x0"

    int a{ 10 };
    void* p = &a;
    println("{0:P} {0:p}", p);           // "0X6FF7EC 0x6ff7ec"
    return 0;
}