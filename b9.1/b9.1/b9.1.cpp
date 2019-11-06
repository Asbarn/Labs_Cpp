#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <vector>
#include "string"
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include "fstream"
#include <iterator>
#include <algorithm>
#include <string.h>
#include <sstream>
#include "clocale"
#include <string>
#include <vector>
#include <algorithm>
#include "iomanip"
using namespace std;
const int max = 100;
const int MAX = 100, MIN = 10, KOL = 100;

void novmas(vector<char> str)
{
	const int max = 100;
	int i = 0, c, d = 0, dd = 0, j = 0, q = 0;
	int b = 0; int k = 0, e = 0;
	
	vector<vector<char>> newtext;
	vector<char>test;
	
	str.push_back(0);
	

	for (; k < str.size()-1 ;)
	{
		for (; k < str.size()-1  && str[k] != ' ' && str[k] != '.' && str[k] != ',' && str[k] != ':' && str[k] != ';' && str[k] != '?' && str[k] != '!' && str[k] != '-' && str[k] != '(' && str[k] != ')';)
		{
			test.push_back(str.at(k));
			k++;
		}


		int eee = k - e;
		for (d = dd; e < k; d++, e++)	q++;
		
		newtext.push_back(test);
		b++;
		test.clear();
		q = 0;
		e = k;

		while (str[e] == ' ')
		{
			e++;
		}
		dd = d + e - k;


		e = k;
		int ee = k;
		while (e < str.size()  && str[e] == ' ' || str[e] == '.' || str[e] == ',' || str[e] == ':' || str[e] == ';' || str[e] == '?' || str[e] == '!' || str[e] == '-' || str[e] == '(' || str[e] == ')')
		{
			e++;
		}
		k = e;


	}
	
	

	for (i = 0; i < b - 1; i++)
		for (j = i + 1; j < b; j++)
			if ( newtext[i] > newtext[j])
			{
				newtext[j].swap(newtext[i]);
				
			}
	std::cout << "Results:\n";
	
	for (std::vector<std::vector<char>>::size_type i = 0; i < newtext.size(); i++)
	{
		for (std::vector<char>::size_type j = 0; j < newtext[i].size(); j++)
		{
			std::cout << newtext[i][j];
		}
		std::cout << " ";
	}
	
}

bool acompare(const int &lhs, const  int &rhs) { return lhs > rhs; };
int f(int i, int j, int n)

{

	return (i * n + j);

}
vector<int> proiz(vector<int>  a, vector<int> b, int n)
{
	vector<int > c(n*n);
	for (size_t i = 0; i < n; i++)
	{

		for (size_t j = 0; j < n; j++)
		{
			c.at(f(i, j, n)) = 0;
			for (int k = 0; k < n; k++)
				c.at(f(i, j, n)) += a.at(f(i, j, n)) * b.at(f(i, j, n));
		}
	}

	return(c);
}
vector<int> sum(vector<int>  a, vector<int> b, int n)

{
	vector<int > c(n*n);


	for (size_t i = 0; i < n; i++)
	{

		for (size_t j = 0; j < n; j++)
		{
			c.at(f(i, j, n)) = a.at(f(i, j, n)) + b.at(f(i, j, n));
		}
	}

	return (c);

}

void create(ofstream &outfile, int n)

{

	for (int i = 1; i <= n; i++)

	{

		int v = rand() % KOL;

		outfile << v << endl;

	}

}
vector<int> createorig3(ifstream &infile, int& i, int n)

{
	int v;
	infile >> v;
	int   t = 0, j = 0; vector<int>A(KOL); for (size_t i = 0; i < KOL; i++)A.at(i) = 0;
	while (!infile.eof())

	{
		A.at(v)++;
		infile >> v;
	}


	for (int i = 0; i < KOL; i++) {
		if (A.at(i) > 1)j++;
	}
	vector<int>C(j);

	for (size_t i = 0; i < KOL; i++) {
		if (A.at(i) > 1) {
			C.at(t) = i; t++;
		}
	}
	sort(C.begin(), C.end(), greater<int>());
	i = j;
	return C;
}
void read_file(ifstream &infile)

{
	int v;
	infile >> v;
	while (!infile.fail())
	{
		std::cout << v << " ";
		infile >> v;
	}
	std::cout << endl;
}

int main()

{
	setlocale(LC_ALL, ""); srand(time(NULL));
	int choose = 0; std::string stroka; std::cout << "Введите номер задания: "; cin >> choose; cin.get();
	switch (choose)
	{
	case 1:
	{
		std::cout << "Введите строку: ";
		std::getline(std::cin, stroka); vector<char>text(stroka.begin(), stroka.end());

		novmas(text);

		//break;
	}
	break;
	case 2:
	{
		int *a, *b, n;

		std::cout << "Введите n: "; cin >> n;

		vector<int>A(n*n), B(n*n);
		std::cout << "Массив А:" << endl;
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				A.at(f(i, j, n)) = (rand() % 10);
		for (size_t i = 0; i < n; i++)

		{
			for (size_t j = 0; j < n; j++)
				std::cout << setw(5) << A.at(f(i, j, n));
			std::cout << endl;
		}

		std::cout << "Массив B:" << endl;
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				B.at(f(i, j, n)) = (rand() % 10);
		for (size_t i = 0; i < n; i++)

		{
			for (size_t j = 0; j < n; j++)
				std::cout << setw(5) << B.at(f(i, j, n));
			std::cout << endl;
		}

		vector<int>c(n*n);
		c = sum(proiz(A, B, n), proiz(B, A, n), n);
		std::cout << "Массив C=A*B+B*C:" << endl;
		for (size_t i = 0; i < n; i++)

		{
			for (size_t j = 0; j < n; j++)
				std::cout << setw(5) << c.at(f(i, j, n));
			std::cout << endl;
		}


	}


	break;
	case 3:

	{
		int n = rand() % (MAX - MIN + 1) + MIN;
		std::cout << "Первоначальный массив:";
		ofstream outfile("file.txt");
		if (!outfile)

		{
			std::cout << "error1" << endl;

			return 1;

		}
		create(outfile, n);
		outfile.flush();
		ifstream infile("file.txt");
		if (!infile)
		{
			std::cout << "error2" << endl;
			return 2;
		}
		read_file(infile);
		infile.close();
		infile.clear();
		infile.open("file.txt");
		if (!infile)
		{
			std::cout << "error4" << endl;
			return 4;
		}
		int i = 0;
		vector<int> b;
		b = createorig3(infile, i, n);
		infile.close();
		infile.clear();
		std::cout << "Массив по убыванию из повторяющихся символов: " << endl;
		for (size_t k = 0; k < i; k++)std::cout << b.at(k) << " ";





	}

	break;

	default:

		std::cout << "Неправильный выбор!";
		break;
	}
	 
	return 0;
}

