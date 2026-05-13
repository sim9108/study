import std;
using namespace std;

auto main() -> int {
    /* // 31.5.2.3, fmtflags state
       fmtflags       flags() const;
       fmtflags       flags(fmtflags fmtfl);
       fmtflags        setf(fmtflags fmtfl);
       fmtflags        setf(fmtflags fmtfl, fmtflags mask);
       void          unsetf(fmtflags mask);

       streamsize precision() const;
       streamsize precision(streamsize prec);
       streamsize     width() const;
       streamsize     width(streamsize wide);
    ///*/
    
    // showpos [numeric][ouput]
    do {
        int a1{ 10 }, a2{ -10 };
        double d1{ 1.23e-10 }, d2{ -1.234e-10 };
        stringstream ss{};
        ss.setf(ios_base::showpos);
        ss << "|" << a1 << "|" << a2 << "|\n";
        ss << "|" << d1 << "|" << d2 << "|\n";
        ss.unsetf(ios_base::showpos);
        ss << "|" << a1 << "|" << a2 << "|\n";
        ss << "|" << d1 << "|" << d2 << "|\n";
        println("{}", ss.str());
    } while (false);

    do {
        int a1{ 10 }, a2{ -10 };
        double d1{ 1.23e-10 }, d2{ -1.234e-10 };
        stringstream ss{};
        ss << showpos << "|" << a1 << "|" << a2 << "|\n";
        ss << "|" << d1 << "|" << d2 << "|\n";
        ss << noshowpos << "|" << a1 << "|" << a2 << "|\n";
        ss << "|" << d1 << "|" << d2 << "|\n";
        println("{}", ss.str());
    } while (false);

    println("|{0: }|{0:+}|{0:-}|", 23);
    println("|{0: }|{0:+}|{0:-}|", 1.234e-10);
    
    // left/right/internal [*][output]
    do {
        long double price = 10'1000;
        int val{ 255 };

        stringstream ss{};
        ss.imbue(locale("ko_KR"));

        ss.setf(ios_base::internal, ios_base::adjustfield);
        ss.setf(ios_base::showbase | ios_base::uppercase);
        ss.fill('*');
        
        ss.width(15);
        ss << put_money(price, true) << "\n";

        ss.setf(ios_base::hex, ios_base::basefield);
        ss.width(15);
        ss << val << "\n";

        ss.setf(ios_base::dec, ios_base::basefield);
        ss.width(15);
        ss << -val;
        println("{}\nwidth:{}", ss.str(), ss.width());
    } while (false);

    do {
        long double price = 10'1000;
        int val{ 255 };

        stringstream ss{};
        ss.imbue(locale("ko_KR"));
        ss << internal << showbase << uppercase << setfill('*')
            << setw(15) << put_money(price, true) << "\n"
            << hex << setw(15) << val << "\n"
            << dec << setw(15) << -val;
        println("{}\nwidth:{}", ss.str(), ss.width());
    } while (false);

    println("{:*^20}", 255);
    println("{: #020X}", 255);
  
    // ios_base: iostream class's base 
    // bitmask type ////////////////////////////////////////////////
    //  using fmtflags = int;
    // 
    //  using fmtflags = int; // formatting flags
    //      boolalpha: [bool][input][output]
    //      hex/dec/oct: [integer][input][output] base
    //              showbase: [integer][output] 0X//0 통화단위
    //              basefield = dec | oct | hex;
    //      fixed/scientific: [floating-point][output] //defaultfloat;
    //              floatfield = scientific | fixed;// hexfloat
    //              showpoint: [floating-point][output] decimal-point
    // 
    //      showpos: [numeric][output] +  
    //      left/right/internal: [*][output]
    //              adjustfield = left | right | internal;    
    //                          designated internal point: sign/0X/통화단위 이후 지점   
    //      uppercase: [numeric][output]
    //          
    //      skipws: [*][input] skip leading whitespace before certain input operations
    //      unitbuf: [*][output] flush after each output operations
    
    //                  
    //      streamsize type: formatting       
    //          precision
    //          width
    //      lazy: formatting
    //          fill char?

    return 0;
}