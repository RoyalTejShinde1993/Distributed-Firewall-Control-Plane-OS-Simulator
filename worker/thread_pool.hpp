
#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

namespace fwos {

class ThreadPool {

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mutex_;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t count);
    ~ThreadPool();

    void enqueue(std::function<void()> task);
};

}
