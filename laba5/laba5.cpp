#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(0, "Russian");
	int a;
	cout<<"������� ���� ����� \n";
	cin>>a;
	if ((a<0)&&(a>=-9))
		cout<<"����� ";
	else
		if ((a>0)&&(a<=9))
			cout<<"���� ";
	switch (a)
	{	
	case 9:
	case -9:
		puts("������");
		break;
	case 8:
	case -8:
		puts("������");
		break;
	case 7:
	case -7:
		puts("����");
		break;
	case 6:
	case -6:
		puts("�����");
		break;
	case 5:
	case -5:
		puts("����");
		break;
	case 4:
	case -4:
		puts("������");
		break;
	case 3:
	case -3:
		puts("���");
		break;
	case 2:
	case -2:
		puts("���");
		break;
	case 1:
	case -1:
		puts("����");
		break;
	case 0:
		puts("����");
		break;
	default:
		cout<<"��������� ����� �� ���������";
	}
	getch();
}