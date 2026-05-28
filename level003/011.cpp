import std;
using namespace std;

void exception_fn() {
    stringstream ss{ "10abc20def30ttt40pp" };
    ss.exceptions(ios_base::failbit | ios_base::badbit | ios_base::eofbit);

    int sum{ 0 };
    do {
        try {
            if (ss.fail()) {
                ss.clear();
                ss.ignore();
            }
            int a{};
            ss >> a;
            sum += a;
        }
        catch (ios_base::failure&) {
            // 또다른 예외는 crash
            if (ss.eof()) break;
            if (ss.bad()) break;
        }          
    } while (true);

    cout << "sum:" << sum << endl;
}

void iostate_fn() {
    stringstream ss{ "10abc20def30ttt40pp" };
    int sum{ 0 };
    do {
        int a{};
        ss >> a;
        
        if (ss.eof()) {
            cout << "eof"; break;
        }
        if (ss.bad()) break;
        if (ss.fail()) {                      
            ss.clear();
            ss.ignore(); 
            if (ss.eof()) {
                cout << "eof"; break;
            }
            continue;
        }        
        sum += a;
        
    } while (true);

    cout << "sum:" << sum << endl;
}

auto main() -> int {
    exception_fn();
    iostate_fn();
    return 0;
}

/*
class ios_base {
    // 31.5.2.2.3, iostate
    using iostate = T2; // bitmask type; buffer state, exception state;
    static constexpr iostate badbit  = unspecified; 
            // 버퍼 완전성이 신뢰할 수 없음(버퍼가 없는 경우도 포함)
            // [input] 읽기 작업을 수행하던 중 실패함
            // [output] 쓰기 작업을 수행하던 중 실패함. 
    static constexpr iostate eofbit  = unspecified; 
            // [input] end of an input sequence. gptr를 읽기할 때 반별
    static constexpr iostate failbit = unspecified; 
            // [input]  쓰기 요청을 수행할 수 없음, gptr 그대로
            // [output] 읽기 요청을 수행하지 못함, pptr 그대로
    static constexpr iostate goodbit = see below;   // the value zero.
    // 31.5.2.2.4, openmode
    using openmode = T3;
    static constexpr openmode app       = unspecified;
    static constexpr openmode ate       = unspecified;
    static constexpr openmode binary    = unspecified;
    static constexpr openmode in        = unspecified;
    static constexpr openmode noreplace = unspecified;
    static constexpr openmode out       = unspecified;
    static constexpr openmode trunc     = unspecified;

    // 31.5.2.2.5, seekdir
    using seekdir = T4;
    static constexpr seekdir beg = unspecified;
    static constexpr seekdir cur = unspecified;
    static constexpr seekdir end = unspecified;

};

template<class charT, class traits = char_traits<charT>>
class basic_ios : public ios_base {
public:
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;

    // 31.5.4.4, flags functions
    explicit operator bool() const; // return !fail();
    bool         operator!() const; // return fail();
    iostate      rdstate() const;   // return _State;
    bool         good() const;      // return rdstate()==0;
    bool         eof() const;       // return true if eofbit is set in rdstate().
    bool         fail() const;      // return true if failbit or badbit is set in rdstate().
    bool         bad() const;       // return true if badbit is set in rdstate().

    void         clear(iostate state = goodbit);
                     // _State = (state | (rdbuf() ? goodbit : badbit) : 
                     // if( _State & exceptions() != 0) then exception throw
    void         setstate(iostate state);
                     // clear(rdstate() | state) 


    iostate     exceptions() const;  
                    // reutrn _Except;

    void        exceptions(iostate except);
                    // _Except= except;
                    // clear(rdstate());
private:
    iostate _State{ goodbit };
    iostate _Except{ goodbit };
};
//*/