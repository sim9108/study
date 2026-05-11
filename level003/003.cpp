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
 
 // hex/dec/oct [input] 
    do {
        stringstream ss{ "0XFF 255 0377" };
        int v1{}, v2{}, v3{};
        ss >> v1 >> v2 >> v3;
        println("[input #1]:{} {} {} failed:{}", v1, v2, v3, ss.fail());
    } while (false);

    do {
        stringstream ss{ "0XFF 255 0377" };
        int v1{}, v2{}, v3{};
        ss.setf(ios_base::hex, ios_base::basefield);
        ss >> v1;
        ss.setf(ios_base::dec, ios_base::basefield);
        ss >> v2;
        ss.setf(ios_base::oct, ios_base::basefield);
        ss >> v3;
        println("[input #2]:{} {} {}", v1, v2, v3);
    } while (false);

    do {
        stringstream ss{ "0XFF 255 0377" };
        int v1{}, v2{}, v3{};
        ss >> hex >> v1 >> dec >> v2 >> oct >> v3;
        println("[input #3]:{} {} {}", v1, v2, v3);
    } while (false);

    // hex/dec/oct [output]
    do {
        int v1{ 255 };
        stringstream ss{ };
        ss.setf(ios_base::showbase);
        ss.setf(ios_base::uppercase);
        ss.setf(ios_base::hex, ios_base::basefield);
        ss << v1;
        ss.setf(ios_base::dec, ios_base::basefield);
        ss << " " << v1;
        ss.setf(ios_base::oct, ios_base::basefield);
        ss << " " << v1;
        println("[output #1]:{}", ss.str());
    } while (false);

    do {
        int v1{ 255 };
        stringstream ss{ };
        ss << showbase << uppercase
            << hex << v1
            << dec << " " << v1
            << noshowbase << oct << " " << v1;
        println("[output #2]:{}", ss.str());
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