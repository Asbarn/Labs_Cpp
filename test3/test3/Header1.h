#pragma once
#include "Header.h"

using namespace std;

template<unsigned int size>
bool numb<size>::overfl(unsigned int n1, unsigned int n2) {
	unsigned long long res = n1 + n2;
	if (res > ULONG_MAX) return true;
	return false;
}

template<unsigned int size>
void numb<size>::razrAdd(int i, unsigned long n) {
	if (overfl(razr[i], n)) {
		razr[i] = razr[i] + n - ULONG_MAX - 1;
		if (i + 1 < size) razrAdd(i + 1, 1);
	}
	else razr[i] += n;
}

template<unsigned int size>
void numb<size>::norm(short* arr, int N) {
	for (int i = 0; i < N; i++) {
		if (arr[i] > 9) {
			if (i + 1 < N) arr[i + 1] += arr[i] / 10;
			arr[i] = arr[i] % 10;
		}
	}
}

template<unsigned int size>
bool numb<size>::operator<(numb n) {
	for (int i = size - 1; i >= 0; i--) {
		if (razr[i] < n.razr[i]) return true;
	}
	return false;
}

template<unsigned int size>
bool numb<size>::operator>(numb n) {
	for (int i = size - 1; i >= 0; i--) {
		if (razr[i] > n.razr[i]) return true;
	}
	return false;
}

template<unsigned int size>
bool numb<size>::operator==(numb n) {
	for (int i = size - 1; i >= 0; i--) {
		if (razr[i] != n.razr[i]) return false;
	}
	return true;
}

template<unsigned int size>
numb<size>& numb<size>::operator=(numb<size> n) {
	for (int i = 0; i < size; i++) {
		razr[i] = n.razr[i];
	}
	return *this;
}

template<unsigned int size>
numb<size> numb<size>::operator+(numb<size> n) {
	numb<size> res;
	for (int i = 0; i < size; i++) {
		if (!overfl(razr[i], n.razr[i])) {
			res.razrAdd(i, razr[i] + n.razr[i]);
		}
		else {
			if (i + 1 < size) res.razrAdd(i + 1, 1);
			res.razrAdd(i, razr[i] + n.razr[i] - ULONG_MAX - 1);
		}
	}
	return res;
}

template<unsigned int size>
numb<size> numb<size>::operator<<(int n) {
	for (int i = size - 1; i - n >= 0; i--) {
		razr[i] = razr[i - n];
	}
	for (int i = 0; i < n && i < size; i++) {
		razr[i] = 0;
	}
	return *this;
}

template<unsigned int size>
ostream & operator<<(ostream & out, const numb<size> & n) {
	for (int i = size - 1; i >= 0; i--) {
		out << n.razr[i] << " ";
	}
	return out;
}

template<unsigned int size>
numb<size> numb<size>::operator*(unsigned int n) {
	numb<size> res;
	for (int i = 0; i < size; i++) {
		unsigned long long tmp = static_cast<unsigned long long>(razr[i]) * n;
		if (tmp <= ULONG_MAX) {
			res.razrAdd(i, (unsigned int)tmp);
		}
		else {
			unsigned int ost = tmp % (static_cast<unsigned long long>(ULONG_MAX) + 1);
			res.razr[i] += ost;
			if (i + 1 < size) {
				unsigned int d = static_cast<unsigned int>(tmp / (static_cast<unsigned long long>(ULONG_MAX) + 1));
				res.razrAdd(i + 1, d);
			}
		}
	}
	return res;
}

template<unsigned int size>
numb<size> numb<size>::operator*(numb<size> n) {
	numb<size> res;
	for (int i = 0; i < size; i++) {
		numb<size> tmp = *this * n[i];
		res += tmp << i;
	}
	return res;
}

template<unsigned int size>
numb<size> numb<size>::operator*=(numb<size> n) {
	*this = *this * n;
	return *this;
}

template<unsigned int size>
numb<size> numb<size>::operator+=(numb<size> n) {
	*this = *this + n;
	return *this;
}

template<unsigned int size>
unsigned int& numb<size>::operator[](const int i) {
	return razr[i];
}

template<unsigned int size>
void numb<size>::print() {
	for (int i = size - 1; i >= 0; i--) {
		cout << razr[i] << " ";
	}
	cout << endl;
}

template<unsigned int size>
string numb<size>::dec_str() {
	int N = 1000;
	short* dec = new short[N];
	short* dec2 = new short[N];
	for (int i = 0; i < N; i++) dec2[i] = 0;

	for (int curRazr = 0; curRazr < size; curRazr++) {
		for (int i = 0; i < N; i++) dec[i] = 0;
		unsigned int n = razr[curRazr];
		int i = 0;
		while (n) {
			dec[i] = n % 10;
			n /= 10;
			i++;
		}
		int curRazr32 = curRazr * 32;
		for (int j = 0; j < curRazr32; j++) {
			for (int i = 0; i < N; i++) {
				dec[i] *= 2;
			}
			norm(dec, N);
		}
		for (int i = 0; i < N; i++) {
			dec2[i] += dec[i];
		}
		norm(dec2, N);
	}
	string res;
	int N2;
	for (N2 = N - 1; N2 >= 0 && !dec2[N2]; N2--);
	for (int i = N2; i >= 0; i--) res += '0' + dec2[i];
	delete[] dec;
	delete[] dec2;
	return res;
}
