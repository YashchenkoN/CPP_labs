#include <iostream>
#include <conio.h>
using namespace std;

int bit(int p);

void main()
{
	setlocale(0, "Russian");
	int n;
	cout<<"Введите n: ";
	cin>>n;
	cout<<"Количество единичных битов в числе "<<n<<" - "<<bit(n);
	getch();
}
int bit(int p)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (p & 1 == 1)
			count++;
		p = p >> 1;
	}
	return count;
}