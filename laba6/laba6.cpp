#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	setlocale(0, "Russian");
	cout<<"������� ����� ��� �������� � ����, ���� (� �����) � ������"<<endl;
	float s;
	int i, r, p;
	cin>>s>>r>>p;
	for (i = 1; i <= r; i++)
	{
		s += s*p/100;
		cout<<"����� ������ ����� ���������� "<<i<<" ���� - "<<s<<endl;
	}
	getch();
}
