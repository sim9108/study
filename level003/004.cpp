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
 
 // fixed/scientific [output]
    do {
        double v1{ 12345.678901234 };
        stringstream ss{ };
        ss.setf(ios_base::uppercase); ss.precision(3);
        ss.setf(ios_base::scientific, ios_base::floatfield);
        ss << v1;
        ss.setf(ios_base::fixed, ios_base::floatfield);
        ss << " " << v1;
        ss.setf(ios_base::floatfield);
        ss << " " << v1;
        println("[output #1]:{}", ss.str());
    } while (false);

    do {
        double v1{ 12345.678901234 };
        stringstream ss{ };
        ss << uppercase << setprecision(3)
            << scientific << v1
            << fixed << " " << v1
            << hexfloat << " " << v1;
        println("[output #2]:{}", ss.str());
    } while (false);

    do {
        double v1{ 100 };
        stringstream ss{ };
        ss << v1;
        ss.setf(ios_base::showpoint);
        ss << " " << v1;
        ss.setf(ios_base::scientific, ios_base::floatfield);
        ss << " " << v1;
        ss.setf(ios_base::fixed, ios_base::floatfield);
        ss << " " << v1;
        println("[output #3]:{}", ss.str());
    } while (false);


    do {
        double v1{ 100 };
        stringstream ss{ };
        ss << v1
            << showpoint
            << " " << v1
            << scientific << " " << v1
            << fixed << " " << v1;
        println("[output #4]:{}", ss.str());
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