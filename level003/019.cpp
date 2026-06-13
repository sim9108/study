
import std;
using namespace std;

using istream_type = istringstream;
using ostream_type = ostringstream;
using streambuf_type = stringbuf;

using int_type = istream_type::int_type;
using char_type = istream_type::char_type;
using traits_type = istream_type::traits_type;

void read_test() {
    do {
        istream_type ss{ "123456" };

        constexpr size_t LEN = 5;
        char_type buf[LEN];
        ss.read(buf, LEN);

        streamsize len = ss.gcount();
        size_t m_len = static_cast<size_t>(len);

         cout.write(buf, LEN) << endl;
         println("buf:{:?} gcount:{} fail:{}", string_view{ buf,m_len }, len, ss.fail());
        // println("buf:{:?} gcount:{} fail:{}", buf, ss.gcount(), ss.fail());
    } while (false);

    do {
        istream_type ss{ "123456" };
        constexpr size_t LEN = 10;
        char_type buf[LEN];
        ss.read(buf, LEN);

        streamsize len = ss.gcount();
        size_t m_len = static_cast<size_t>(len);

        println("read buf:{:?} gcount:{} fail:{}", string_view{ buf,m_len }, ss.gcount(), ss.fail());
    } while (false);

    do {
        istream_type ss{ "123" };
        constexpr size_t LEN = 5;
        char_type buf[LEN];
        
        do {
            streamsize cnt = ss.readsome(buf, LEN);
            size_t m_len = static_cast<size_t>(cnt);

            println("#1 readsome buf:{:?} cnt:{} gcount:{} eof:{}", string_view{ buf,m_len }, cnt, ss.gcount(),ss.eof());
        } while (false);

        do {
            streamsize cnt = ss.readsome(buf, LEN);
            size_t m_len = static_cast<size_t>(cnt);

            println("#2 readsome buf:{:?} cnt:{} gcount:{} eof:{}", string_view{ buf,m_len }, cnt, ss.gcount(), ss.eof());
        } while (false);

    } while (false);
}

auto main() -> int {
    read_test();
    return 0;
}

/* istream class의 read/readsome unformatted function 

// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)


template<class charT, class traits = char_traits<charT>>
class basic_istream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios)
    using   char_type = charT;
    using    int_type = traits::int_type; // eof + char_type;
    using    pos_type = traits::pos_type;
    using    off_type = traits::off_type;
    using traits_type = traits;

    // 31.7.5.4, unformatted input
    // getline vs read, readsome
    basic_istream& read(char_type* s, streamsize n);
    // extracts characters and stores them into successive locations of an array 
    //      whose first element is designated by s.
    // Characters are extracted and stored until either of the following occurs:
    //      - n characters are stored;
    //      - EOF occurs on the input sequence 
    //          (in which case the function calls setstate(failbit|eofbit),
    //              which may throw ios_base::failure).
    // ** null not append, exactly n characters
    // Returns: *this;

    streamsize     readsome(char_type* s, streamsize n);
    // extracts characters and stores them into successive locations of an array 
    //      whose first element is designated by s.
    // *** rdbuf()->in_avail check!! ****
    //  — If rdbuf()->in_avail() == -1, calls setstate(eofbit);
    //      (which may throw ios_base::failure), and extracts no characters;
    //  - If rdbuf()->in_avail() > 0, extracts read(s, min(rdbuf()->in_avail(), n)); always success
    // // If rdbuf()->in_avail() == 0, extracts no characters
    // return The number of characters extracted;

};

//*/