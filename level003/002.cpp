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
 
 // boolalpha [input]
    do {
        stringstream ss{ "true 1" };
        bool v1{}, v2{};
        ss >> v1 >> v2;
        println("[input #1]:{} {} failed:{}", v1, v2, ss.fail());
    } while (false);

    do {
        stringstream ss{ "true 1" };
        bool v1{}, v2{};
        ss.setf(ios_base::boolalpha);
        ss >> v1;
        ss.unsetf(ios_base::boolalpha);
        ss >> v2;
        println("[input #2]:{} {}", v1, v2);
    } while (false);

    do {
        stringstream ss{ "true 1" };
        bool v1{}, v2{};
        ss >> boolalpha >> v1 >> noboolalpha >> v2;
        println("[input #3]:{} {}", v1, v2);
    } while (false);

    // boolalpha [output]
    do {
        stringstream ss{ };
        ss << true << " " << true;
        println("[output #1]:{}", ss.str());
    } while (false);

    do {
        stringstream ss{};
        ss.setf(ios_base::boolalpha);
        ss << true;
        ss.unsetf(ios_base::boolalpha);
        ss << " " << true;
        println("[output #2]:{}", ss.str());
    } while (false);

    do {
        stringstream ss{ };
        ss << boolalpha << true << noboolalpha << " " << true;
        println("[output #3]:{}", ss.str());
    } while (false);

    // ios_base: iostream class's base  ex)stringstream
    // bitmask type ////////////////////////////////////////////////
    //  using fmtflags = int;    
    // 
    //  using fmtflags = int; // formatting flags
    //      boolalpha: [bool][input][output]
    //      hex/dec/oct: [integer][input][output] base
    //              showbase: [integer][output] 0X//0
    //              basefield = dec | oct | hex;
    //      fixed/scientific: [floating-point][output]
    //              floatfield = scientific | fixed;// hexfloat
    //              showpoint: [floating-point][output] decimal-point
    //      showpos: [numeric][output] +  
    //      left/right/internal: [*][output]
    //              adjustfield = left | right | internal;    //                  
    //      skipws: [*][input] skip leading whitespace before certain input operations
    //      unitbuf: [*][output] flush after each output operations
    //      uppercase: [numeric][output]
    //                  
    //      streamsize type: formatting       
    //          precision
    //          width
    //      lazy: formatting
    //          fill char?
    // 

    return 0;
}