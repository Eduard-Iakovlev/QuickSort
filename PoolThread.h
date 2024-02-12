#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <future>

using namespace std;

typedef function<void()> task_type;
typedef void (*FuncType) (vector<int>, int, int, shared_ptr<promise<void>>);

class PoolThread {
public:
	PoolThread() = default;
	void start();
	void stop();
	void push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise);
	void threadFunc();
private:
	vector<thread> m_threads;
	queue<function<void(vector<int>,int, int)>> m_task_queue;
	mutex m_locker;
	condition_variable m_event_holder;
	volatile bool m_work;
};
