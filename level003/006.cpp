import std;
using namespace std;

auto main() -> int {
    // basic_ios<>;
    // basic_istream<>::sentry;
    // basic_ostream<>::sentry;*/
    // basic_iostream<>
    // 
    //  class sentry ///////////////////////////
    //  formatted/unformatted input function; //bool _Noskip = false/true   // gcount()
    //  prefix operations: streambuf' lock, tie()->flush(), skipws[input]
    //  suffix operations: unitbuf[output], streambuf' unlock
    //  exception safety level
    //      1. Nothrow / Nofail
    //      2. Strong Guarantee(Roll back Guarantee)
    //      3. Basic Guarantee(State sync Guarantee)*
    //      4. No Guarantee
    // 

    // skipws: [*][input]
    do {
        stringstream ss{ " 123" };
        int a1{};
        ss >> a1;
        println("|{}|", a1);
    } while (false);

    do {
        stringstream ss{ " hello" };
        string str{};
        ss >> str;
        println("|{}|", str);
    } while (false);

    do {
        stringstream ss{ " 123" };
        ss.unsetf(ios_base::skipws);
        /*
        ss.ignore();
        ss.get();// ss.rdbuf()->sbumpc();
        */
        int a1{};
        ss >> a1;
        println("|{}| failed:{}", a1, ss.fail());
    } while (false);

    do {
        stringstream ss{ " hello" };
        ss.unsetf(ios_base::skipws);
        /*
        ss.ignore();
        ss.get();// ss.rdbuf()->sbumpc();
        */
        string str{};
        ss >> str;
        getline(ss, str);
        println("|{}|failed:{}", str, ss.fail());
    } while (false);


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
    return 0;
}