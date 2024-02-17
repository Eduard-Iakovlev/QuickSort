#pragma once
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <future>

using namespace std;


class PoolThread {
public:
    PoolThread() = default;
    void start();
    void stop();
    template<typename F, typename... Args>
    void push_task(F&& f, Args&&... args);
    void threadFunc();

private:
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_task_queue;
    std::mutex m_locker;
    std::condition_variable m_event_holder;
    volatile bool m_work;
};

template<typename F, typename... Args>
void PoolThread::push_task(F&& f, Args&&... args) {
    {
        std::lock_guard<std::mutex> l(m_locker);
        m_task_queue.push(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    }
    m_event_holder.notify_one();
}