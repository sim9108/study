
import std;
using namespace std;

struct A {
    using FN = A & (A&);

    A& operator>>(FN* fn) {
        return fn(*this);
    }
    A& operator<<(FN* fn) {
        return fn(*this);
    }

    void check(int a) {
        m_check = a;
        println("check:{}", m_check);
    }

    void on() { m_isOn = true; println("isOn:{}", m_isOn);  }
    void off() { m_isOn = false; println("isOn:{}", m_isOn); }

private:
    bool m_isOn{ false };
    int  m_check{};
};

namespace {
    A& _check(A& a, int const& v) {
        a.check(v);
        return a;
    }
}

template<class T>
struct _Man {
    using FN = A & (A&, T const&);
    FN* fn;
    T const v;
    _Man(FN* fn, T const& v) :fn{ fn }, v{ v } {}

    friend A& operator>>(A& a, _Man const& man) {
        return man.fn(a, man.v);
    }
    friend A& operator<<(A& a, _Man const& man) {
        return man.fn(a, man.v);
    }
};

_Man<int> check(int a) {
    return _Man<int>{&_check, a};
}

A& on(A& a) {
    a.on();
    return a;
}
A& off(A& a) {
    a.off();
    return a;
}

auto main() -> int {
    A a{};
    a >> check(3) >> check(4) >> on >> off;

    cout << setw(3);
    return 0;
}