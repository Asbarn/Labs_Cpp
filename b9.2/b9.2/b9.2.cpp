#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream> // for cin cout
#include "stdlib.h"
#include "clocale"
#include <string>
#include "vector"
#include "task73.h"
#include "task74.h"
#include "task76.h"
using namespace std;


int main() {

	setlocale(LC_ALL, "");
	int choose, choose2; cout << "Введите номер задания(1,2 или 3): " << endl; cin >> choose;
	switch (choose)
	{
	case 1:
	{
		cout << "Введите способ решения(1-vector,2-list)"; cin >> choose2;
		if (choose2 == 1)
			task73();
		else if (choose2 == 2)
			task73v();
		else cout << "Неправильный выбор!" << endl;


	}
	break;
	case 2:
	{
		cout << "Введите способ решения(1-vector,2-list)"; cin >> choose2;
		if (choose2 == 1)
			task74();
		else if (choose2 == 2)
			task74v();
		else cout << "Неправильный выбор!" << endl;






	}
	break;

	case 3:
	{

		cout << "Введите способ решения(1-vector,2-list)"; cin >> choose2;
		if (choose2 == 1)
			task76();
		else if (choose2 == 2)
			task76v();
		else cout << "Неправильный выбор!" << endl;

	}
	break;
	default:
	{
		cout << "Неправильный выбор!" << endl;

	}





	}

	system("pause");
	return 0;
}

