#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
public:
    ThreadPool(int n);
    void enqueue(std::function<void()> job);
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> jobs;
    std::mutex mtx;
    std::condition_variable cv;
    bool running = true;
};