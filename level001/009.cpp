import std;
using namespace std;


struct Point { int x, y; };

//(1,2);
template<typename CharT>
struct formatter<Point, CharT> : formatter<pair<int, int>, CharT> {
    using BASE_TYPE = formatter<pair<int, int>, CharT>;

    auto format(const Point& p, auto& ctx) const {
        return BASE_TYPE::format(tie(p.x, p.y), ctx);
    }
};

enum class color { red, green, blue };

// "red"
template<typename CharT>
struct formatter<color, CharT> : formatter<const CharT*, CharT> {
    using BASE_TYPE = std::formatter<const CharT*, CharT>;

    static constexpr const CharT* get_name(color c) {
        if constexpr (is_same_v<CharT, char>) {
            static constexpr const char* names[] = { "red", "green", "blue" };
            return names[to_underlying(c)];
        }
        else {
            static constexpr const wchar_t* names[] = { L"red", L"green", L"blue" };
            return names[to_underlying(c)];
        }
    }

    auto format(color c, auto& ctx) const {
        return BASE_TYPE::format(get_name(c), ctx);
    }
};


struct A {
    int id;
    string name;
};

template <>
struct formatter<A> {

    struct format_specs {
        bool id{ false };
    };
    format_specs specs{};


    // {:i}  =>id:"name", "name"
    constexpr auto parse(format_parse_context& ctx) {
        auto it = ctx.begin();
        const auto end = ctx.end();
        for (; it != end && *it != '}'; ++it) {
            switch (*it) {
            case  'i':specs.id = true; break;
            default:
                throw format_error("not accepted format spec");
            }
        }
        return it;
    }

    auto format(const A& p, format_context& ctx) const {
        if (specs.id) {
            return format_to(ctx.out(), "{}:\"{}\"", p.id, p.name);
        }
        return format_to(ctx.out(), "\"{}\"", p.name);
    }
};

auto main() -> int {
    Point pt{ 10, 100 };
    println("{:*^20}", pt);
    wcout << format(L"{:*^20}", pt);

    color red = color::red;
    println("{:}", red);
    wcout << format(L"{:*^10}", red) << endl;

    A name{ 34,"simmon" };
    println("{0}", name);
    println("{0:i}", name);
    return 0;
}