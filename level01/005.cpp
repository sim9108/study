import std;
using namespace std;

struct A {
    timed_mutex mtx{};

    void run() {
        if (unique_lock lk{ mtx,defer_lock }; lk.try_lock_for(10ms)) {
            println("I have try and modify:{}", this_thread::get_id());
        }
    }
};

auto main() -> int {
    do {
        for (vector v = { 1, 2, 3, 4, 5 }; auto x : v) {
            println("{}", x);
        }
    } while (false);

    do {
        A a{};
        vector<jthread> ths{};
        for (auto i = 0uz; i < 5uz; ++i) {
            ths.emplace_back(&A::run, &a);
        }
        this_thread::sleep_for(1s);
    } while (false);

    return 0;
}