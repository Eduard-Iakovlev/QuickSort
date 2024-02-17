#pragma once
#include "PoolThread.h"
class RequestHander {
public:
	RequestHander();
	~RequestHander();
	//void push_task(FuncType f, vector<int> vec, int left, int right, shared_ptr<promise<void>> promise);
//	template<typename F, typename... Args>
//	void push_task(F&& f, Args&&... args);
//private:
//	PoolThread m_pool;
};

