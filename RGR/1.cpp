#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

long double fact(long long n);
long double value(long double x, long double e, bool boolean);

static long double step;
static int k;
 
void main() 
{
	setlocale(0, "Russian");
	double xBegin, xEnd, dx, eps;
	cout << "������� ��������� � �������� �������� x (� ��������)" << endl;
	cin >> xBegin >> xEnd;
	cout << "������� ��� ����������" << endl;
	cin >> dx;
	cout << "������� �������� ����������" << endl;
	cin >> eps;
	while(xBegin <= xEnd)
	{
		cout << "x = " << xBegin << endl;
		cout << "(cos(x))^2 = " << value(xBegin, eps, true) << endl;
		xBegin = xBegin + dx;
	}
	getch();
}
 
long double value(long double x, long double e, bool boolean) 
{
	if (boolean)
	{
		k = 1;
		step = 2.0;
	}
	k *= -1;
	long double sum = k * (pow(2, step - 1) * pow(x, step)/fact(step));
	if (fabs(sum) <= e)
		return 1 + sum;
	else 
	{
		step += 2.0;
		return sum + value(x, e, false);
    }
}
 
long double fact(long long n) 
{
	long double res = 1;
    	for(long long i = 1; i <= n; i++)
		res *= i;
	return res;
}
