#pragma once
#include "pch.h"
#include "iostream"
#include  "vector"
#include "list"


using namespace std;

void print(vector<int> a, vector<int>nexta, vector<int>preva)
{
	int i = 0;
	do {
		cout << a[i] << ' ';
		i = nexta[i];
	} while (i > 0);
	cout << endl;
}


void add(vector<int>& a, vector<int>&nexta, vector<int>&preva, int key, int n) {

	if (nexta[0] != 1) {
		preva[0] = 0; nexta[0] = 1; a[0] = key;
	}
	else {
		int k = 1; int i = 0; while (nexta[i] == k)
		{
			k++; i++;
		}
		preva[i] = i - 1;
		nexta[i] = i + 1; a[i] = key; if (i + 1 == n)nexta[i] = 0;
	}
}





void task76()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите кол-во чисел: "; cin >> n;
	vector<int>a(2 * n); vector<int>nexta(2 * n); vector<int>preva(2 * n);
	cout << "введите " << 2 * n << " чисел: ";
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		add(a, nexta, preva, x, 2 * n);
	}
	cout << endl << "ѕервоначальный список: ";
	print(a, nexta, preva); cout << endl;
	int ans = 0;
	int i = 0, j = 2 * n - 1;
	do {
		ans += a[i] * a[j];
		i = nexta[i];
		j = preva[j];
	} while (i < j);

	cout << endl << "Result:" << ans << endl;

}


void task76v()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите кол-во чисел: "; cin >> n;
	list<int>a;
	cout << "введите " << 2 * n << " чисел: ";
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << endl << "ѕервоначальный список: ";
	for (list<int>::iterator p = a.begin(); p != a.end(); ++p)
		cout << *p; cout << endl;
	int ans = 0;
	int i = 0, j = 2 * n - 1; list<int>::const_reverse_iterator pp = a.rbegin(); list<int>::iterator p = a.begin();
	for (; *p<*pp; ++p,++pp) ans += (*p)*(*pp);
		
	cout << endl << "Result:" << ans << endl;

}