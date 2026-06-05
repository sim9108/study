import std;
using namespace std;
#include <cerrno>

void ctype_mask_table() {
    // Bit masks for the possible character types
    // #define _XA      0x100    // extra alphabetic
    // #define _UPPER   0x01     // uppercase letter
    // #define _LOWER   0x02     // lowercase letter
    // #define _DIGIT   0x04     // digit[0-9]
    // #define _SPACE   0x08     // tab, carriage return, newline, vertical tab, or form feed
    // #define _PUNCT   0x10     // punctuation character
    // #define _CONTROL 0x20     // control character
    // #define _BLANK   0x40     // space char (tab is handled separately)
    // #define _HEX     0x80     // hexadecimal digit

    locale myloc("");

    do {
        using facet_type = ctype<char>;
        using mask_type = facet_type::mask;
        using char_type = facet_type::char_type;

        const facet_type& v = use_facet<facet_type>(myloc);
        const char_type str[]{ "Za1\t\r" };
        constexpr size_t len = sizeof(str) - 1;
        mask_type mask[len]{};

        v.is(str, str + len, mask);
        for (auto&& [i,m] : views::enumerate(mask)) {
            println("{:#B} : {:?}", m, str[i]);
        }
    } while (false);
}

void ctype_test() {
    using facet_type = ctype<char>;
    using wfacet_type = ctype<wchar_t>;

    using mask_type = facet_type::mask;
    using char_type = facet_type::char_type;

    locale loc("");
    const facet_type& facet = use_facet<facet_type>(loc);
    const wfacet_type& wfacet = use_facet<wfacet_type>(loc);
    do {        
        cout << "alpha:" << facet.is(facet_type::alpha, 'c') << endl;
        cout << "isalpha:" << isalpha('c', loc) << endl;

        cout << "c is uppper:" << facet.is(facet_type::upper, 'c') << endl;
        cout << "c isupper:" << isupper('c', loc) << endl;
    } while (false);

    do {        
        cout << "d toupper:" << facet.toupper('d') << endl;
        cout << "d toupper:" << toupper('d', loc) << endl;
    } while (false);

    do {    // facet based   
        wcout << L"ctype<wchar_t> d to widen:" << wfacet.widen('d') << endl;
        cout << "ctype<wchar_t> 0XAC00 to narrow:" << wfacet.narrow(L'\uAC00', '?') << endl;

        cout << "ctype<char> d to widen:" << facet.widen('d') << endl;
        cout << "ctype<char> d to narrow:" << facet.narrow(L'd', '?') << endl;
    } while (false);

    do {   // stream based     
        wcout << L"ctype<wchar_t> d to widen:" << wcout.widen('d') << endl;
        cout << "ctype<wchar_t> 0XAC00 to narrow:" << wcout.narrow(L'\uAC00', '?') << endl;

        cout << "ctype<char> d to widen:" << cout.widen('d') << endl;
        cout << "ctype<char> d to narrow:" << cout.narrow(L'd', '?') << endl;
    } while (false);
    
}

void and_so_on() {
    do {
        const signed char a1[]{ "const signed char*\n" };
        const char a2[]{ "const char*\n" };
        cout << a1;
        cout << a2;
    } while (false);

    do {
        string a1{ "string\n" };
        string_view a2{ "string_view\n"};
        cout << a1;
        cout << a2;
    } while (false);

    do {
        cout << absolute(filesystem::path(".")) << "\n";
    } while (false);

    do {
        linear_congruential_engine<unsigned int, 48271, 0, 2147483647> custom_lce{ 12345 };
        cout << "engine:" << custom_lce << endl;
        cout << "value:" << custom_lce() << endl;

        uniform_int_distribution<int> dist(1, 6);
        cout << "* distribution:" << dist << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "distribution(engine):" << dist(custom_lce) << endl;
        }
    } while (false);

    do {
        error_code ec1(ENOENT, std::system_category());
        cout << "error code:" << ec1 << endl;
    } while (false);

    do {
        std::bitset<8> bits(42); 
        cout << "bits:" << bits << endl;
    } while (false);

    do {
        cout << "thread id:" << this_thread::get_id() << endl;
    } while (false);

    do {
        auto now = std::chrono::system_clock::now();
        std::chrono::zoned_time ny_time{ "America/New_York", now };
        cout << "America/New_York:" << ny_time << endl;
    } while (false);
}


auto main() -> int {
   ctype_mask_table();
   ctype_test();
   and_so_on();

    return 0;
}


/* ostream class의 ctype<charT> facet를 사용하는 formatted function: output operator( operator<< ) overload;

// stream class의 formatted function vs unformatted function
//
// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)

// 28.3.3.1, locale // entity component pattern 
class locale {
    class facet;
    class id;
    using category = int; //locale 내부 type alias
};
template<class Facet> const Facet& use_facet(const locale&);

// 28.3.4.2, ctype 1 category:ctype
class ctype_base;
template<class charT> class ctype;
template<>            class ctype<char>;        // specialization
template<class charT> class ctype_byname;
class codecvt_base;
template<class internT, class externT, class stateT> class codecvt;
template<class internT, class externT, class stateT> class codecvt_byname;

class ctype_base {
public:
    using mask = see below;

    // numeric values are for exposition only.
    static constexpr mask space = 1 << 0;
    static constexpr mask print = 1 << 1;
    static constexpr mask cntrl = 1 << 2;
    static constexpr mask upper = 1 << 3;
    static constexpr mask lower = 1 << 4;
    static constexpr mask alpha = 1 << 5;
    static constexpr mask digit = 1 << 6;
    static constexpr mask punct = 1 << 7;
    static constexpr mask xdigit = 1 << 8;
    static constexpr mask blank = 1 << 9;
    static constexpr mask alnum = alpha | digit;
    static constexpr mask graph = alnum | punct;
};
template<class charT>
class ctype : public locale::facet, public ctype_base {
public:
    using char_type = charT;

    explicit ctype(size_t refs = 0);

    bool         is(mask m, charT c) const;
    const charT* is(const charT* low, const charT* high, mask* vec) const;
    const charT* scan_is(mask m, const charT* low, const charT* high) const;
    const charT* scan_not(mask m, const charT* low, const charT* high) const;
    charT        toupper(charT c) const;
    const charT* toupper(charT* low, const charT* high) const;
    charT        tolower(charT c) const;
    const charT* tolower(charT* low, const charT* high) const;

    charT        widen(char c) const;
    const char*  widen(const char* low, const char* high, charT* to) const;

    char         narrow(charT c, char dfault) const;
    const charT* narrow(const charT* low, const charT* high, char dfault, char* to) const;

    static locale::id id;

    // ctype<char> specialization
    static const size_t table_size = implementation-defined;

    const mask*         table() const noexcept;
    static const mask*  classic_table() noexcept; // the classifications of characters in the "C" locale.

protected:
    ~ctype();
    virtual bool         do_is(mask m, charT c) const;
    virtual const charT* do_is(const charT* low, const charT* high, mask* vec) const;
    virtual const charT* do_scan_is(mask m, const charT* low, const charT* high) const;
    virtual const charT* do_scan_not(mask m, const charT* low, const charT* high) const;
    virtual charT        do_toupper(charT) const;
    virtual const charT* do_toupper(charT* low, const charT* high) const;
    virtual charT        do_tolower(charT) const;
    virtual const charT* do_tolower(charT* low, const charT* high) const;
    virtual charT        do_widen(char) const;
    virtual const char*  do_widen(const char* low, const char* high, charT* dest) const;
    virtual char         do_narrow(charT, char dfault) const;
    virtual const charT* do_narrow(const charT* low, const charT* high, char dfault, char* dest) const;
};

// 28.3.3.3, convenience interfaces
template<class charT> bool isspace (charT c, const locale& loc); // return use_facet<ctype<charT>>(loc).is(ctype_base::F, c); // for isF
template<class charT> bool isprint (charT c, const locale& loc);
template<class charT> bool iscntrl (charT c, const locale& loc);
template<class charT> bool isupper (charT c, const locale& loc);
template<class charT> bool islower (charT c, const locale& loc);
template<class charT> bool isalpha (charT c, const locale& loc);
template<class charT> bool isdigit (charT c, const locale& loc);
template<class charT> bool ispunct (charT c, const locale& loc);
template<class charT> bool isxdigit(charT c, const locale& loc);
template<class charT> bool isalnum (charT c, const locale& loc);
template<class charT> bool isgraph (charT c, const locale& loc);
template<class charT> bool isblank (charT c, const locale& loc);
template<class charT> charT toupper(charT c, const locale& loc);
template<class charT> charT tolower(charT c, const locale& loc);

// 31.7.6.3.4, character inserters
// 문자
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, charT c); 
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, char c);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, char c);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, signed char c);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, unsigned char c);
// rdbuf()->sputc(os.widen(c)); // use_facet<ctype<char>>(getloc()).widen(c);
// os.width(0); 
// return os;

// 문자 delete function: narrow conversion
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, wchar_t) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, char8_t) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, char16_t) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, char32_t) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, char8_t) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, char16_t) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, char32_t) = delete;

// 문자열(const)
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const charT* s);
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const char* s);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, const char* s);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, const signed char* s);
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>& os, const unsigned char* s);
// auto len = traits::length(reinterpret_cast<const char*>(s));
// rdbuf()->sputc(os.widen( s[0..len) ));
// os.width(0); 
// return os;

// 문자열(const) delete function: narrow conversion
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const wchar_t*) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const char8_t*) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const char16_t*) = delete;
template<class traits>
basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const char32_t*) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, const char8_t*) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, const char16_t*) = delete;
template<class traits>
basic_ostream<wchar_t, traits>& operator<<(basic_ostream<wchar_t, traits>&, const char32_t*) = delete;

// 31.12.6.7, path inserter and extractor
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const path& p);
// os << quoted(p.string<charT, traits>()); // native pathname format
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const directory_entry& d);
// return os << d.path();

template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& out, thread::id id);

template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const error_code& ec);
// return os << ec.category().name() << ':' << ec.value();

template<class charT, class traits, size_t N>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const bitset<N>& x);

// 27.3.5, inserters and extractors
template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os,basic_string_view<charT, traits> str);

template<class charT, class traits, class Allocator>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const basic_string<charT, traits, Allocator>& str);

template<class T, class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&, const complex<T>&);

template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const linear_congruential_engine& x);
// mersenne_twister_engine,subtract_with_carry_engine, philox_engine, discard_block_engine, independent_bits_engine
// shuffle_order_engin, ...

template<class charT, class traits>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os,const uniform_int_distribution& x);
// uniform_real_distribution, bernoulli_distribution, ...

// 30.5.11, duration I/O
template<class charT, class traits, class Rep, class Period>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const duration<Rep, Period>& d);
// sys_time<Duration>, sys_days, utc_time<Duration>, tai_time<Duration>, gps_time<Duration>, file_time<Duration>
// local_time<Duration>, day, month, year, weekday, weekday_indexed, weekday_last

template<class charT, class traits, class Duration, class TimeZonePtr>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const zoned_time<Duration, TimeZonePtr>& t);
//*/