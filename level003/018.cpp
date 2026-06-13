
import std;
using namespace std;

using istream_type = istringstream;
using ostream_type = ostringstream;
using streambuf_type = stringbuf;

using int_type = istream_type::int_type;
using char_type = istream_type::char_type;
using traits_type = istream_type::traits_type;

void getline_test() {
    do {
        istream_type ss{ "1234567890\n" };

        char_type buf[5]{}; // buffer full
        ss.getline(buf, 5, ss.widen('\n'));
       println("buffer full buf:{:?} gcount:{} fail:{} eof:{}", buf, ss.gcount(),ss.fail(), ss.eof());
    } while (false);

    do {
        istream_type ss{ "abcdef" }; // eof

        char_type buf[10]{};
        ss.getline(buf, 10, ss.widen('\n'));
        println("eof buf:{:?} gcount:{} fail:{} eof:{}", buf, ss.gcount(), ss.fail(), ss.eof());
    } while (false);

    do {
        istream_type ss{ "12345P67890" }; // delimiter

        char_type buf[10]{};
        ss.getline(buf, 10, ss.widen('P')); // unformatted
        char_type c{}; 
        ss >> c; //formatted
        println("delimiter buf:{:?} c:{:?} gcount:{} fail:{} eof:{}", buf, c, ss.gcount(), ss.fail(), ss.eof());
    } while (false);

    do {
        istream_type ss{ "1234567\nab\nz" }; 
        char_type buf[10]{};
        ss.getline(buf, 10, ss.widen('\n')); // unformatted gcount O

        string str{ "init" };
        getline(ss, str, ss.widen('\n')); // unformatted gcount X

        char_type c{};
        ss >> c; //formatted
        println("string buf:{:?} str:{:?} c:{:?} gcount:{} fail:{} eof:{}", buf, str, c, ss.gcount(), ss.fail(), ss.eof());
    } while (false);

    do {
        using ctype_facet = ctype<char_type>;
        locale loc("");
        ctype_facet const& ctype = use_facet< ctype_facet>(loc);
          
        string str{ "init" };
        getline(istream_type{ "1234567\nab\nz"}, str, ctype.widen('\n')); // unformatted gcount X
        println("rvalue str:{:?}", str);
    } while (false);

}

auto main() -> int {
    getline_test();
    return 0;
}

//* istream class의 getline unformatted function 

// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)


template<class charT, class traits = char_traits<charT>>
class basic_istream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios (31.5.4))
    using   char_type = charT;
    using    int_type = traits::int_type; // eof + char_type;
    using    pos_type = traits::pos_type;
    using    off_type = traits::off_type;
    using traits_type = traits;

    // 31.7.5.4, unformatted input

    basic_istream& getline(char_type* s, streamsize n, char_type delim);
    // extracts characters and stores them into successive locations of 
    //      an array whose first element is designated by s.
    // Characters are extracted and stored until one of the following occurs:
    //      1. EOF occurs on the input sequence;
    //      2. traits::eq(c, delim) for the next available input character c 
    //          (in which case the input character is extracted but not stored ***);
    //      3. n is less than one or n - 1 characters are stored 
    //          (in which case the function calls setstate(failbit)).**
    // If the function extracts no characters, 
    //      ios_base::failbit is set in the input function’s local error state before setstate is called.
    // stores a null character (using charT()) into the next successive location of the array.
    basic_istream& getline(char_type* s, streamsize n);
    // return getline(s, n, widen('\n'));
};

template<class charT, class traits, class Allocator>
basic_istream<charT, traits>& getline(basic_istream<charT, traits>& is,
    basic_string<charT, traits, Allocator>& str, charT delim);

template<class charT, class traits, class Allocator>
basic_istream<charT, traits>& getline(basic_istream<charT, traits>&& is,
    basic_string<charT, traits, Allocator>& str, charT delim);
// it does not affect the value returned by subsequent calls to basic_istream<>::gcount();
// calls str.erase() and then extracts characters from is and appends them to str as if by calling str.append(1, c) 
//      until any of the following occurs :
//      1. end-of-file occurs on the input sequence;(EOF)
//      2. traits::eq(c, delim) for the next available input character c 
//              (in which case, c is extracted but not appended**);
//      3. str.max_size() characters are stored 
//          (in which case, ios_base::failbit is set in the input function’s local error state **).
// If the function extracts no characters, 
//      ios_base::failbit is set in the input function’s local error state before setstate is called.
// return is;

template<class charT, class traits, class Allocator>
basic_istream<charT, traits>& getline(basic_istream<charT, traits>& is, basic_string<charT, traits, Allocator>& str);

template<class charT, class traits, class Allocator>
basic_istream<charT, traits>& getline(basic_istream<charT, traits>&& is, basic_string<charT, traits, Allocator>& str);
// return getline(is, str, is.widen('\n'));

//*/