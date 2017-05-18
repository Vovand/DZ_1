// DZ_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define size 25
 
void pr1(void);
void pr2(void);
void pr3(void);
void show(int* parr);
void show(int* parr, int N);
int* analysis(int* parr);
int* init(void);
void showSymbols(int* pArr, int* pMask);
void show_dolar(int N);
void show_grille(int N);
void show_star(int N);
void freeMem(int* Parr);
void init(int* parr, int N);
int* creat_int(int N);
void search(int* parr1, int N, int* parr2, int M);

int main()
{
	int n;
	cout << "Select program 1 or 2 or 3 : " << endl;
	cin >> n;
	if (n == 1)
		pr1();

	if (n == 2) 
		pr2();
	if (n ==3)
		pr3();
	
    return 0;
}

void pr1(void)
{
	cout << "____Program_1____" << endl;
	int* pArr;
	int* pMask;
	pArr = init();
	pMask = analysis(pArr);
	show(pArr);
	showSymbols(pArr, pMask);
	freeMem(pArr);
	freeMem(pMask);
}

void pr2(void)
{
	cout << "____Program_2____"<<endl;
	int N;
	int n = 0;
	cout << "Enter size : ";
	cin >> N;
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < i + 1; ++j) {
			n++;
		}
	}
	int* pArr = new int[n];
	n = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			*(pArr + n) = i+1;
			n++;
		}
	}
	show(pArr,n);
	freeMem(pArr);
}

void pr3(void)
{
	cout << "____Program_3____" << endl;
	int size1, size2;
	int* pArr1;
	int* pArr2;
	cout << "Enter mas size 1 :";
	cin >> size1;
	cout << "Enter mas size 2 :";
	cin >> size2;

	pArr1 = creat_int(size1);
	pArr2 = creat_int(size2);

	init(pArr1, size1);
	init(pArr2, size2);
	cout << "Mas1: ";
	show(pArr1, size1);
	cout << "Mas2: ";
	show(pArr2, size2);

	search(pArr1, size1, pArr2, size2);

}

void show(int* parr)
{
	for (int i = 0; i < size; i++)
		cout << *(parr + i) << " ";
	cout << endl;
}

int* analysis(int* parr)
{
	int n = 0;
	int* pMask = new int[size];

	for (int i = 0; i < size; i++)
		*(pMask + i) = 0;

	for (int i = 0; i < size; i++)
	{
		if ((*(parr + i)) >= 10)
		{
			n = n +1;
			if (n >= 3)
			{
				*(pMask + i-2) = 1;
				*(pMask + i-1) = 1;
				*(pMask + i) = 1;
			}
			
		}
		else
			n = 0;
	}
	return pMask;
}

int* init(void)
{
	int* parr = new int[size];
	for (int i = 0; i < size; i++)
		*(parr + i) = rand() % 25;
	return parr;
}

void showSymbols(int* pArr, int* pMask)
{
	for (int i = 0; i < size; i++)
	{
		if (*(pMask + i) == 1)
		{
			show_dolar(*(pArr + i));
		}
		else
		{
			if (*(pArr + i) >= 10)
				show_grille(*(pArr + i));
			else
				show_star(*(pArr + i));
		}
	}
}

void show_dolar(int N)
{
	for (int i = 0; i < N; i++)
		cout << "$";
	cout << endl;
}

void show_grille(int N)
{
	for (int i = 0; i < N; i++)
		cout << "#";
	cout << endl;
}

void show_star(int N)
{
	for (int i = 0; i < N; i++)
		cout << "*";
	cout << endl;
}

void show(int* parr, int N)
{
	for (int i = 0; i < N; i++)
		cout << *(parr + i) << " ";
	cout << endl;
}

void freeMem(int* Parr)
{
	delete[] Parr;
	cout << "Memory is free" << endl;
}

int* creat_int(int N)
{
	int* pArr = new int[N];
	return pArr;
}

void init(int* parr, int N)
{
	for (int i = 0; i < N; i++)
		*(parr + i) = rand() % 10;
}

void search(int* parr1, int N, int* parr2, int M)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (*(parr1 + i) == *(parr2 + j))
			{
				count++;
				cout << "Count = " << count << endl;
				break;
			}
		}
	}
	int* newArr = new int[count];

	for (int i = 0, count = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (*(parr1 + i) == *(parr2 + j))
			{
				*(newArr + count) = *(parr1 + i);
				count++;
				break;
			}
		}
	}
	show(newArr, count);
	freeMem(newArr);
}