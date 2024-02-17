#include "RequestHander.h"
#include "PoolThread.h"

//RequestHander::RequestHander() {
//	m_pool.start();
//}
//
//RequestHander::~RequestHander() {
//	m_pool.stop();
//}
//
//template<typename F, typename... Args>
//void RequestHander::push_task(F&& f, Args&&... args) {
//	m_pool.push_task(std::forward<F>(f), std::forward<Args>(args)...);
//}

//void RequestHander::push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise) {
//	m_pool.push_task(f, vec, left, right, promise);
//}
