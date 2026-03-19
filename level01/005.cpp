import std;
using namespace std;

struct A {
    set<thread::id> ids{};
    timed_mutex mtx{};

    void run() {
        auto id = this_thread::get_id();
        if (unique_lock lk{ mtx,defer_lock }; lk.try_lock_for(10ms)) {
            if (auto [it, inserted] = ids.insert(id); inserted) {
                println("successfully insertion:{}", id);
            }
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