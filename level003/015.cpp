import std;
using namespace std;

void fast_copy() {
   ifstream src("big.txt", ios_base::binary);
   ofstream target("target.txt", ios_base::binary);

    if (!src || !target) {
        cerr << "copy fail" << endl;
        return;
    }
    cout << "fast copy";
    target << src.rdbuf();
}

void fast_read() {
    ofstream target("write.txt");
    if (!target) {
        cerr << "read fail" << endl;
        return;
    }
    cout << "break CTL+Z" << endl;
    cin >> target.rdbuf();
}

void boolalpha_test() {
    cout << "bool alpha test:";
    bool b{};
    cin >> boolalpha >> b;    
    cout << "failed:" << cin.fail() << endl;
    cout << boolalpha << b << endl;
}

void basic_test() {
    cout << "age:?" << endl;
    int a{};
    cin >> a;
    cout << a;
}

auto main() -> int {  
    fast_copy();
    fast_read();
    
    basic_test();
    boolalpha_test();
    return 0;
}


/* istream class의 formatted function

// stream class의 formatted function vs unformatted function
//
// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)

// ostream
template<class charT, class OutputIterator = ostreambuf_iterator<charT>>
class num_put : public locale::facet {
public:
    using char_type = charT;
    using iter_type = OutputIterator;

    explicit num_put(size_t refs = 0);

    iter_type put(iter_type s, ios_base& f, char_type fill, bool v) const;
    iter_type put(iter_type s, ios_base& f, char_type fill, long v) const;
    iter_type put(iter_type s, ios_base& f, char_type fill, long long v) const;
    iter_type put(iter_type s, ios_base& f, char_type fill, unsigned long v) const; // int 유형 없음, short 유형없음
    iter_type put(iter_type s, ios_base& f, char_type fill, unsigned long long v) const;
    iter_type put(iter_type s, ios_base& f, char_type fill, double v) const;        // float 유형없음
    iter_type put(iter_type s, ios_base& f, char_type fill, long double v) const;
    iter_type put(iter_type s, ios_base& f, char_type fill, const void* v) const;

    static locale::id id;
protected:
    ~num_put();
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, bool v) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, long v) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, long long v) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, unsigned long) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, unsigned long long) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, double v) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, long double v) const;
    virtual iter_type do_put(iter_type, ios_base&, char_type fill, const void* v) const;
};

// istream
template<class charT, class InputIterator = istreambuf_iterator<charT>>
class num_get : public locale::facet {
public:
    using char_type = charT;
    using iter_type = InputIterator;

    explicit num_get(size_t refs = 0);

    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, bool& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, long& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, long long& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, unsigned short& v) const;     // short 없음
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, unsigned int& v) const;       // int 없음
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, unsigned long& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, unsigned long long& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, float& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, double& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, long double& v) const;
    iter_type get(iter_type in, iter_type end, ios_base&, ios_base::iostate& err, void*& v) const;

    static locale::id id;

protected:
    ~num_get();
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, bool& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, long& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, long long& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, unsigned short& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, unsigned int& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, unsigned long& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, unsigned long long& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, float& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, double& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, long double& v) const;
    virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate& err, void*& v) const;
};


template<class charT, class traits = char_traits<charT>>
class basic_istream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios (31.5.4))
    using   char_type = charT;
    using    int_type = traits::int_type;
    using    pos_type = traits::pos_type;
    using    off_type = traits::off_type;
    using traits_type = traits;

    // 31.7.5.2.4, prefix/suffix
    class sentry;
    //  formatted/unformatted input function; //bool _Noskip = false/true
    //  prefix operations: streambuf' lock, tie()->flush(), skipws[input]
    //  suffix operations: streambuf' unlock
    //  exception safety level
    //      1. Nothrow / Nofail
    //      2. Strong Guarantee(Roll back Guarantee)
    //      3. Basic Guarantee(State sync Guarantee)*
    //      4. No Guarantee
    // 

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


//*/