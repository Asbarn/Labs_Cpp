#pragma once
#include <climits>
#include <iostream>
#include <iomanip>
using namespace std;
const int max = 1000000000;

template<unsigned int size>
class numb {
	unsigned int* razr = new unsigned int[size];

	bool overfl(unsigned int n1, unsigned int n2);
	void razrAdd(int i, unsigned long n);
	void norm(short* arr, int N);
public:
	numb() {
		for (int i = 0; i < size; i++) {
			razr[i] = 0;
		}
	}
	numb(const unsigned int n) {
		razr[0] = n;
		for (int i = 1; i < size; i++) {
			razr[i] = 0;
		}
	}
	numb(const unsigned int* n) {
		int N = sizeof(n);
		for (int i = 0, j = N - 1; i < size && i < N; i++, j--) {
			razr[i] = n[j];
		}
		for (int i = N; i < size; i++) razr[i] = 0;
	}
	numb(const numb& n) {
		for (int i = 0; i < size; i++) {
			razr[i] = n.razr[i];
		}
	}
	~numb() {
		delete[] razr;
	}
	bool operator<(numb n);
	bool operator>(numb n);
	bool operator==(numb n);
	numb& operator=(numb n);
	numb operator+(numb n);
	numb operator<<(int n);
	friend ostream& operator<<(ostream& out, const numb& n) {
		for (int i = size - 1; i >= 0; i--) {
			out << n.razr[i] << " ";
		}
		return out;
	}
	numb operator*(unsigned int n);
	numb operator*(numb n);
	numb operator*=(numb n);
	numb operator+=(numb n);
	unsigned int& operator[](const int i);
	void print();
	string dec_str();
};
#include "Header1.h"