
import std;
using namespace std;

using istream_type = istringstream;
using ostream_type = ostringstream;
using streambuf_type = stringbuf;

using int_type = istream_type::int_type;
using char_type = istream_type::char_type;
using traits_type = istream_type::traits_type;

void get_test() {
    do {
        istream_type ss{ ""};
        int_type ic = ss.get();
        if (!traits_type::eq_int_type(ic, traits_type::eof())) {
            println("ic:{:?} gcount:{} fail:{}",
                traits_type::to_char_type(ic), ss.gcount(), ss.fail());
        }
        else {
            println("ic:{} gcount:{} fail:{}",
                ic, ss.gcount(), ss.fail());
        }
    } while (false);


    do {
        istream_type ss{ "1" };

        char_type c{};        
        ss.get(c);
        println("c:{:?} gcount:{} fail:{}",
            c, ss.gcount(), ss.fail());
    } while (false);

    do {
        istream_type ss{ "01#234" };

        char_type ac[4]{};        
        ss.get(ac,4, ss.widen('#'));
        println("ac:{:?} gcount:{}", ac, ss.gcount());
    } while (false);
  
    do {
        istream_type ss{ "01234" };

        char_type ac[10]{};        
        ss.get(ac,10);
        println("ac:{:?} gcount:{} fail:{}", ac, ss.gcount(), ss.fail());
    } while (false);


    do {
        istream_type s1{ "012$34" };
        ostream_type s2{  };
        char_type c{};
        s1.get(*s2.rdbuf(), s1.widen('$')); // unformatted
        s1 >> c; //formatted
        println("s2:{:?} c:{:?} gcount:{}", s2.str(), c, s1.gcount());
    } while (false);
}

auto main() -> int {
    get_test();
    return 0;
}



/* istream class의 unformatted function

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
    // code unit(encode), 하나 이상의 code units로부터 decode 수행
    // Character Set:Glyph
    // Glyph Cluster( Grapheme Cluster(그라핌 클러스터) 또는 Text Element(텍스트 요소))
    // 
    // ZWJ(Zero-Width Joiner, 폭이 없는 접합자, U+200D)
    //      👨 + ZWJ + 💻  :  👨‍💻(남자 개발자)
    // ZWNJ(Zero-Width Non-Joiner, 폭 없는 비접합자, U+200C)
    //      👨 + ZWNJ + 💻 : 👨💻
    // 시프트(Shift) 기반 문자셋(Shift JIS) : 상태 의존형(Stateful), mbstate_t
    //      SI(Shift-In, 0x0F, 확장 문자셋) / SO(Shift-Out, 0x0E, 기본 ASCII 문자셋):



    // 31.7.5.4, unformatted input
    streamsize     gcount() const;
    // Returns: The number of characters extracted by 
    //              the last unformatted input member function called for the object.
    //          If the number cannot be represented, returns numeric_limits<streamsize>::max().

    int_type       get();
    // extracts a character c = rdbuf()->sgetc(), if one is available. 
    // Otherwise, ios_base::failbit is set in the input function’s local error state before setstate is called.
    // Returns: c if available(rdbuf()->sbumpc()), otherwise traits::eof().

    basic_istream& get(char_type& c);
    // extracts a character, if one is available, and assigns it to c.
    // Otherwise, ios_base::failbit is set in the input function’s local error state before setstate is called.
    // Returns: *this.

    basic_istream& get(char_type* s, streamsize n, char_type delim);
    // extracts characters and stores them into successive locations of an array whose first element is designated by s.
    // Characters are extracted and stored until any of the following occurs:
    //      — n is less than one or n - 1 characters are stored.
    //      - EOF occurs on the input sequence;
    //      - traits::eq(c, delim) for the next available input character c (in which case c is not extracted **)
    // If the function stores no characters, 
    //          ios_base::failbit is set in the input function’s local error state before setstate is called.
    // In any case, if n is greater than zero 
    // it then stores a null character into the next successive location of the array.

    basic_istream& get(char_type* s, streamsize n);
    // return get(s, n, widen('\n'));

    basic_istream& get(basic_streambuf<char_type, traits>& sb, char_type delim);
    // extracts characters and inserts them in the output sequence controlled by sb.
    // Characters are extracted and inserted until any of the following occurs :
    //      — EOF occurs on the input sequence;
    //      — inserting in the output sequence fails(in which case the character to be inserted is not extracted);
    //      - traits::eq(c, delim) for the next available input character c (in which case c is not extracted ***);
    //      — an exception occurs(in which case, the exception is caught but not rethrown).
    // If the function inserts no characters, 
    //      ios_base::failbit is set in the input function’s local error state before setstate is called.
    // Returns: *this
    basic_istream& get(basic_streambuf<char_type, traits>& sb);
    // return get(sb, widen('\n'));


};
//*/