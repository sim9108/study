import std;
using namespace std;

void sync1_test() {
    cout << "cout1\n";

    do {
        osyncstream bout(cout);
        bout << "Hello, ";
        bout << "World!";
        cout << "cout2\n";
        bout << endl; // flush is noted
        bout << "and more!\n";
    } while (false);
    // characters are transferred and cout is flushed
}

void sync2_test() {
    do {
       osyncstream(cout) << "Hello, " << (cout << "cout2\n", "World!") << '\n';
   } while (false);
   
}

void sync3_test() {
   do {
        osyncstream bout(cout);
        bout << "Hello," << '\n';       // no flush
        bout.emit();                    // characters transferred; cout not flushed
        bout << "World!" << endl;       // flush noted; cout not flushed
        bout.emit();                    // characters transferred; cout flushed
        bout << "Greetings." << '\n';   // no flush
   } while (false);
   // characters transferred; cout not flushed   
}

void sync4_test() {
    do {
        osyncstream bout1(cout);
        bout1 << "Hello, ";
        {
            osyncstream(bout1.get_wrapped()) << "Goodbye, " << "Planet!" << '\n';
        }
        bout1 << "World!" << '\n';
    } while (false);
}

void th_test() {
    vector<jthread> ths;
    for (int i = 0; i < 5; ++i) {
        ths.emplace_back([i]() {
            //auto& os = cout; 
            auto&& os = osyncstream{ cout };
            os << "<" << this_thread::get_id() << " " << this_thread::get_id() << ">" << endl;
            });
    }
}

auto main() -> int {
    th_test();

    sync1_test();
    sync2_test();
    sync3_test();
    sync4_test();
    return 0;
}
/*//
// Synchronized output streams
// Header <syncstream>

template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
class basic_syncbuf : public basic_streambuf<charT, traits> {
public:
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;
    using allocator_type = Allocator; //internal buffer

    using streambuf_type = basic_streambuf<charT, traits>;

    // 31.11.2.2, construction and destruction
    basic_syncbuf() : basic_syncbuf(nullptr) {}
    explicit basic_syncbuf(streambuf_type* obuf) : basic_syncbuf(obuf, Allocator()) {}
    basic_syncbuf(streambuf_type*, const Allocator&);
    basic_syncbuf(basic_syncbuf&&);
    ~basic_syncbuf();

    // 31.11.2.3, assignment and swap
    basic_syncbuf& operator=(basic_syncbuf&&);
    void swap(basic_syncbuf&);

    // 31.11.2.4, member functions
    bool emit();
    // wrapped->sputn(internal buffer);    
    // if _Sync_recorded==true {
    //  wrapped->pubsync();
    // }
    // _Sync_recorded=false;
    // internal buffer reset

    streambuf_type* get_wrapped() const noexcept;
    allocator_type get_allocator() const noexcept;
    void set_emit_on_sync(bool) noexcept;

protected:
    // 31.11.2.5, overridden virtual functions
    int sync() override; // recoded sync set pubsync
    // Records that the wrapped stream buffer is to be flushed.
    // Then, if emit-on-sync is true, 
    //          calls emit().
    //  If emit-on-sync is false, 
    //          the actual flush is delayed until a call to emit().
    // 
    //  Returns : If emit() was called and returned false, returns - 1; otherwise 0.

private:
    streambuf_type* wrapped;    // exposition only
    bool emit_on_sync{};        // exposition only
    bool _Sync_recorded{};      // exposition only
};

template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
class basic_osyncstream : public basic_ostream<charT, traits> {
public:
    using char_type = charT;
    using int_type = traits::int_type;
    using pos_type = traits::pos_type;
    using off_type = traits::off_type;
    using traits_type = traits;

    using allocator_type = Allocator;
    using streambuf_type = basic_streambuf<charT, traits>;
    using syncbuf_type = basic_syncbuf<charT, traits, Allocator>;

    // 31.11.3.2, construction and destruction
    basic_osyncstream(streambuf_type*, const Allocator&);
    explicit basic_osyncstream(streambuf_type* obuf)
        : basic_osyncstream(obuf, Allocator()) {
    }
    basic_osyncstream(basic_ostream<charT, traits>& os, const Allocator& allocator)
        : basic_osyncstream(os.rdbuf(), allocator) {
    }
    explicit basic_osyncstream(basic_ostream<charT, traits>& os)
        : basic_osyncstream(os, Allocator()) {
    }
    basic_osyncstream(basic_osyncstream&&) noexcept;
    ~basic_osyncstream();

    // assignment
    basic_osyncstream& operator=(basic_osyncstream&&) noexcept;

    // 31.11.3.3, member functions
    void emit();
    // sb.emit();
    // stream state

    streambuf_type* get_wrapped() const noexcept;
    syncbuf_type* rdbuf() const noexcept { return const_cast<syncbuf_type*>(addressof(sb)); }

private:
    syncbuf_type sb;    // exposition only
};


// 31.7.6.5, standard basic_ostream manipulators
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
//*////