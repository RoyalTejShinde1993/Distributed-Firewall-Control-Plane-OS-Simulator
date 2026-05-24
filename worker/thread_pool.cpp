
#include "thread_pool.hpp"

using namespace fwos;

ThreadPool::ThreadPool(size_t count) {

    for(size_t i=0;i<count;i++) {

        workers.emplace_back([this]() {

            while(true) {

                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(mutex_);

                    cv.wait(lock,[this] {
                        return stop || !tasks.empty();
                    });

                    if(stop && tasks.empty())
                        return;

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
        std::lock_guard<std::mutex> lock(mutex_);
        tasks.push(task);
    }

    cv.notify_one();
}

ThreadPool::~ThreadPool() {

    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop = true;
    }

    cv.notify_all();

    for(auto& worker : workers)
        worker.join();
}
