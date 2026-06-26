import std;
using namespace std;

void ospan_test(span<char> data){
    ospanstream os{ data };
    os << "100 200 300";
}

void ispan_test(span<char const> cdata, span<int> vals) {
    ispanstream is{ cdata };
    for (auto& i : vals) {
        is >> i;
        if (is.fail()) break;
    }
    is.clear();

   // char_T
   // array<char, 7> data2 = { '3', '0', '0', ' ', '4', '0', '0' };
   // string data2 { "300 400"};
   // vector<char> data2{ '3', '0', '0', ' ', '4', '0', '0' };
    string_view data2{ "300 400" };

    is.span(data2);
    int a{}, b{};
    is >> a >> b;
    println("a:{} b:{}", a, b);
}

void FourCC_test(span<char> data) {
    do {
        ofstream fo("test.txt");
        fo << "H264 data";
    } while (false);

    ospanstream ss{ data };
    do {
        ifstream fi("test.txt");
        ss << fi.rdbuf();
    } while (false);
    println("{:.{}}", data.data(), data.size());
}

auto main() -> int {
    char buf[20]{}; // 최대 3개 숫자 포함 문자
    int vals[3]{};  // 

    char FCC[4]{};  // Four-Character Code

    ospan_test(buf);
    ispan_test(buf, vals);
    FourCC_test(FCC);

    println("out:{:.20}", buf);
    println("vals:{}", vals);
    return 0;
}