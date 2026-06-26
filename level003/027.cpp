import std;
using namespace std;

template<typename CharT, class _Statetype>
struct formatter<fpos<_Statetype>, CharT> : formatter<streamsize, CharT> {
    using BASE_TYPE = formatter<streamsize, CharT>;

    auto format(const fpos<_Statetype>& p, auto& ctx) const {
        return BASE_TYPE::format(static_cast<long long>(p), ctx);
    }
};

void app_test() {
    const string filename = "app_pos_test.txt";   
    do{
        std::ofstream init_file(filename, ios_base::trunc);
        init_file << "0123456789";
    } while (false);

    do {
        fstream file(filename, ios_base::in | ios_base::out | ios_base::app | ios_base::ate);
        using char_type = fstream::char_type;

        println("#1:{}", file.tellp());

        file.seekp(0, ios_base::beg);
        println("#2:{}", file.tellp());

        file << "ABC";
        println("#3:{}", file.tellp());

        file.seekp(0, ios_base::beg);
        println("#4:{}", file.tellp());

        file << "abc";
        println("#5:{}", file.tellp());

        char_type fourCC[4]{};
        file.seekp(0, ios_base::beg);
        file >> fourCC;
        println("fourCC:{:.4}", fourCC);

    } while (false);

    do {
       ifstream check_file(filename);
       ostringstream ss;
       ss << check_file.rdbuf();
       println("{}", ss.view());
    } while (false);

 }
auto main() -> int {
    app_test();
    return 0;
}