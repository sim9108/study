
import std;
using namespace std;

using stream_type = stringstream;
using istream_type = istringstream;
using ostream_type = ostringstream;
using streambuf_type = stringbuf;

using int_type = istream_type::int_type;
using char_type = istream_type::char_type;
using traits_type = istream_type::traits_type;

void peek_test() {
    istream_type ss{ "start#23567#8934" };
    int_type ic = ss.peek();

    if (!traits_type::eq_int_type(ic, traits_type::eof())) {
        println("int_type:{} char_type:{:?} gcount:{}",
            ic, traits_type::to_char_type(ic), ss.gcount());
    }
    else {
        println("int_type:{} gcount:{}", ic, ss.gcount());
    }
}

void ignore_test() {
    istream_type ss{ "1234#ab#8934" };
    ss.ignore(10, ss.widen('#')); // unformatted
    // ss.ignore(10, traits_type::to_char_type(ss.widen('#'))); // unformatted, gcount O

    string str;
    getline(ss, str, ss.widen('#')); // unformatted, gcount X

    char_type c{};
    ss >> c; // formatted
    println("str:{:?} c:{:?} gcount:{}", str, c, ss.gcount());
}


void cin_putback_unget_test() {
    using stream_type = decltype(cin);
    using char_type = stream_type::char_type;
    using traits_type = stream_type::traits_type;
    using ctype_type = ctype< char_type>;

    ctype_type const& ctype = use_facet<ctype_type>(cin.getloc());

    char_type ch{};
    cin >> ch; 
    cin.unget();

    if (ctype.is(ctype_type::digit,ch)) {
        // cin.putback(cin.widen('3'));
        int a{};
        cin >> a;
        cout << "it is number: " << a << '\n';
    }
    else {
       // cin.putback(cin.widen('A'));
        string text;
        cin >> text;
        cout << "it is string: " << text << '\n';
    }
}

void putback_unget_test() {
    do {
       // istream_type ss{ "1abcdef" };
        stream_type ss{ "1abcdef" };
        char_type c{};
        ss >> c;

        //ss.unget();
        ss.putback(ss.widen('7'));        
        bool bfail = ss.fail();

        ss.clear();
        string str;
        ss >> str;
        println("str:{} gcount:{} fail:{}", str, ss.gcount(), bfail);
    } while (false);

    do {
        istream_type ss{ "abcdef" };
        char_type c{};
        ss >> c;

        ss.unget();

        //ss.clear();

        string str;
        ss >> str;
        println("unget str:{} gcount:{} fail:{}", str, ss.gcount(), ss.fail());
    } while (false);

    do {
        do {
            ofstream wss{ "putback.txt", ios_base::out | ios_base::trunc };
            wss << "123456789";
        } while (false);

        string bufstr, filestr;
        
        do {
            fstream ss{ "putback.txt", ios_base::in | ios_base::out };
            using char_type = fstream::char_type;

            char_type c{};
            ss >> c;
            //ss.unget();
            //ss.putback(ss.widen('1'));
            ss.putback(ss.widen('P'));

            ss >> bufstr;
        } while (false);

        do {
            ifstream ss{ "putback.txt"};
            ss >> filestr;
        } while (false);

        println("bufstr:{} filestr:{}", bufstr, filestr);
    } while (false);
}

auto main() -> int {
    cin_putback_unget_test();
    putback_unget_test();
    ignore_test();
    peek_test();
    return 0;
}


/* istream class의 putback, unget, ignore, peek unformatted function 
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
    basic_istream& putback(char_type c);
    // If rdbuf() is null
    //          badbit 설정
    // otherwise
    //    int_type c = rdbuf()->sputbackc(c). // writable *** 일관성 주의(데이터 일관성, 사용성 일관성)
    //    if traits_type::eq_int_type(c, traits_type::eof)
    //      badbit 설정
    // the next call to gcount() is 0

    //**** int_type sputbackc(char_type c);******streambuf******
    //    Effects: 
    //      If the input sequence putback position is not available, or if traits::eq(c, gptr()[-1]) is false, 
    //          returns pbackfail(traits::to_int_type(c)). ***gptr() == eback(), gptr() == nullptr,  or traits::eq(c, gptr()[-1]) is false **
    //      Otherwise, 
    //          decrements the next pointer for the input sequence and 
    //          returns traits::to_int_type(*gptr()).

    basic_istream& unget();
    // If rdbuf() is null
    //          badbit 설정
    // otherwise
    //      int_type c = rdbuf()->sungetc() // reabable *** 일관성 유지
    //      if traits_type::eq_int_type(c, traits_type::eof)
    //          badbit 설정
    // the next call to gcount() is 0

    //**** int_type sungetc();******streambuf******
    //    Effects: 
    //      If the input sequence putback position is not available, 
    //          returns pbackfail(traits::eof()). ***gptr() == eback(), or gptr() == nullptr**
    //      Otherwise,
    //          decrements the next pointer for the input sequence and 
    //          returns traits::to_int_type(*gptr()).


    // ****** int_type pbackfail(int_type c = traits::eof()); ******
    // The pending sequence is defined as for underflow(), with the modifications that
    //      — If traits::eq_int_type(c, traits::eof()) == true, ***gptr() == eback(), or gptr() == nullptr**
    //              then the input sequence is backed up one character before the pending sequence is determined.
    //      — If traits::eq_int_type(c, traits::eof()) == false, ***gptr() == eback() or traits::eq(c, gptr()[-1]) is false **
    //              then c is prepended.
    //              Whether the input sequence is backed up or modified in any other way is unspecified(*).    //              
    //  Returns :  
    //      if the input sequence could not be backed up(**empty**), or 
    //      if for some other reason the pointers cannot be set consistent with(****) the constraints,
    //          traits::eof() to indicate failure.
    //      otherwise
    //          Returns some value other than traits::eof() to indicate success.          
    //  Default behavior : Returns traits::eof().
    //  Remarks : 
    //      The public functions of basic_streambuf call this virtual function only when 
    //          gptr() is null, 
    //          gptr() == eback(), or 
    //          traits::eq(traits::to_char_type(c), gptr()[-1]) ==false.

    basic_istream& ignore(streamsize n = 1, int_type delim = traits::eof());
    // extracts characters(int_type c = rdbuf()->sbumpc()) and discards them. 
    // Characters are extracted until any of the following occurs:
    //      1. if n != numeric_limits<streamsize>::max() and n characters have been extracted so far,
    //      2. if traits::eq_int_type(c, traits::eof())
    //              eofbit 설정;
    //      3. if traits::eq_int_type(c, delim)
    //          (in which case c is extracted ***)
    // 
    // retrun *this;

    basic_istream& ignore(streamsize n, char_type delim);
    // Constraints: is_same_v<char_type, char> is true;
    // return ignore(n, traits::to_int_type(delim));

    int_type       peek();
    // reads but does not extract the current input character.
    // if not good(),
    //          return traits::eof();
    // otherwise
    //          _Meta = rdbuf()->sgetc();
    //          if(traits_type::eq_int_type(traits_type::eof(), _Meta)) eofbit 설정;
    //          return _Meta;
};

//*/