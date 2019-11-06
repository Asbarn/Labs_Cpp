#pragma once
#include "iostream"
#include "Header.h"

#include <string>
#include "iomanip"
#include <cstdlib>
#include "vector"
#include "cassert"
#include "fstream"
#include "list"
#include "iterator"
using namespace std;



class List :public bicycle, public car, public taxi, public minibus, public bus, public underground
{
	list<bicycle*>a;
public:
	List() 
	{a.push_back(new bicycle); };
	List( const List&l)
	{
		list<bicycle*>b = l.a;
		for (std::list<bicycle*>::iterator it = b.begin(); it != b.end(); it++)
			a.push_back(*it);
		
	}
	List(bicycle*i)
	{
		a.push_back(i);
	}

	List(List& l) {//конст перемещения
		a.clear();		
		list<bicycle*>b = l.a;
		for (std::list<bicycle*>::iterator it = b.begin(); it != b.end(); it++)
			a.push_back(*it);
		l.DeleteAll();
	}

	~List()
	{
		a.clear();
	}
	void Delete(int x)
	{
		std::list<bicycle*>::iterator it = a.begin(); int y = 0;
		while (it != a.end() && y != x)
		{
			it++; y++;
		}
		if(y==x)
		a.erase(it);
		
	}

	void DeleteAll()
	{
		a.clear();
	}

	void create(int n)
	{
		
		a.clear();
		for (int i = 0; i < n; i++)
		{
			//bicycle A;
			int k = (rand() % 5) + 1;
			switch (k)
			{
			case 1: {a.push_back(new car); }break;
			case 2: {a.push_back(new taxi);  } break;
			case 3: {a.push_back(new bus);  } break;
			case 4: {a.push_back(new minibus);  } break;
			case 5: {a.push_back(new underground);  } break;
			
			}
			
		}
	}

	List Copy(List&l)
	{
		List b(l);
		return b;
	}
	void Move(List&l)
	{
		a.clear();
		list<bicycle*>b = l.a;
		for (std::list<bicycle*>::iterator it = b.begin(); it != b.end(); it++)
			a.push_back(*it);
		l.DeleteAll();
	
	
	}
	void Show();
	void Add(bicycle* x);
	
	
	
};

void List::Add(bicycle* x)
{
	a.push_back(x);
}

void List::Show()
{

	for (std::list<bicycle*>::iterator it = a.begin(); it != a.end(); it++)
		(*it)->ShowInfo();

}