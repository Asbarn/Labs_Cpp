#include "pch.h"
#include "Header.h"
#include "iostream"
int main() 
{
	numb<10> n = 1;
	for (int i = 1; i <= 10; i++) n *= i;
	cout << n << endl << endl << n.dec_str().c_str() << endl;
}