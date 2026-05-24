#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class TSQueue {
public:
    void push(T val) {
        std::lock_guard<std::mutex> lock(m);
        q.push(val);
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&]{ return !q.empty(); });

        T v = q.front();
        q.pop();
        return v;
    }

private:
    std::queue<T> q;
    std::mutex m;
    std::condition_variable cv;
};