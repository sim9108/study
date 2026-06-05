import std;
using namespace std;

void check_stringstream(stringstream& ss) {
    using stream_type = stringstream;
    using char_type   = stream_type::char_type;
    using traits_type = stream_type::traits_type;
    using pos_type    = stream_type::pos_type;
    using off_type    = stream_type::off_type;

    char_type const buf[]{ "0123456789" };
    streamsize len = traits_type::length(buf);
    ss.write(buf, len);
    ss.put(char_type{ '0' });
    cout << ss.str() << endl;

    do {
        ss.seekp(off_type{-3}, ios_base::end);
        pos_type pos_cur = ss.tellp();
        ss << "|" << pos_cur + off_type{ 1 } << "|";
        cout << ss.str() << endl;
    } while (false);

    do {
        ss.seekp(off_type{ 2 }, ios_base::beg);
        pos_type pos_cur = ss.tellp();
        ss << "|" << pos_cur + off_type{ 1 } << "|";
        cout << ss.str() << endl;
    } while (false);

    do {
        ss.seekp(pos_type{ 5 });
        pos_type pos_cur = ss.tellp();
        ss << "|" << pos_cur + off_type{ 1 } << "|";
        cout << ss.str() << endl;
    } while (false);

    do {
        ss.flush();
        cout << ss.str() << ":flush" << endl;
    } while (false);
}

auto main() -> int {
    stringstream ss;
    check_stringstream(ss);        
    return 0;
}

/* ostream class의 unformatted function

// stream class의 formatted function vs unformatted function
//
// formatting 요소: fmtflags, width()(최소폭, padding data), precision(), fill(), locale
//              전달한 데이터를 새로운 형태의 데이터 변경 
//              type 의존적인 변환(not raw data)


template<class charT, class traits = char_traits<charT>>
class basic_ostream : virtual public basic_ios<charT, traits> {
public:
    // types (inherited from basic_ios (31.5.4))
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;

    // 31.7.6.4, unformatted output
    basic_ostream& put(char_type c);
    // int_type i = this->rdbuf()->sputc(c);
    // if(traits::eq_int_type(traits::eof(), i) ) // badbit 설정
    // return *this;

    basic_ostream& write(const char_type* s, streamsize n);
    // streamsize sz = this->rdbuf()->sputn(s, n);
    // if(sz!=n) // badbit 설정
    // return *this;

    basic_ostream& flush();
    // auto ptr = this->rdbuf();
    // if(ptr) { 
    //      int ret = ptr->pubsync(); // -1:실패, badbit
    // } 
    // return *this;
    
    // 31.7.6.2.5, seeks
    pos_type tellp();
    // if(!this->fail()) { 
    //      return this->rdbuf()->pubseekpos(0, ios_base::cur, ios_base::out);
    // } 
    // return pos_type{off_type{-1}};;

    basic_ostream& seekp(pos_type pos);
    // if(!this->fail()) { 
    //      pos_type ret = this->rdbuf()->pubseekpos(pos, ios_base::out); // -1:실패, failbit
    // } 
    // return *this;

    basic_ostream& seekp(off_type off, ios_base::seekdir way);
    // if(!this->fail()) { 
    //      pos_type ret = this->rdbuf()->pubseekpos(off, way, ios_base::out); // -1:실패, failbit
    // } 
    // return *this;
};

//*/