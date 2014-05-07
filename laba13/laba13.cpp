#include <iostream>
#include <conio.h>
using namespace std;

void enter();
void arr_a(int **arr, int x, int y);
void arr_sort(int **arr, int x, int y);

void main()
{
	setlocale(0, "Russian");
	enter();
	getch();
}

void enter()
{
	int x, y;
	cin >> x >> y;
	int **a = new int *[x];
	for (int i = 0; i < x; i++)
		a[i] = new int [y];
	arr_a(a, x, y);
	arr_sort (a, x, y);

}
void arr_a(int **arr, int m, int n)
{
	cout << "Начальный массив" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand()%50;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void arr_sort(int **arr, int m, int n)
{
	int temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < m; h++)
			{
				for (int g = 0; g < n; g++)
				{
					if ((arr[h][g] > arr[i][j])&&(arr[h][g] % 2 == 1)&&(arr[i][j] % 2 == 1))
					{
						temp = arr[i][j];
						arr[i][j] = arr[h][g];
						arr[h][g] = temp;
					}
				}
			}
		}
	}
	cout << "Конечный массив" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}