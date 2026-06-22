
import std;
using namespace std;

template<class charT, class traits = char_traits<charT>>
basic_ios<charT, traits>& mymani(basic_ios<charT, traits>& ios) {
    cout << setfill(cout.widen('*')) << setw(50) << internal << hex << uppercase << showbase;
    cout << 255 << endl;
    return ios;
}

void ws_test() {
    do {
        string str;
        getline(cin, str, cin.widen('\n')); // unformatted
        println("#1|{}|", str);
    } while (false);
    do {
        string str;
        getline(cin >> ws, str, cin.widen('\n')); // unformatted but formatted like
        println("#2|{}|", str);
    } while (false);
}


auto main() -> int {
    //cout << mymani;
    ws_test();
    return 0;
}

/* //
template<class charT, class traits = char_traits<charT>>
class basic_ostream : virtual public basic_ios<charT, traits> {
public:
    // 31.7.6.3, formatted output
    basic_ostream& operator<<(basic_ostream& (*pf)(basic_ostream&));
    basic_ostream& operator<<(basic_ios<charT, traits>& (*pf)(basic_ios<charT, traits>&));
    basic_ostream& operator<<(ios_base& (*pf)(ios_base&));
};

template<class charT, class traits = char_traits<charT>>
class basic_istream : virtual public basic_ios<charT, traits> {
public:
    // 31.7.5.3, formatted input
    basic_istream& operator>>(basic_istream& (*pf)(basic_istream&));
    basic_istream& operator>>(basic_ios<charT, traits>& (*pf)(basic_ios<charT, traits>&));
    basic_istream& operator>>(ios_base& (*pf)(ios_base&));
};

///////// basic_ostream /////////
// 31.7.6.5, standard basic_ostream manipulators
template<class charT, class traits>
basic_ostream<charT, traits>& endl(basic_ostream<charT, traits>& os);
// os.put(os.widen('\n'));
// os.flush();
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& ends(basic_ostream<charT, traits>& os);
// os.put(charT());
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& flush(basic_ostream<charT, traits>& os);
// os.flush();
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& emit_on_flush(basic_ostream<charT, traits>& os);
// const auto _ptr = dynamic_cast<basic_syncbuf<charT, traits, Allocator>*>(os.rdbuf());
// if(_ptr) _ptr->set_emit_on_sync(true);
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& noemit_on_flush(basic_ostream<charT, traits>& os);
// const auto _ptr = dynamic_cast<basic_syncbuf<charT, traits, Allocator>*>(os.rdbuf());
// if(_ptr) _ptr->set_emit_on_sync(false);
// return os;

template<class charT, class traits>
basic_ostream<charT, traits>& flush_emit(basic_ostream<charT, traits>& os);
// os.flush();
// const auto _ptr = dynamic_cast<basic_syncbuf<charT, traits, Allocator>*>(os.rdbuf());
// if(_ptr) {
//  sentry OK{os};
//  if(OK) {
//      const bool success = _ptr->emit();
//      if(!success) // badbit
//  } else{
//      // badbit
//  }
// }
// return os;


////// basic_istream ///////
// 31.7.5.5, standard basic_istream manipulators
template<class charT, class traits>
basic_istream<charT, traits>& ws(basic_istream<charT, traits>& is)

//*/