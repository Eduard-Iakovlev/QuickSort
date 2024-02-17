#include "Array.h"
#include "Length.h"
#include "Data.h"
#include "QuickSort.h"


Array::Array(){
    Length length;
    _length = length.length();

    for (int i = 0; i < _length; i++)
        _arr.push_back(rand() % (_end - _start + 1) + _start);
}

Array::~Array() {
    _arr.clear();
}

void Array::print() {
    for (int i = 0; i < _arr.size(); i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

void Array::print_begin() {
    std::cout << "\n �������� ������: \n";
}

void Array::print_end() {
    std::cout << " ��������������� ������: \n";
}

void Array::sort_arr() {
    QuickSort sort;
    sort.quicksort(_arr, 0, _arr.size() - 1);
}

int Array::menu() {
    Data<int> data('1', '2');
    while (true) {
        std::cout << "\n �������� ��������:\n";
        std::cout << " 1 - �����\n";
        std::cout << " 2 - ������� ������ ����� �������\n -> ";
        _menu = data.input();
        if (_menu > 2) {
            system("cls");
            data.clear();
            std::cout << " �� ������ ����\n ������� ����� ��������������� ��������:\n";
            continue;
        }
        else break;
    }
    return _menu;
}

