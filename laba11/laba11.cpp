#include <iostream>
#include <conio.h>
using namespace std;

void init();
void arr_in(float **ar, int m, int n);
void arr_out(float **ar, int m, int n);
void arr_s(float **ar, int m, int n);

void main()
{
	init();
	getch();
}

void init()
{
	int x, y;
	cout << "Enter size " << endl;
	cin >> x >> y;
	float **a = new float *[x];
	for (int i = 0; i < x; i++)
		a[i] = new float [y];
	arr_in(a, x, y);
	arr_out(a, x, y);
	arr_s(a, x, y);
	for (int i = 0; i < x; i++)
		delete [] a[i];
	delete a;
}

void arr_in(float **ar, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter arr[" << i << "][" << j << "]" << endl;
			cin >> ar[i][j];
		}
	}
}

void arr_out(float **ar, int m, int n)
{
	cout << "your array" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ar[i][j] << "\t";
		}
		cout << endl;
	}
}
void arr_s(float **ar, int m, int n)
{
	float *b = new float [n], sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum = sum + ar[j][i];
		}
		b[i] = sum;
	}
	cout << "array b" << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << "\t";
	delete [] b;
}
