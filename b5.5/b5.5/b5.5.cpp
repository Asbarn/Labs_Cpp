// b5.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iomanip> 
#include <stdlib.h> 
#include <time.h> 
#include <LIMITS.H> 
#include <iostream>
#include "clocale"
#include "cmath"
using namespace std;
const float pi = 3.14;
const float exp = 2.7;
float s, ds = 0.1;
void kor(float,float, float a, float b);
void main()
{
	setlocale(LC_ALL, "");
	float x0, xn, x;
	float Fa = pow((x0 + 3), 3) - 8; float fa = 3 * x0*x0 + 18 * x0 + 27;
	float Fb = cos(pi*x0) - pow(x,s); float fb = pi * sin(pi*x0) - 5 * x0*x0*x0*x0;
	int a; cout << "Введите номер функции:"; cin >> a;
	if (a = 1) { float a = -2; float b = 1; kor(Fa, fa, a, b); }
	else if (a = 2) { float a = 0, b = 2;kor(Fb,fb,a,b) }
	else cout << "Неправильный выбор";
}
void kor(float F,float f, float a, float b)
{
	int chtonib = 0;
	float x0 = b, xn , t;
	for (;abs(F)<exp && x0>a;)
	{
		xn = x0 - (F) / (f);
		//t = x0;
		x0 = xn;
	}

}

