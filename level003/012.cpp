import std;
using namespace std;

void facet_id() {
    locale base_loc("");
    locale other_loc("ko_kr.UTF-8");
    do {
        using _FACET = num_put<char>;
        cout << "num_put<char>:" << use_facet<_FACET>(base_loc).id._Get_index() << endl;
        cout << "num_put<char>:" << use_facet<_FACET>(other_loc).id._Get_index() << endl;
    } while (false);

    do {
        using _FACET = num_put<wchar_t>;
        cout << "num_put<wchar_t>:" << use_facet<_FACET>(base_loc).id._Get_index() << endl;
        cout << "num_put<wchar_t>:" << use_facet<_FACET>(other_loc).id._Get_index() << endl;
    } while (false);

    do {
        using _FACET = messages<wchar_t>;
        cout << "messages<wchar_t>:" << use_facet<_FACET>(base_loc).id._Get_index() << endl;
        cout << "messages<wchar_t>:" << use_facet<_FACET>(other_loc).id._Get_index() << endl;
    } while (false);
}

void using_numput() {
    locale base_loc("");
    locale other_loc("ko_kr");
    locale my_loc(base_loc, &use_facet<num_put<char>>(other_loc));

    long long big = 123456789;
    do {        
        stringstream ss;
        ss << big << endl;
        ss << uppercase << hex << big << endl;

        cout << "not using_numput:\n" << ss.str() << endl;        
    } while (false);

    do {
        stringstream ss;
        ss.imbue(my_loc);

        ss << big << endl;
        ss << uppercase << hex << big << endl;

        cout << "using_numput:\n" << ss.str() << endl;
    } while (false);
}

void hex_ll_or_double() {
    long long big{ -1 };
    cout << "long long hex:" << hex << big << endl;
    cout << "long long dec:" << dec << big << endl;
}

void short_hex() {
    short v1{ -1 };
    cout << "dec:" << dec << v1 << endl;
    cout << "hex:" << hex << v1 << endl;
    cout << "hex:" << hex << showbase << v1 << endl;

    long v2{ -1 };
    cout << "long hex:" << hex << showbase << v2 << endl;
}

void stringbuf_output() {
    stringstream s1{}, s2{}, s3{};
    s1 << "s1 stringstream";
    s2 << "s2 stringstream";
    s3 << s1.rdbuf() << ' ' << s2.rdbuf();
    cout << "s3:" << s3.str() << endl; // s3 current state output

    cout << "cout 1:" << s3.rdbuf()<< endl; // s3 consumed
    cout << "cout 2:" << s3.rdbuf()<< endl; // s3 empty sequence
}

void nullptr_void() {
    cout << nullptr << endl;

    int a{};
    cout << &a << endl;
}

auto main() -> int {
    facet_id();
    using_numput();
    hex_ll_or_double();
    short_hex();
    stringbuf_output();
    nullptr_void();
    return 0;
}

/* ostream class의 manipulator를 제외한 formatted function

// stream class의 formatted function vs unformatted function

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

// 28.3.4.3, numeric 2 category:numeric // 산술 타입, const void*
template<class charT, class InputIterator = istreambuf_iterator<charT>>
class num_get;
template<class charT, class OutputIterator = ostreambuf_iterator<charT>>
class num_put;
template<class charT>
class numpunct;
template<class charT>
class numpunct_byname;

// 28.3.4.5, collation 3 category:collate
template<class charT> class collate;
template<class charT> class collate_byname;

// 28.3.4.6, date and time 4 category:time
class time_base;
template<class charT, class InputIterator = istreambuf_iterator<charT>>
class time_get;
template<class charT, class InputIterator = istreambuf_iterator<charT>>
class time_get_byname;
template<class charT, class OutputIterator = ostreambuf_iterator<charT>>
class time_put;
template<class charT, class OutputIterator = ostreambuf_iterator<charT>>
class time_put_byname;

// 28.3.4.7, money 5 category:monetary
class money_base;
template<class charT, class InputIterator = istreambuf_iterator<charT>>
class money_get;
template<class charT, class OutputIterator = ostreambuf_iterator<charT>>
class money_put;
template<class charT, bool Intl = false>
class moneypunct;
template<class charT, bool Intl = false>
class moneypunct_byname;

// 28.3.4.8, message retrieval 6 category:messages
class messages_base;
template<class charT> class messages;
template<class charT> class messages_byname;

template<class charT, class traits = char_traits<charT>>
class basic_ostream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios (31.5.4))
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;

    using _Myios = basic_ios<_Elem, _Traits>;
    using _Mysb  = basic_streambuf<_Elem, _Traits>;
    using _Iter  = ostreambuf_iterator<_Elem, _Traits>;
    using _Nput  = num_put<_Elem, _Iter>; //facet type

    // 31.7.6.3, formatted output
    // manipulator
    basic_ostream& operator<<(basic_ostream& (*pf)(basic_ostream&));
    basic_ostream& operator<<(basic_ios<charT, traits>& (*pf)(basic_ios<charT, traits>&));
    basic_ostream& operator<<(ios_base& (*pf)(ios_base&));
    
    // arithmetic type (numeric formatting: locale/ num_get num_put:facet)
    basic_ostream& operator<<(bool n);
    basic_ostream& operator<<(short n);
    basic_ostream& operator<<(unsigned short n);
    basic_ostream& operator<<(int n);
    basic_ostream& operator<<(unsigned int n);
    basic_ostream& operator<<(long n);
    basic_ostream& operator<<(unsigned long n);
    basic_ostream& operator<<(long long n);
    basic_ostream& operator<<(unsigned long long n);
    basic_ostream& operator<<(float f);
    basic_ostream& operator<<(double f);
    basic_ostream& operator<<(long double f);
    basic_ostream& operator<<(extended_floating_point_type f);
    // void*, nullptr_t, streambuf
    basic_ostream& operator<<(const void* p);
    basic_ostream& operator<<(const volatile void* p);

    basic_ostream& operator<<(nullptr_t);
    basic_ostream& operator<<(basic_streambuf<char_type, traits>* sb);

    // 기본규칙
    //              : 8진수, 16진수 표현: signed type -> unsigned type 변환(보수 표현). 10진수는 원본 타입 유지
    //              : 정수형 타입: unsigned long/long 타입으로 conversion => integral promotion conversion
    //              : 부동소수점 타입: double 타입으로 conversion => floating-point promotion conversion
    //              : extended_floating_point_type 타입: double, long double 타입으로 conversion => extended-floating-point promotion conversion
    //              : const volatile void*에서 const void* 변환 => cv-qualification conversion(casting away volatileness/constness)
    //              : locale의 num_put facet 사용 변환
    // 
    // _Iter _Nput::put(_Iter _Dest, ios_base& _Iosbase, _Elem _Fill, auto val) : facet 호출 함수
    // 
    // val's type : bool, long, unsigned long, long long, unsigned long long, double, long double, or const void*:

    //              bool failed = 
    //              use_facet<_Nput>(getloc()).
    //              put(_Iter(this->rdbuf()), *this, fill(), val).
    //              failed();
    //              if(failed) badbit
    // val's type : unsigned short, unsigned int;
    //              bool failed = 
    //              use_facet<_Nput>(getloc()).
    //              put(_Iter(this->rdbuf()), *this, fill(), static_cast<unsigned long>(val)).
    //              failed();
    //              if(failed) badbit
    // val's type : float;
    //              bool failed = 
    //              use_facet<_Nput>(getloc()).
    //              put(_Iter(this->rdbuf()), *this, fill(), static_cast<double>(val)).
    //              failed();
    //              if(failed) badbit
    // 
    // val's type : short;
    //              ios_base::fmtflags baseflags = ios_base::flags() & ios_base::basefield;
    //              bool failed = 
    //              use_facet<_Nput>(getloc()).
    //              put(_Iter(this->rdbuf()), *this, fill(), 
    //                  baseflags == ios_base::oct || baseflags == ios_base::hex ? 
    //                  static_cast<long>(static_cast<unsigned short>(val)) : static_cast<long>(val)).
    //              failed();  
    //              if(failed) badbit          
    // val's type : int;
    //              ios_base::fmtflags baseflags = ios_base::flags() & ios_base::basefield;
    //              bool failed = 
    //              use_facet<_Nput>(getloc()).
    //              put(_Iter(this->rdbuf()), *this, fill(), 
    //                  baseflags == ios_base::oct || baseflags == ios_base::hex ? 
    //                          static_cast<long>(static_cast<unsigned int>(val)) : static_cast<long>(val)).
    //              failed(); 
    //              if(failed) badbit
    // val's type : nullptr_t;
    //              implementation string, ex) "nullptr"
    // val's type : const volatile void*;
    //              return operator<<(const_cast<const void*>(p));
    // val's type : extended_floating_point_type;
    //              bool failed = 
    //                  use_facet<_Nput>(getloc()).
    //                  put(_Iter(this->rdbuf()), *this, fill(), static_cast<double>(val))
    //                  .failed()
    //              bool failed = 
    //                  use_facet<_Nput>(getloc()).
    //                  put(_Iter(this->rdbuf()), *this, fill(), static_cast<long double>(val))
    //                  .failed()
    // val's type : basic_streambuf<char_type, traits>*; // unformatted function처럼 거동
    //              sb가 EOF가 될 때 또는 insert 실패(exception 포함)까지 수행
    //              insert count==0: failbit
    //              insert count>0 상태로 실패: badbit
    //              sb == null :  badbit 

};

//*/