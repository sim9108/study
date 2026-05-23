import std;
using namespace std;

template <class _Elem = char, class _Traits = char_traits<_Elem>>
class SimpleInputBuffer : public basic_streambuf<_Elem, _Traits> {
    using char_type = _Elem;
    using traits_type = _Traits;
    using int_type = _Traits::int_type;

private:
    static const size_t BUFFER_SIZE = 4;
    basic_string<char_type> src_;
    vector<char_type> buffer_;    
    size_t idx_;

public:
    SimpleInputBuffer(const basic_string<char_type>& source)
        : buffer_(BUFFER_SIZE), src_(source), idx_(0) {
        this->setg(buffer_.data(), buffer_.data(), buffer_.data());
    }

protected:
    int_type underflow() override {
        if (idx_ >= src_.size()) {
            return traits_type::eof();
        }

        size_t bytes_to_read = min(BUFFER_SIZE, src_.size() - idx_);

        copy_n(src_.begin() + idx_, bytes_to_read, buffer_.begin());
        idx_ += bytes_to_read;

        this->setg(buffer_.data(), buffer_.data(), buffer_.data() + bytes_to_read);
        cout << "\n[underflow(): " << bytes_to_read << " byte load]\n";
        return traits_type::to_int_type(*this->gptr());
    }
};

auto main() -> int {
    do {
        SimpleInputBuffer buffer("1234567890"s);
        istream in(&buffer);

        char ch;
        while (in >> ch, !in.fail()) {
            cout << ch << " ";
        }

        println("\neof:{}", in.eof());
    } while (false);
    return 0;
}


/*
// controlled sequence vs associated sequence
// 3 pointer: xbeg, xnext, xend 
// xbeg==xnext==xend==nullptr 허용(unbuffered stream 객체 구현 가능)
// 
// [output] 3 pointer: pbase(), pptr(), epptr();
// [input]  3 pointer: eback(), gptr(), egptr();
// 
// [output] xnext < xend: write position is available, otherwise overflow;  
// [output] pending sequence:[pbase(),pptr)
// [output] consumed sequence:associated sequence로 전송 완료된 sequence
// 
// [input]  xnext < xend: read position is available, otherwise underflow 
// [input]  xbeg < xnext: putback position is available, otherwise pbackfail  
// 
// [input] backup sequence/consume sequence:[eback(), gptr())
// [input] pending sequence:[gptr(), egptr()) + sequence of characters read from the input sequence



template<class charT, class traits = char_traits<charT>>
class basic_streambuf {
public:
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;
public:
    // 31.6.3.3.4, putback
    int_type sputbackc(char_type c);
    // if putback postion is available && traits::eq(c, gptr()[-1])
    //          --gptr(),returns traits::to_int_type(*gptr());
    // otherwise 
    //          pbackfail(traits::to_int_type(c));
    int_type sungetc();
    // if putback postion is available
    //          --gptr(),returns traits::to_int_type(*gptr()); 
    // otherwise 
    //          pbackfail();
protected:
    virtual int_type pbackfail(int_type c = traits::eof());
    // if putback postion is not available
    //          버퍼밀기 / 재할당 / 파일 포인터 역이동 / give up 
    // if putback postion is not available
    //          return traits::eof();
    // if traits::eq_int_type(c, traits::eof())
    //          gbump(-1), return traits_type::not_eof(c);
    // if !traits::eq_int_type(c, traits::eof())
    //          gbump(-1),*gptr()=c, return traits_type::not_eof(c);

public:
    // 31.6.3.3.5, put area
    int_type sputc(char_type c);
    // if write position is not available
    //      return overflow(traits::to_int_type(c))
    // else
    //      *pptr() = c;
    //      pbump(1);
    //      return traits::to_int_type(c);
    streamsize sputn(const char_type* s, streamsize n);
    // return xsputn(s, n);

protected:
    // 31.6.3.4.3, put area access [output]
    char_type* pbase() const;
    char_type* pptr() const;
    char_type* epptr() const;
    void       pbump(int n);
    // pptr() += n;
    void       setp(char_type* pbeg, char_type* pend);

    // 31.6.3.5.5, put area
    virtual streamsize xsputn(const char_type* s, streamsize n);
    // streamsize tcnt{};
    // while(n>0){
    //  if(pptr() >= epptr()) {
    //    if(overflow(traits_type::to_int_type(*s)) == traits_type::eof()) break;
    //    --n;
    //    ++tcnt;
    //    s++;
    //  }
    //  streamsize count = min(epptr() - pptr(),n);
    //  memcpy(pptr(),s,count);
    //  pbump(count);
    //  tcnt +=count;
    //  n -=count
    //  s +=count;
    // }
    // return tcnt; 

    virtual int_type   overflow(int_type c = traits::eof());
    // if eq_int_type(c, traits::eof())
    //      pending sequence:[pbase(),pptr)
    // else 
    //      pending sequence:[pbase(),pptr) + c
    // consume pending sequence;
    // return traits_type::not_eof(c);

public:
    // 31.6.3.3.3, get area
    streamsize in_avail();  
    // if read position is available 
    //      returns egptr() - gptr();
    // otherwise 
    //      return showmanyc();
    
    int_type sgetc();       
    // if read position is not available 
    //      return underflow();
    // otherwise
    //      return traits::to_int_type(*gptr());

    int_type sbumpc();
    // if read position is not available
    //      return uflow();
    // otherwise
    //      int_type c = traits::to_int_type(*gptr()); 
    //      if traits::eq_int_type(c, traits::eof()) {
    //          return traits::eof();
    //      }
    //      gptr++; 
    //      return c; 

    int_type snextc();      
    // int_type c = sbumpc();
    // if traits::eq_int_type(c, traits::eof())
    //      return traits::eof();
    // otherwise
    //      return sgetc(); // next character
      

    streamsize sgetn(char_type* s, streamsize n); 
    // return xsgetn(s, n);

protected:
    // 31.6.3.4.2, get area access[input]
    char_type* eback() const;
    char_type* gptr() const;
    char_type* egptr() const;
    void       gbump(int n);
    // gptr() += n;
    void       setg(char_type* gbeg, char_type* gnext, char_type* gend);

    // 31.6.3.5.3, get area
    virtual streamsize showmanyc();
    // 양수: 즉시 읽어낼 수 있는 문자수
    //   0: blocking할 수 있지만 여전히 읽어낼 문자가 있음.
    //  -1: 읽어낼 문자가 없음
    virtual int_type underflow();
    // input seqence assign from pending sequence(usual backup condition 구현)
    // if the pending sequence is empty, 
    //      return traits::eof();
    // else
    //      pending sequence 채움.
    //      return traits::to_int_type(c), where c is the first character of the pending sequence.
    // (peek mode)
    virtual int_type uflow();
    //  int_type c = underflow(); 
    //  do {
    //       if traits::eq_int_type(c, traits::eof()) break;
    //       gbump(1); 
    //  } while(false);
    //  return c; 

    virtual streamsize xsgetn(char_type* s, streamsize n);
    //  streamsize tcnt{};
    //  while(n>0){
    //   if(gptr() >= egptr()) {
    //      if traits::eq_int_type(underflow(), traits_type::eof()) break;
    //   }
    //   streamsize count = min(egptr() - gptr(),n);
    //   memcpy(s,gptr(),count);
    //   gbump(count);
    //   tcnt += count;
    //   n -= count
    //   s += count;
    // }
    // return tcnt; 
};
//*/