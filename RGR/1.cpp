#include <iostream>
#include <fstream>
#include <math.h>
#include <conio.h>
using namespace std;

//������� ��� �������� ����������
long double fact(long long n);
//����������� ������� ��� �������� �������� ������� (cosx)^2
long double value(long double x, long double e, long double step, int k);

void main() 
{
	setlocale(0, "Russian");
	double xBegin, xEnd, dx, eps;
	char c;
	bool boolean;
	cout << "��� ����� � ����� ������� f, ��� ����� � ���������� - k" << endl;
	c = getchar();
	if(c == 'f')
	{
	
		fstream f;
		f.open("D:\\in.txt");
		if(f)
		{
			while(!f.eof())
			{
				f >> xBegin;
				cout << "xBegin = " << xBegin << endl;
				f >> xEnd;
				cout << "xEnd = " << xEnd << endl;
				f >> dx;
				cout << "dx = " << dx << endl;
				f >> eps;
				cout << "eps = " << eps << endl;
			}
			f.close();
		}
		else
		{
			cout << "���� �� ������, ����������� ���� ������ � ����������" << endl;
			boolean = true;
		}
	}
	if((c == 'k')||(boolean))
	{
		cout << "������� ��������� � �������� �������� x (� ��������)" << endl;
		cin >> xBegin >> xEnd;
		cout << "������� ��� ����������" << endl;
		cin >> dx;
		cout << "������� �������� ����������" << endl;
		cin >> eps;
	}

	ofstream f;
	f.open("D:\\out.txt");
	f << "\tcos(x)^2 \t\t ������� ������� \t ����������� �������" << endl;
	cout << "\tcos(x)^2 \t\t ������� ������� \t ����������� �������" << endl;
	while(xBegin <= xEnd) //���� � ������������ �������� �������� ������� ��� ���������� � �������� �����
	{
		cout << "\tx = " << xBegin << "\t\t\t" << value(xBegin, eps, 2, 1) << "\t\t\t" << pow(cos(xBegin), 2) << endl;
		f << "\tx = " << xBegin << "\t\t\t" << value(xBegin, eps, 2, 1) << "\t\t\t" << pow(cos(xBegin), 2) << endl;
		xBegin = xBegin + dx;
	}
	f.close();
	getch();
}
 
long double value(long double x, long double e, long double step, int k) 
{
	//if (boolean)	//�������� �� ��, �������� ��� ��� ������� �� �����
	//{
	//	k = 1;		//���� ��� - ������ ��������� ���������: ������� � ���������� ���� �������
	//	step = 2.0;
	//}
	k *= -1;
	long double sum = k * (pow(2, step - 1) * pow(x, step)/fact(step));
	if (fabs(sum) <= e)	
		return 1 + sum;	//���� ���������� ����������� ��������, �� ���������� �������� �������
	else 
	{
		step += 2.0;	//����� - ����������� ������� � ��������� ��������� ���� ����
		return sum + value(x, e, step, k);
    }
}
 
long double fact(long long n) 
{
	long double res = 1;
	for(long long i = 1; i <= n; i++)
		res *= i;
	return res;
}