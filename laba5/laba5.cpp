#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(0, "Russian");
	int a;
	cout<<"¬ведите ¬аше число \n";
	cin>>a;
	if ((a<0)&&(a>=-9))
		cout<<"минус ";
	else
		if ((a>0)&&(a<=9))
			cout<<"плюс ";
	switch (a)
	{	
	case 9:
	case -9:
		puts("дев€ть");
		break;
	case 8:
	case -8:
		puts("восемь");
		break;
	case 7:
	case -7:
		puts("семь");
		break;
	case 6:
	case -6:
		puts("шесть");
		break;
	case 5:
	case -5:
		puts("п€ть");
		break;
	case 4:
	case -4:
		puts("четыре");
		break;
	case 3:
	case -3:
		puts("три");
		break;
	case 2:
	case -2:
		puts("два");
		break;
	case 1:
	case -1:
		puts("один");
		break;
	case 0:
		puts("ноль");
		break;
	default:
		cout<<"¬веденное число не корректно";
	}
	getch();
}