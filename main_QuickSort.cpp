#include <iostream>
#include "Array.h"
#include "Windows.h"
#include <ctime>


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (true) {
        Array* array = new Array;
        array->print_begin();
        array->print();
        int start = clock();
        array->sort_arr();
        int end = clock();
        printf("Time taken: %.5fs\n", (double)(clock() - start) / CLOCKS_PER_SEC);

        array->print_end();
        array->print();
        if (array->menu() == 1) break;
        delete array;
    }
}
