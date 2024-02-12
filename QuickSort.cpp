#include "quicksort.h"
#include <thread>
#include <future>
#include <algorithm>
#include "PoolThread.h"
#include "RequestHander.h"

void Quick_sort::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void Quick_sort::quicksort_f(vector<int>& vec, int left, int right, shared_ptr<promise<void>> promise){
    future<void> f = async(launch::async, [&]() {
        quicksort(vec, left, right);
        });
    f.wait();
    promise->set_value();
}

void Quick_sort::quicksort(vector<int>& vec, int left, int right){

    if (left >= right) return;
    RequestHander rh;
    auto promise = std::make_shared<std::promise<void>>();
    future<void> future = promise->get_future();
    int pi = partition(vec, left, right); 
    if (pi - left > 100000){
        rh.push_task(quicksort_f, vec, left, pi - 1, promise);
        quicksort(vec, pi + 1, right);
    }
    else {
        quicksort(vec, left, pi - 1);
        quicksort(vec, pi + 1, right);
    }
}

int Quick_sort::partition(vector<int>& vec, int left, int right){

    int pivot = vec[right];   
    int i = (left - 1); 
    for (int j = left; j <= right - 1; j++)
    {
        if (vec[j] <= pivot){

            i++;    
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right]);
    return (i + 1);
    return 0;
}
