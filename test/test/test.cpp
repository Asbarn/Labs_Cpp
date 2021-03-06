#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int MAX = 1000;

void insert(char A[1000], char B[1000], int n)
{
	int x = 0;
	int k = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (B[i] == '\n')
		{
			x = i;
			break;
		}
	}
	for (int i = 999; i > n; i--)
	{
		A[i] = A[i - x];
	}
	for (int i = 0; i < x; i++)
	{
		A[n + i] = B[i];
	}
}
void insert_x(char A[1000], char x)
{
	char B[2] = { 32, '\n' };
	for (int i = 0; i < 1000; i++)
	{
		if (A[i] == x)
		{
			insert(A, B, i + 1);
			insert(A, B, i);
			i = i + 1;
		}
	}
}
map<string, int*> readfile(ifstream &to, map<string, int*> A)
{
	string signs = { '+', '-', '=', ':', '(', ')', ',', '.', ';' , '\t' , '[' , ']', '<', '>', '{', '}' };
	vector<string> V;
	V.push_back("int"); V.push_back("double"); V.push_back("float"); V.push_back("char"); V.push_back("string"); V.push_back("struct"); V.push_back("void");
	char v1[MAX];
	string v;
	string v2; string v0; v0 += "0";
	int k = 1;
	int a = 0;
	int b = 0;
	int ii = 0, iii = 0;;
	map<string, int*>::iterator p;
	while (!to.eof())
	{
		if (!a) {
			for (int i = 0; i < MAX; i++)
			{
				v1[i] = 32;
			}
			to.getline(v1, MAX);
			for (int i = 0; i < signs.length(); i++)
			{
				insert_x(v1, signs.at(i));
			}
			v = v1;
		}
		if (v != "")
		{
			v2 += v.at(0); ii++;
			for (int i = 1; i < v.length(); i++)
			{
				
				if (v.at(i) != ' ')
				{
					v2 += v.at(i);
					ii++;
				}
				else
				{

					
					//if (a == 1)
					

					//if (!iii) {
						if (atoi(v2.c_str()) != 0 || v2=="0" || v2=="true" || v2=="false")
						{
							//a++; i = i - ii - 1; ii = 0; //iii=1;
							//cout << v2 << endl;
							//break;
							{p = A.find(v2);
							if (p != A.end())
							{
								//p->second[0]++;
								p->second[k] = k;
							}
								a = 0;

								for (int i1 = 0; i1 < v2.length(); i1++)
								{
									if (v2.at(i1) == '*' || v2.at(i1) == '&')
									{
										v2.erase(0, 1);
										i1 = -1;
									}
								}
								int o = 0;
								for (int i2 = 0; i2 < V.size(); i2++)
								{
									if (v2 == V.at(i2))
									{
										o++;
										break;
									}
								}
								if (v2 != "[" && v2 != "(" && v2 != ")" && v2 != "<" && v2 != ";" && v2 != ">" && v2 != "" && o == 0)
								{
									p = A.find(v2);
									if (p == A.end())
									{
										int *X = new int[MAX];
										for (int i = 0; i < MAX; i++)
										{
											X[i] = 0;
										}
										A.insert(pair <string, int*>(v2, X));
										p = A.find(v2);
										p->second[k] = k;
									}
									else
									{
										p->second[0]++;
										p->second[k] = k;
									}
									iii = 1;
								}
							}

						}
					//}
					if (b == 1)
					{
						b = 0;
						V.push_back(v2);
					}
					if (v2 == "class" || v2 == "typename")
					{
						b++;
					}
					
					v2 = "";
				}
			}
		}
		if (b == 1)
		{
			b = 0;
			V.push_back(v2);
		}
		k++;
		v2 = "";
	}
	v.clear();
	v2.clear();
	return A;
}
void writefile(ofstream &from, map<string, int*> A)
{
	map<string, int*>::iterator p = A.begin();
	while (p != A.end())
	{
		from << "Идентификатор: " << p->first << "   " << "Количество раз, которое он встретился: " << p->second[0] + 1 << "   " << endl;
		from << "Номера строк, в которых он встретился: ";
		for (int i = 1; i < MAX; i++)
		{
			if (p->second[i] != 0)
			{
				from << p->second[i] << "  ";
			}
		}
		p++;
		from << endl;
	}
}
void out(map<string, int*> A)
{
	map<string, int*>::iterator p = A.begin();
	while (p != A.end())
	{
		cout << "Identifikator: " << p->first << "   " << "Kolichestvo raz, kotoroe on vstretilsya: " << p->second[0] + 1 << "   " << endl;
		cout << "Nomera strok v kotoryh vstretilsya: ";
		for (int i = 1; i < MAX; i++)
		{
			if (p->second[i] != 0)
			{
				cout << p->second[i] << "  ";
			}
		}
		p++;
		cout << endl;
	}
}

int main()
{
	ifstream to("to.txt");
	map<string, int*> A;
	A = readfile(to, A);
	to.close();

	ofstream from("from.txt");
	writefile(from, A);
	from.close();
	out(A);
	A.clear();
	system("pause");
}