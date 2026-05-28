import std;
using namespace std;
#include <cstdio>

void save_bigfile() {
    cout << "buf default size:" << BUFSIZ << endl;

    ofstream outfile("bigfile.txt", ios_base::out|ios_base::app);  

    vector<char> buf(1024 * 64); 
    outfile.rdbuf()->pubsetbuf(buf.data(), buf.size());
    // first  // iostate problem

    do{
        if (!outfile.is_open()) {
            cout << "file open failed";
            break;
        }     
        outfile << "big data\n";
        outfile.close();
    } while (false);
}

void unbufferd_file() {
    ofstream outfile("unbufferd.txt", ios_base::out | ios_base::trunc);
    outfile.rdbuf()->pubsetbuf(nullptr, 0); // first  // iostate problem
    do {
        if (!outfile.is_open()) {
            cout << "file open failed";
            break;
        }        
        outfile << "0123456789";
        outfile.close();
    } while (false);
}

void pos_file() {
    do {
        ifstream infile("unbufferd.txt", ios_base::in);
        if (!infile.is_open()) {
            cout << "file open failed";
            break;
        }

        infile.seekg(-2, ios_base::end);
        streampos pos = infile.tellg();
        string str1{};
        infile >> str1;

        infile.seekg(streampos(2));
        string str2{};
        infile >> str2;
        cout << "pos:" << pos << " str1:|" << str1 << "| str2:|" << str2 << "|";
    } while (false);
}

void file_sync() {
    do {
        ofstream f1{ "test.txt" };
        f1 << "123";
    } while (false);

    ifstream f2{ "test.txt" };
    char c1{}, c2{}, c3{};
    f2 >> c1;

    do {
        ofstream f3{ "test.txt" };
        f3 << "ABC";
    } while (false);

    f2 >> c2;
    f2.sync();
    f2 >> c3;
    f2.close();
    cout << c1 << c2 <<c3;

}


auto main() -> int {
    save_bigfile();
    unbufferd_file();
    pos_file();
    file_sync();
    return 0;
}

/*
template<class charT, class traits = char_traits<charT>>
class basic_streambuf {
public:
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;
protected:
    // 주어진 내부 버퍼에 대한 제어 함수
    void    setp(char_type* pbeg, char_type* pend); // output buffer(pbase, pptr, epptr)
    void    setg(char_type* gbeg, char_type* gnext, char_type* gend); // input buffer(eback, gptr, egptr)

public:
    // 31.6.3.3.2, buffer and positioning
    basic_streambuf* pubsetbuf(char_type* s, streamsize n); // 사용할 버퍼 지정하고 setp/setg에서 사용한다
    pos_type         pubseekoff(off_type off, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out);
    pos_type         pubseekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out);
    int              pubsync();

    // non-virtual interface pattern:
    //      library vs user : Design advantageous for library expansion
    // pub interface vs internel interface

protected:
    // 31.6.3.5.2, buffer management and positioning
    virtual basic_streambuf* setbuf(char_type* s, streamsize n);
    // buffer seperate
    // ex) big buffer/unbuffered for fstream
    // stringstream: ignored 
    //                              
    virtual pos_type    seekoff(off_type off, ios_base::seekdir way,ios_base::openmode which = ios_base::in | ios_base::out);
    virtual pos_type    seekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out);
    // the stream positions within one or more of the controlled sequences, cross link buffer
    // enumerated type ios_base::seekdir  => streampos vs off_type
    //              beg, cur, end
    // if fail
    //      return pos_type(off_type(-1));
    // else
    //      return pos_type(current postion);
    virtual int     sync(); 
    // static bool ios_base::sync_with_stdio(bool sync = true);는 다른 의미
    // [input stream] : synchronize with input source(option)
    //      if pbase() is not null 
    //          write buffer flush: [pbase(), pptr()]를 flush: external buffer update
    //      end if
    //      read buffer synchronize with input source
    //              - Clear the residue remaining in the buffer
    //              - no action
    // return -1: fail (ex buffer is null)
    // return 0: success
};
//*/