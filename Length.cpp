#include "Length.h"
#include "Data.h"


void Length::request() {
	system("cls");
	std::cout << "\n ������� ����� �������: ";
}

int Length::length() {
	Data<int> data('0', '9');
	request();
	return data.input();
}
