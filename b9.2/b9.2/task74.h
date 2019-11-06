#pragma once
#include "pch.h"
#include "iostream"
#include  "vector"
#include "list"


using namespace std;

void print(vector<int> a, vector<int>aa) {
	int i = 0;
	do {
		if (a[i] != 0)cout << a[i] << ' ';
		i = aa[i];
	} while (i > 0);
	cout << endl;
}

void add(vector<int>&a, vector<int>&aa, int n, int key) {


	if (aa.at(0) != 1) {
		a[0] = key; aa[0] = 1;
	}
	else {
		int k = 1; int i = 0; while (aa.at(i) == k)
		{
			k++; i++;
		}

		aa[i] = (i + 1); a[i] = key; if (i + 1 == n)aa[i] = 0;
	}

}



bool find_equal(vector<int> &a, vector<int>&aa, int key, int n) {
	int i = 0;
	do {
		if (a[i] == key) {
			return true;
		}
		i = aa[i];
	} while (i);
	return false;
}
bool find_equal(list<int>a, int key) {
	for (list<int>::iterator p = a.begin(); p != a.end(); ++p)
	{
		if (*p == key) {
			return true;
		}
	}
	return false;
}


void solution(vector<int>&c, vector<int>&cc, vector<int>&a, vector<int>&aa, vector<int>&b, vector<int>&bb, int n) {
	int i = 0; do {

		if (!find_equal(b, bb, a[i], n) && !find_equal(c, cc, a[i], n)) {
			add(c, cc, n, a[i]);
		}
		i = aa[i];
	} while (i > 0);

}
void solution(list<int>&c, list<int>&a, list<int>&b) {
	for (list<int>::iterator p = a.begin(); p != a.end(); ++p) 
	{
		
		if (!find_equal(b, *p) /*&& !find_equal(c, cc, a[i], n)*/)
		{
			c.push_back(*p);
		}
	}

}





void task74()
{
	setlocale(LC_ALL, "rus");

	int n, m;

	cout << "¬ведите количество элементов списка L1: "; cin >> n;
	vector<int>A(n); vector<int>nextA(n);


	cout << "¬ведите сами элементы: ";
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp; add(A, nextA, n, tmp);

	}

	cout << "¬ведите количество элементов списка L2: "; cin >> m;

	vector<int>B(m); vector<int>nextB(m);
	cout << "¬ведите сами элементы: ";
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		add(B, nextB, m, tmp);

	}
	cout << endl;



	vector<int>C(n + m); vector<int>nextC(n + m);
	solution(C, nextC, A, nextA, B, nextB, n + m);
	solution(C, nextC, B, nextB, A, nextA, n + m);
	cout << " ћассив из неповтор€ющихс€ чисел: ";
	print(C, nextC);

}


void task74v()
{
	setlocale(LC_ALL, "rus");

	int n, m; list<int>a; list<int>b;

	cout << "¬ведите количество элементов списка L1: "; (cin >> n).get();

	cout << "¬ведите сами элементы: ";
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}



	cout << "¬ведите количество элементов списка L2: "; (cin >> m).get();

	cout << "¬ведите сами элементы: ";
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	cout << endl;
	

	list<int>c;
	solution(c,a,b);
	solution(c,b,a);
	cout << " ћассив из неповтор€ющихс€ чисел: ";
	
	for (list<int>::iterator p = c.begin(); p != c.end(); ++p)cout << *p; cout << endl;

}
