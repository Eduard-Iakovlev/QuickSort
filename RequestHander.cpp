#include "RequestHander.h"
#include "PoolThread.h"

RequestHander::RequestHander() {
	m_pool.start();
}

RequestHander::~RequestHander() {
	m_pool.stop();
}

void RequestHander::push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise) {
	m_pool.push_task(f, vec, left, right, promise);
}
