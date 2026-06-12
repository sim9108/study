import std;
using namespace std;
#include <cerrno>

void read_char_arry() {
    do {
        char data[5]{};
        stringstream ss{ "0123456789" };
        ss >> setw(3) >> data;
        cout << "#1-1 setw(3):" << data << endl;
    } while (false);

    do {
        string data{};
        stringstream ss{ "0123456789" };
        ss >> setw(3) >> data;
        cout << "#1-2 setw(3):" << data << endl;
    } while (false);

    do {
        char data[5]{};
        stringstream ss{ "0123456789" };
        ss >> setw(0) >> data;
        cout << "#2-1 setw(0):" << data << endl;
    } while (false);

    do {
        string data{};
        stringstream ss{ "0123456789" };
        ss >> setw(0) >> data;
        cout << "#2-2 setw(0):" << data << endl;
    } while (false);

    do {
        char data[5]{};
        stringstream ss{ "01 23456789" };
        ss >> setw(0) >> data;
        cout << "#3-1 setw(0):" << data << endl;
    } while (false);

    do {
        string data{};
        stringstream ss{ "01 23456789" };
        ss >> setw(0) >> data;
        cout << "#3-2 setw(0):" << data << endl;
    } while (false);

    do {
        string data{};
        stringstream ss{ "\"01 2345\"6789" };
        ss >> setw(0) >> quoted(data);
        cout << "#3-3 setw(0):" << data << endl;
    } while (false);

}

void and_so_on() {
    do {
        stringstream ss;
        ss << absolute(filesystem::path(".")) << "\n";

        filesystem::path pa{};
        ss >> pa;
        cout << pa << endl;
    } while (false);

    do {
        stringstream ss;
        linear_congruential_engine<unsigned int, 48271, 0, 2147483647> custom_lce{ 12345 };
        ss << custom_lce;

        linear_congruential_engine<unsigned int, 48271, 0, 2147483647> my_lce{};
        ss >> my_lce;
        cout << my_lce << endl;

    } while (false);

    do{
        stringstream ss;
        uniform_int_distribution<int> dist(1, 6);
        ss << dist;

        uniform_int_distribution<int> my_dist{};
        ss >> my_dist;
        cout << my_dist << endl;
    } while (false);

    do {
        stringstream ss;
        std::bitset<8> bits(42);
        ss << bits << endl;

        std::bitset<8> bits1{};
        ss >> bits1;
        cout << bits1 << endl;
        cout << bits1.to_ulong()<< endl;
    } while (false);

    do {
        stringstream ss;
        auto now = chrono::system_clock::now();
        std::string formatted = std::format("{:%Y-%m-%d %H:%M:%S}", now); // println
        ss << formatted;

        decltype(now) parsed_time{};
        ss >> chrono::parse("%Y-%m-%d %H:%M:%S", parsed_time);

        cout << std::format("{:%Y-%m-%d %H:%M:%S}", parsed_time);
    } while (false);
}

auto main() -> int {  
    read_char_arry();
    and_so_on();
    return 0;
}
/* istream class에 대한 input operator >>

// stream class의 formatted function vs unformatted function
//
// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)


template<class charT, class traits = char_traits<charT>>
class basic_istream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios (31.5.4))
    using   char_type = charT;
    using    int_type = traits::int_type;
    using    pos_type = traits::pos_type;
    using    off_type = traits::off_type;
    using traits_type = traits;

    // 31.7.5.3, formatted input
    basic_istream& operator>>(basic_istream& (*pf)(basic_istream&));
    basic_istream& operator>>(basic_ios<charT, traits>& (*pf)(basic_ios<charT, traits>&));
    basic_istream& operator>>(ios_base& (*pf)(ios_base&));
    // arithmetic type formatted
    // use_facet<num_get<charT>>(loc) : use_facet<ctype<charT>>(loc), use_facet<numpunct<charT>>(loc)
    basic_istream& operator>>(bool& n);
    basic_istream& operator>>(short& n);
    basic_istream& operator>>(unsigned short& n);
    basic_istream& operator>>(int& n);
    basic_istream& operator>>(unsigned int& n);
    basic_istream& operator>>(long& n);
    basic_istream& operator>>(unsigned long& n);
    basic_istream& operator>>(long long& n);
    basic_istream& operator>>(unsigned long long& n);
    basic_istream& operator>>(float& f);
    basic_istream& operator>>(double& f);
    basic_istream& operator>>(long double& f);
    basic_istream& operator>>(extended - floating - point - type & f);
    basic_istream& operator>>(void*& p);
    basic_istream& operator>>(basic_streambuf<char_type, traits>* sb);

    // 31.7.5.4, unformatted input
    streamsize     gcount() const;
    int_type       get();
    basic_istream& get(char_type& c);
    basic_istream& get(char_type* s, streamsize n);
    basic_istream& get(char_type* s, streamsize n, char_type delim);
    basic_istream& get(basic_streambuf<char_type, traits>& sb);
    basic_istream& get(basic_streambuf<char_type, traits>& sb, char_type delim);

    basic_istream& getline(char_type* s, streamsize n);
    basic_istream& getline(char_type* s, streamsize n, char_type delim);

    basic_istream& ignore(streamsize n = 1, int_type delim = traits::eof());
    basic_istream& ignore(streamsize n, char_type delim);
    int_type       peek();
    basic_istream& read(char_type* s, streamsize n);
    streamsize     readsome(char_type* s, streamsize n);

    basic_istream& putback(char_type c);
    basic_istream& unget();
    int sync();

    pos_type tellg();
    basic_istream& seekg(pos_type);
    basic_istream& seekg(off_type, ios_base::seekdir);
};

// 31.7.5.3.3, character extraction templates
// 문자
template<class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is, charT& c);
template<class traits>
basic_istream<char, traits>& operator>>(basic_istream<char, traits>& is, unsigned char& c);
template<class traits>
basic_istream<char, traits>& operator>>(basic_istream<char, traits>& is, signed char& c);
// if one is available, and stored in c. 
// Otherwise, ios_base::failbit is set in the input function’s local error state before setstate is called.

// 고정 사이즈 문자열
template<class charT, class traits, size_t N>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is, charT(&ca)[N]);
template<class traits, size_t N>
basic_istream<char, traits>& operator>>(basic_istream<char, traits>& is, unsigned char(&ca)[N]);
template<class traits, size_t N>
basic_istream<char, traits>& operator>>(basic_istream<char, traits>& is, signed char(&ca)[N]);
// if width()!=0 
//      n = min(size_t(is.width()), N)  
// else
//      n = N;
// 
//Characters are extracted and stored until any of the following occurs:
//      — n - 1 characters are stored;
//      — end of file occurs on the input sequence;(EOF)
//      — letting ct be use_facet<ctype<charT>>(in.getloc()), ct.is(ct.space, c) is true.
// 
// operator>> then stores a null byte (charT()) in the next position, 
// which may be the first position if no characters were extracted. 
// 
// operator>> then calls is.width(0).
// 
// If the function extracted no characters, 
//  ios_base::failbit is set in the input function’s local error state before setstate is called.

// whitespace를 구분자로 한 문자열
template<class charT, class traits, class Allocator>
basic_istream<charT, traits>&
operator>>(basic_istream<charT, traits>& is, basic_string<charT, traits, Allocator>& str);
// str.erase();
// if width()!=0 
//      n = is.width();
// else
//      n = str.max_size();
//Characters are extracted and stored until any of the following occurs:
//      — n characters are stored;
//      — end of file occurs on the input sequence;(EOF)
//      — letting ct be use_facet<ctype<charT>>(in.getloc()), ct.is(ct.space, c) is true.
// 
// which may be the first position if no characters were extracted. 
// 
// operator>> then calls is.width(0).
// 
// If the function extracted no characters, 
//  ios_base::failbit is set in the input function’s local error state before setstate is called.

template<class charT, class traits>
friend basic_istream<charT, traits>&
operator>>(basic_istream<charT, traits>& is, path& p);
// basic_string<charT, traits> tmp;
// is >> quoted(tmp);
// p = tmp;

template<class charT, class traits, size_t N>
basic_istream<charT, traits>&
operator>>(basic_istream<charT, traits>& is, bitset<N>& x);

//thread::id

template<class T, class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>&, complex<T>&);

template<class charT, class traits>
basic_istream<charT, traits>&
operator>>(basic_istream<charT, traits>& is, linear_congruential_engine& x);

template<class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is, uniform_int_distribution& x);


//*/