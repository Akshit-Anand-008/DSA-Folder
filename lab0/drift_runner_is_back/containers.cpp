#include "containers.h"
using namespace std;

void measure_vector(const std::vector<unsigned>& sizes, unsigned repeat, ResultMap& results) {
    for (unsigned n : sizes) {
        Result r{0.0, 0.0, -1.0};
        for (unsigned t = 0; t < repeat; t++) {
            std::vector<int> v;

            auto start_time = std::chrono::steady_clock::now();
            for (int i = 1; i <= n; i++) { v.push_back(i); }
            auto duration = std::chrono::steady_clock::now() - start_time;
            long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.insert_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 1; i <= n; i++) { auto it = find(v.begin(), v.end(), i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_std_us += time_taken;
        }
        r.insert_us /= repeat;
        r.find_std_us /= repeat;
        results[n] = r;
    }
}

void measure_list(const std::vector<unsigned>& sizes, unsigned repeat, ResultMap& results) {
    Result r{0, 0, -1};
    for (unsigned n : sizes) {
        for (int i = 0; i < repeat; i++) {
            list<int> l;

            auto start_time = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++) { l.push_back(i); }
            auto duration = std::chrono::steady_clock::now() - start_time;
            long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.insert_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 1; i <= n; i++) { auto it = find(l.begin(), l.end(), i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_std_us += time_taken;
        }

        r.insert_us /= repeat;
        r.find_std_us /= repeat;
        results[n] = r;
    }
}

void measure_set(const std::vector<unsigned>& sizes, unsigned repeat, ResultMap& results) {
    Result r{0, 0, 0};
    for (unsigned n : sizes) {
        for (int i = 0; i < repeat; i++) {
            set<int> s;

            auto start_time = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++) { s.insert(i); }
            auto duration = std::chrono::steady_clock::now() - start_time;
            long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.insert_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 1; i <= n; i++) { auto it = find(s.begin(), s.end(), i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_std_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++) { auto it = s.find(i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_member_us += time_taken;
        }

        r.insert_us /= repeat;
        r.find_std_us /= repeat;
        r.find_member_us /= repeat;
        results[n] = r;
    }
}

void measure_unordered_set(const std::vector<unsigned>& sizes, unsigned repeat, ResultMap& results) {
    Result r{0, 0, 0};
    for (unsigned n : sizes) {
        for (int i = 0; i < repeat; i++) {
            unordered_set<int> s;

            auto start_time = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++) { s.insert(i); }
            auto duration = std::chrono::steady_clock::now() - start_time;
            long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.insert_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 1; i <= n; i++) { auto it = find(s.begin(), s.end(), i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_std_us += time_taken;

            start_time = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++) { auto it = s.find(i); }
            duration = std::chrono::steady_clock::now() - start_time;
            time_taken = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            r.find_member_us += time_taken;
        }

        r.insert_us /= repeat;
        r.find_std_us /= repeat;
        r.find_member_us /= repeat;
        results[n] = r;
    }
}
