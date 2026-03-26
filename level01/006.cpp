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

enum color { red, green, blue };
const char* color_names[] = { "red", "green", "blue" };
template<> struct std::formatter<color> : std::formatter<const char*> {
    auto format(color c, format_context& ctx) const {
        return formatter<const char*>::format(color_names[c], ctx);
    }
};


auto main() -> int {
    NS1::Point p{ 10, 20 };
    println("{}", p);   // "(10, 20)"
    println("{}", red); // "red"
    return 0;
}