#pragma once
#include "PoolThread.h"

class RequestHandler {
public:
    RequestHandler();
    ~RequestHandler();
    template<typename F, typename... Args>
    void push_task(F&& f, Args&&... args);

private:
    PoolThread m_pool;
};

