#include "thread_pool.h"

ThreadPool::ThreadPool(int n) {
    for (int i = 0; i < n; i++) {
        workers.emplace_back([this] {
            while (true) {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock, [&] {
                        return !tasks.empty() || !running;
                    });

                    if (!running && tasks.empty()) return;

                    task = tasks.front();
                    tasks.pop();
                }

                task();
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        tasks.push(task);
    }
    cv.notify_one();
}

void ThreadPool::stop() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        running = false;
    }
    cv.notify_all();

    for (auto& w : workers)
        w.join();
}