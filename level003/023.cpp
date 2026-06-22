import std;
using namespace std;

void quoted_test() {
    do {
        stringstream s1;
        using char_type = stringstream::char_type;
        string src{ "te$🚀s🤷‍♀️t^" };
        println("src:{}", src);

        s1 << "|" << setw(50)
            << quoted(src, s1.widen('$'), s1.widen('^'))
            << "|";
        println("{}", s1.str());

        char_type c1, c2;
        string dst;
        s1 >> c1
            >> quoted(dst, s1.widen('$'), s1.widen('^'))
            >> c2;

        println("dst:{}", dst);
    } while (false);

    do {
        stringstream s1;
        using char_type = stringstream::char_type;
        string src{ "te$🚀s🤷‍♀️t^" };
        println("src:{}", src);

        s1 << "|" << setw(50)
            << src
            << "|";
        println("{}", s1.str());

        char_type c1;
        string dst;
        s1 >> c1
            >> quoted(dst, s1.widen('$'), s1.widen('^')); //>> dest;

        println("dst:{}", dst);
    } while (false);
}

auto main() -> int {
/*    
    cout << resetiosflags(ios_base::basefield);
    cin >> resetiosflags(ios_base::basefield);

    cout << setiosflags(ios_base::basefield);
    cin >> setiosflags(ios_base::basefield);

    cout << setbase(8);      
    cin >> setbase(8);

    cout << setprecision(8);
    cin >> setprecision(8);

    cout << setw(8);
    cin >> setw(8);

    cout << setfill(cout.widen('c'));    
*/

    quoted_test();
    return 0;
}

/*////
class ios_base;
template <class charT, class traits> class basic_ios;
template <class charT, class traits> class basic_ostream;
template <class charT, class traits> class basic_istream;
template <class charT, class traits> class basic_iostream;

// 31.7.7, standard manipulators
// basic_istream/basic_ostream
unspecified resetiosflags(ios_base::fmtflags mask); // str.setf(ios_base::fmtflags(0), mask); return str;
unspecified setiosflags(ios_base::fmtflags mask);   // str.setf(mask); return str;
unspecified setbase(int base);
//  str.setf(
//    base == 8 ? ios_base::oct :
//    base == 10 ? ios_base::dec :
//    base == 16 ? ios_base::hex :
//    ios_base::fmtflags(0), ios_base::basefield);
// return str;
unspecified setprecision(int n);                    // str.precision(n); return str;
unspecified setw(int n);                            // str.width(n); return str;
// basic_ostream
template<class charT> unspecified setfill(charT c); // str.fill(c); return str;

// 31.7.9, quoted manipulators
// output
template<class charT>
unspecified quoted(const charT* s, charT delim = charT('"'), charT escape = charT('\\'));
template<class charT, class traits, class Allocator>
unspecified quoted(const basic_string<charT, traits, Allocator>& s, charT delim = charT('"'), charT escape = charT('\\'));
template<class charT, class traits>
unspecified quoted(basic_string_view<charT, traits> s, charT delim = charT('"'), charT escape = charT('\\'));
//input output
template<class charT, class traits, class Allocator>
unspecified quoted(basic_string<charT, traits, Allocator>& s, charT delim = charT('"'), charT escape = charT('\\'));
*/////