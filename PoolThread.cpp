#include "PoolThread.h"
#include <future>

void PoolThread::start() {
	m_work = true;
	for (int i = 0; i < 4; i++) {
		m_threads.push_back(thread(&PoolThread::threadFunc, this));
	}
}

void PoolThread::stop() {
	m_work = false;
	m_event_holder.notify_all();
	for (auto& t : m_threads) t.join();
}

void PoolThread::push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise) {
	lock_guard<mutex> l(m_locker);
	function<void(vector<int>, int, int)> new_task = [&promise, &f](vector<int> vec, int left, int right) {f(vec, left, right, promise); };
	m_task_queue.push(new_task);
	m_event_holder.notify_one();
}
void PoolThread::threadFunc() {
	while (true) {
		function<void(vector<int>, int, int)> task_to_do;
		{
			unique_lock<mutex> l(m_locker);
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
		if (task_to_do)	task_to_do;
	}
}
