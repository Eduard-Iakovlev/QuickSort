#pragma once
#include <vector>
using namespace std;


class Quick_sort {
public:
void swap(int& x, int& y);
void quicksort_f(vector<int>& vec, int left, int right, shared_ptr<promise<void>> promise);
void quicksort(vector<int>& vec, int left, int right);
int partition(vector<int>& vec, int left, int right);

};
