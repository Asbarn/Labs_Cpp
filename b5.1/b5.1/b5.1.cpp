// b5.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <conio.h>

#include <ctime>
#include <iomanip>
using namespace std;

//1
//void zapol1(int *[], int );
//
//void main()
//{
//	int n;
//	cout << "n = "; cin >> n;
//	int **Arr = new int*[n];
//	/*for (int count = 0; count < n; count++)
//		ptrarray[count] = new int[n];*/
//	
//
//	// заполнение массива
//	/*for (int count_row = 0; count_row < n; count_row++)
//		for (int count_column = 0; count_column < n; count_column++)
//			ptrarray[count_row][count_column] = 0;*/
//
//	//int Arr[n][n];
//	
//
//	zapol1(Arr, n);
//
//	for (int q = 0; q < n; q++)
//	{
//		for (int w = 0; w < n; w++)
//		{
//			cout << setw(4) << Arr[q][w];
//		};
//		cout << endl;
//	}
//
//	
//	
//
//	//zapol1(ptrarray, n);
//
//	// вывод массива
//	/*for (int count_row = 0; count_row < n; count_row++)
//	{
//		for (int count_column = 0; count_column < n; count_column++)
//			cout << setw(4) << setprecision(2) << a[count_row][count_column] << "   ";
//		cout << endl;
//	}*/
//
//	
//
//	//for (int count = 0; count < n; count++)
//		//delete[]a[count];
//	/*system("pause");
//	return 0;*/
//}
//
//
//void zapol1( int *a[]	, int n)
//{
//	
//	//int per = 1;
//	//int k = n, m = 0;
//	//int i = 1, j = n - 1;
//
//	//for (; k != 0;)
//	//{
//	//	for (; i < k; i++)//vniz
//
//	//	{
//	//		ptrarray[i][j] = per;	per++;
//	//	}
//	//	for (; j >= m; j--)
//	//	{
//	//		ptrarray[i][j] = per;	per++;//vlevo
//	//	}
//	//	for (; i >= m; i--)
//
//	//	{
//	//		ptrarray[i][j] = per;	per++;//vverh
//	//	}
//	//	k--;
//	//	for (; j < k; j++)
//	//	{
//	//		ptrarray[i][j] = per;	per++;//vpravo
//	//	}
//	//	m++;
//	//}
//	//int cnt = 25;
//	//int i = 0;
//	//int j = -1;
//
//	//while (cnt) {
//	//	while (j < n - i - 1) {                     //right
//	//		a[i][++j] = cnt--;
//	//	}
//
//	//	if (!cnt) break;
//
//	//	while (i < j) {                             //down
//	//		a[++i][j] = cnt--;
//	//	}
//	//	while (j > n - i - 1) {                     //left
//	//		a[i][--j] = cnt--;
//	//	}
//	//	while (i > j + 1) {                         //up
//	//		a[--i][j] = cnt--;
//	//	}
//	//}
//	int i = 0, j, k = 0, p = 1;
//	while (i < n*n) /*Цикл по номеру витка*/
//	{
//
//
//		k++;
//		for (j = k - 1; j < n - k + 1; j++)
//		{
//			a[j][n - k] = p++;
//			i++;
//		}   /* --//-- По правому вертикальному столбцу*/
//
//		for (j = n - k - 1; j >= k - 1; j--)
//		{
//			a[n - k][j] = p++;
//			i++;
//		}   /* --//-- по нижнему горизонтальному столбцу*/
//
//		for (j = n - k - 1; j >= k; j--)
//		{
//			a[j][k - 1] = p++;
//			i++;
//		}   /* --//-- по левому вертикальному столбцуний верхнего гор столбца*/
//
//
//		for (j = k - 1; j < n - k; j++)
//		{
//			a[k - 1][j] = p++;
//			i++;
//		}   /*Определение значений верхнего гор столбца*/
//
//	}
//}


//2
//int** sozdanie(int n, int m)
//{
//	int **A;
//	A = new int *[n]; 
//	for (int i = 0; i < n; i++) {
//		A[i] = new int[m];
//	}
//	return A;
//}

void initialize(int** a, int n, int m)
{
	int i = 0, j, k = 0, p = 1;
	while (i < n*n) 
	{


		k++;
		for (j = k - 1; j < n - k + 1; j++)
		{
			a[j][n - k] = p++;
			i++;
		}  

		for (j = n - k - 1; j >= k - 1; j--)
		{
			a[n - k][j] = p++;
			i++;
		}   

		for (j = n - k - 1; j >= k; j--)
		{
			a[j][k - 1] = p++;
			i++;
		}  


		for (j = k - 1; j < n - k; j++)
		{
			a[k - 1][j] = p++;
			i++;
		}  

	}



}
const int n = 5;
void zapol1(int* a[],int n)
{
	int i = 0, j, k = 0, p = 1;
	while (i < n*n)
			{
		
		
				k++;
				for (j = k - 1; j < n - k + 1; j++)
				{
					a[j][n - k] = p++;
					i++;
				}  
		
				for (j = n - k - 1; j >= k - 1; j--)
				{
					a[n - k][j] = p++;
					i++;
				}   
		
				for (j = n - k - 1; j >= k; j--)
				{
					a[j][k - 1] = p++;
					i++;
				}  
		
		
				for (j = k - 1; j < n - k; j++)
				{
					a[k - 1][j] = p++;
					i++;
				}  
		
			}
}




void main()
{

	
	//cout << "n= "; cin >> n;
	//int **A;
	int A[n][n];
	//A = sozdanie(n, n); 
	int x;
	cout << " vvedite sposob(1 - 2)"; cin >> x; cout << endl;
	if (x = 1)
	{
		int *par1[] = { A[0],A[1] ,A[2],A[3],A[4]};
		initialize(par1, n, n);
	}
	if (x = 2)
	{
		int *par2[] = { &A[0][0],&A[1][0] ,&A[2][0],&A[3][0] ,&A[4][0]};
		zapol1(par2, n);
	}

	else cout << "Neprav vibor" << endl;
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			cout << setw(4) << A[q][w];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A; 
	_getch();
}