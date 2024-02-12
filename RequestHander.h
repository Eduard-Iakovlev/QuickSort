#pragma once
#include "PoolThread.h"
class RequestHander {
public:
	RequestHander();
	~RequestHander();
	void push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise);
private:
	PoolThread m_pool;
};

