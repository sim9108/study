import std;
using namespace std;

//{[arg-id]:[[fill]align][width]}

void call3() {
    println("{}", __func__);
    auto st = stacktrace::current();
    println("{}", st);
}

void call2() {
    println("{}", __func__);
    call3();
}

void call1() {
    println("{}", __func__);
    call2();
}
auto main() -> int {
    call1();
    return 0;
}