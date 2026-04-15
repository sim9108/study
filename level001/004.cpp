import std;
using namespace std;


auto main() -> int {
    println("{} {}", 123, 456);                      // "123 456"
    println("{}", formatted_size("{} {}", 123, 456));// "7"
    println("{}", nullptr);                          // "0x0"

    int a{ 10 };
    void* p = &a;
    println("{0:P} {0:p}", p);           // "0X6FF7EC 0x6ff7ec"

    println("{:🤡^6}", "x");             // "🤡🤡x🤡🤡🤡"
    println("{:*^6}", "🤡🤡🤡");        // "🤡🤡🤡"
    println("{:*^6}", "123456");         // "123456"
    println("{:*^6}", "❤️❤️❤️");          // "*❤️❤️❤️**"
    return 0;
}