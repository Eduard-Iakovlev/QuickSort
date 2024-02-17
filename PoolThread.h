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
	vector<thread> m_threads;
	queue<function<void(vector<int>,int, int)>> m_task_queue;
	mutex m_locker;
	condition_variable m_event_holder;
	volatile bool m_work;
public:

};
