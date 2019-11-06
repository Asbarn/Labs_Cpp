#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <conio.h>
#include <stack>
#include "cstdio"
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int imp(char v) {
	switch (v) {
	case '(': return 1;
	case '+':return 2;
	case '-': return 2;
	case '*':return 3;
	case '/': return 3;
	}
}
bool oper(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
bool oper(double c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
bool numb(char c) {
	return c != '+' && c != '-' &&c != '*' &&c != '/';
}
bool numb(double c) {
	return c != '+' && c != '-' &&c != '*' &&c != '/';
}
void polchar(char *a, char *out) {
	stack <char> S;
	int i = 0, j = 0,t=0,l=0;
	
	while (a[i] != '\0') {
		if (numb(a[i]) )
		{
			out[j] = a[i];
			j++;


		}
		
		else if (oper(a[i]))
		{
			
			if (S.empty() || imp(S.top()) < imp(a[i]))
			{
				S.push(a[i]);
			}
			else
			{
				while (!S.empty() && (imp(S.top()) >= imp(a[i])))
				{
					out[j++] = S.top();
					S.pop();
				}
				S.push(a[i]);
			}
		}
		
		i++;
	}
	

	





	while (!S.empty()) {
		if (S.top() == '(') {
			cout << "Input error!";
			_getch(); exit(1);
		}
		else {
			out[j] = S.top();
			S.pop();
			j++;

		}
	}
}
double sol(char *out) {
	int j = 0; char ccc[1];
	stack <double> S; double cc=0, r1=0, r2=0;
	
	while (j < strlen(out))
	{

		if (numb(out[j]))
		{
			 ccc[0] = out[j];  cc = atof(ccc); S.push(cc);
		}
		else if (oper(out[j]))
		{
			r1 = S.top(); S.pop();
			r2 = S.top(); S.pop();

			switch (out[j])
			{
			case '+': S.push(r2 + r1); break;
			case '-': S.push(r2 - r1); break;
			case '*': S.push(r2*r1); break;
			case '/': S.push(r2 / r1); break;
			}
		}
		j++;
	}
	return (S.top());
}

void main() {
	setlocale(LC_ALL, "rus");
	char a[100] = {0};
	char out[100] = {0};

	cout << "Введите пример: "; gets_s(a);polchar(a, out); 
	cout << "Пример на польской записи: " << out << endl;
	cout << "Ответ: " << sol(out);

}