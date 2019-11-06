#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "iostream"
#include "string"
#include <string>
#include"stdlib.h"
#include "clocale"
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <conio.h>
#include <stack>
#include "cstdio"
#include "stdio.h"
#include "list"
#include "vector"
using namespace std;

struct Student {
	string surname;
	string name;
	string secondName;
	int age;
	string sex;
	int course;
	double averageScore;
	
	bool operator ==(const Student& st)
	{
		return surname == st.surname &&
			name == st.name &&
			secondName == st.secondName &&
			age == st.age &&
			sex == st.sex &&
			course == st.course &&
			averageScore == st.averageScore;
	}
};

struct Node {
	Student data;
	Node* next;
};

void add(Node*&, Student);
bool comp(Student, Student);
void _print(Node*);
void _print(Student);
void _scan(Student&);
void _delete(Node*&, Student);
bool cmp(Student, Student);

bool comp(Student a, Student b) {
	if (a.surname > b.surname) {
		return true;
	}
	if (a.surname < b.surname) {
		return false;
	}
	if (a.name > b.name) {
		return true;
	}
	if (a.name < b.name) {
		return false;
	}
	if (a.secondName > b.secondName) {
		return true;
	}
	else {
		return false;
	}
}


void add(Node* &top, Student key) {
	Node *nv = new Node;
	nv->data = key;
	nv->next = NULL;
	if (!top) {
		top = nv;
	}
	else {
		if (comp(top->data, nv->data)) {
			nv->next = top;
			top = nv;
		}
		else {
			Node *p = top;
			Node *pv = p;
			while (p) {
				pv = p;
				if (!comp(p->data, nv->data)) {
					break;
				}
				p = p->next;
			}
			nv->next = pv->next;
			pv->next = nv;
		}
	}
}

void _print(Node* top) {
	while (top) {
		_print(top->data);
		top = top->next;
	}
}

void _print(Student a) {
	cout << a.surname << ' ' << a.name << ' ' << a.secondName << ' ' << a.age << ' ' << a.sex << ' '
		<< a.course << ' ' << a.averageScore << endl;
}

void _scan(Student &a) {
	cout << "Фамилия: "; cin>>a.surname;
	cout << "Имя: "; cin >> a.name;;
	cout << "Отчество: "; cin>>a.secondName;
	cout << "Возраст: "; cin >> a.age;
	cout << "Пол: "; cin>>a.sex;
	cout << "Курс: "; cin >> a.course;
	cout << "Средний балл: "; cin >> a.averageScore;
}

bool cmp(Student a, Student b) {
	if (a.surname != b.surname) {
		return false;
	}
	if (a.name != b.name) {
		return false;
	}
	if (a.secondName != b.secondName) {
		return false;
	}
	if (a.age != b.age) {
		return false;
	}
	if (a.sex != b.sex) {
		return false;
	}
	if (a.course != b.course) {
		return false;
	}
	if (a.averageScore != b.averageScore) {
		return false;
	}
	return true;
}

void _delete(Node* &top, Student key) {
	Node* p = top;
	Node* pv = p;
	while (p && !(cmp(p->data, key))) {
		pv = p;
		p = p->next;
	}
	if (p == top) {
		top = top->next;
	}
	else {
		if (p->next == NULL) {
			pv->next = NULL;
		}
		else {
			pv->next = p->next;
		}
	}
	delete p;
	p = NULL;
}


void task73v()
{
	setlocale(LC_ALL, "rus");
	int n;
	list<Student>a; list<Student>b;
	
	cout << "Введите количество студентов: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student tmp;
		_scan(tmp);
		a.push_back(tmp);
	}

	cout << endl << "Первоначальный список: ";
	for (list<Student>::iterator p = a.begin(); p != a.end(); ++p)
		_print(*p); cout << endl;
	
	//for(int i=0;i<n;i++)
	for (list<Student>::iterator p = a.begin(); p != a.end(); ++p)
	{
		
		if ((*p).averageScore >= 9.0)
		{
			
			b.push_back(*p);
			
			//b.splice(b.begin(), a, p, ++p);
			//list<Student>::iterator pp = p; if(p!=(a.end()--))++pp;
			a.remove(*p);
			p = a.begin();
			//break;
			
			//_print(*p);
			//p = pp;
			//p = a.erase(p);
			//y
			//a.erase(p++);
			//a = delete_list_elem(a, *p);
		}
		
	}

	
	cout << "Первоначальный измененный список:" << endl;
	for (list<Student>::iterator p = a.begin(); p != a.end(); ++p)
		_print(*p); cout << endl;

	cout << "Список отличников:" << endl;
	for (list<Student>::iterator p = b.begin(); p != b.end(); ++p)
		_print(*p); cout << endl;

}

void task73()
{
	setlocale(LC_ALL, "rus");
	int n;
	vector<Student>a; vector<Student>b;

	cout << "Введите количество студентов: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student tmp;
		_scan(tmp);
		a.push_back(tmp);
	}

	cout << endl << "Первоначальный список: ";
	for (vector<Student>::iterator p = a.begin(); p != a.end(); ++p)
		_print(*p); cout << endl;

	
	for (vector<Student>::iterator p = a.begin(); p != a.end(); ++p)
	{

		if ((*p).averageScore >= 9.0)
		{

			b.push_back(*p);
			a.erase(p);
			p = a.begin();
		}

	}


	cout << "Первоначальный измененный список:" << endl;
	for (vector<Student>::iterator p = a.begin(); p != a.end(); ++p)
		_print(*p); cout << endl;

	cout << "Список отличников:" << endl;
	for (vector<Student>::iterator p = b.begin(); p != b.end(); ++p)
		_print(*p); cout << endl;
	   	 
}