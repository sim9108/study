import std;
using namespace std;

namespace NS1 {
    struct Point { int x, y; };
}
namespace std {
    using NS1::Point;
    template <>
    struct formatter<Point> {
        constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

        auto format(const Point& p, format_context& ctx) const {
            return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
        }
    };
}

auto main() -> int {
    NS1::Point p{ 10, 20 };
    println("{}", p); //(10, 20)
    return 0;
}