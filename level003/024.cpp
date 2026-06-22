import std;
using namespace std;

void money_test() {
    do {
        stringstream ss{ "KRW123,456 KRW567,896" }; 
        ss.imbue(locale("ko_KR.UTF-8"));

        string      s1{};
        long double s2{};

        ss >> showbase >> get_money(s1, true) >> get_money(s2, true);
        // intl: 
        //      false : $, ₩ 
        //      true: USD, KRW
        println("s1:{} s2:{}", s1, s2);
    } while (false);

    do {
        string      s1{ "123456" };
        long double s2{ 567896 };

        stringstream ss{};
        ss.imbue(locale("ko_KR.UTF-8"));

        ss << showbase << put_money(s1, true) << " " << put_money(s2, false);
        // intl: 
        //      false : $, ₩ 
        //      true: USD, KRW
        println("ss:{}", ss.view());


       // using money_puct = moneypunct< stringstream::char_type>;
       // money_puct const& m = use_facet<money_puct>(ss.getloc());
       // println("{}", m.curr_symbol());
    } while (false);

}

void time_test() {
    const char fmt[]{ "%Y-%m-%d %H:%M:%S" };
    do {
        stringstream ss("2026-06-22 14:30:10");
        tm t{};
        ss >> get_time(&t, fmt);
        if (ss.fail())  break;

        println("{}-{:02}-{:02} {:02}:{:02}:{:02}", 
            t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, 
            t.tm_hour,t.tm_min,t.tm_sec
            );
    } while (false);

    do {
        time_t now{};        
        time(&now);
        tm* t = localtime(&now); // localtime_s(t, &now);

        stringstream ss;
        ss << put_time(t, fmt);
        if (ss.fail())  break;
        println("{}", ss.view());
    } while (false);

}

auto main() -> int {
    money_test();
    time_test();
    return 0;
}