#include "PoolThread.h"
#include <future>

void PoolThread::start() {
    m_work = true;
    for (int i = 0; i < 4; i++) {
        m_threads.push_back(std::thread(&PoolThread::threadFunc, this));
    }
}

void PoolThread::stop() {
    m_work = false;
    m_event_holder.notify_all();
    for (auto& t : m_threads) t.join();
}


void PoolThread::threadFunc() {
    while (true) {
        std::function<void()> task_to_do;
        {
            std::unique_lock<std::mutex> l(m_locker);
            if (m_task_queue.empty() && !m_work)
                return;
            if (m_task_queue.empty()) {
                m_event_holder.wait(l, [&]() {return !m_task_queue.empty() || !m_work; });
            }
            if (!m_task_queue.empty()) {
                task_to_do = m_task_queue.front();
                m_task_queue.pop();
            }
        }
        if (task_to_do) task_to_do();
    }
}
