import std;
using namespace std;

struct A {
    set<int> values{};
    timed_mutex mtx{};

    bool exist(int v) const { return values.contains(v); }

    void run(int v) {
        auto id = this_thread::get_id();
        if (unique_lock lk{ mtx,defer_lock }; lk.try_lock_for(1ms)) {
            if (auto [it, inserted] = values.insert(v); inserted) {
                println("thread id:{} inserted:'{}'", id, v);
            }
            else {
                println("thread id:{} fail:'{}'", id, v);
            }
        }
    }
};

auto main() -> int {
    do {
        for (vector v = { 1, 2, 3 }; auto x : v) {
            println("{}", x);
        }
    } while (false);

    do {
        A a{};
        vector<jthread> ths{};
        for (auto i = 0uz; i < 3uz; ++i) {
            ths.emplace_back(&A::run, &a, i % 2);
        }
        this_thread::sleep_for(1s);
    } while (false);

    return 0;
}