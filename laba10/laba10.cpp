#include <iostream>
#include <conio.h>
using namespace std;

void array_el(int *arr);
void array_f(int *arr);

void main()
{
	setlocale(0, "Russian");
	int a[10];
	array_el(a);
	array_f(a);
	getch();
}

void array_el(int *arr)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "������� " << i << "-� ������� �������" << endl;
		cin >> arr[i];
	}
	cout << "��������� ������: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}
void array_f(int *arr)
{
	cout << endl << "������� x, y, z: " << endl;
	int x, y, z;
	cin >> x >> y >> z;
	cout << "�������� ������:" << endl;
	for (int i = 0; i < 10; i++)
	{
		if ((arr[i] < x) || (arr[i] > y))
		{
			arr[i] = z;
		}
		cout << arr[i] << " ";
	}
}