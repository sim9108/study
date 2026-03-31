import std;
using namespace std;

//chrono-format-spec

auto main() -> int {
    // {[arg-id]:[[fill]align][width][precision][L][chrono-specs]}
    // chrono-specs:[%[modifier][type]]...[literal-char]...
    // modifier: E O
    // type: a/A b/B c/C d/D e F g/G h/H I j m/M n p q/Q r/R S t/T u/U V w/W x/X y/Y z/Z %
    // litera-char: {, },%를 제외한 문자

    println("{:%T}", -10'000s);        // -02:46:40
    println("{:%H:%M:%S}", -10'000s);  // -02:46:40
    println("minutes {:%M, hours %H, seconds %S}", -10'000s);// minutes -46, hours 02, seconds 40

    auto ds = chrono::seconds{ 0 };
    chrono::sys_seconds epoch{ ds };
    println("{:%Y-%m-%d %H:%M:%S %Z}", epoch);    // 1970-01-01 00:00:00 UTC
    return 0;
}