#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

//функция для рассчета факториала
long double fact(long long n);
//рекурсивная Функция для рассчета значения функции (cosx)^2
long double value(long double x, long double e, bool boolean);

static long double step;
static int k;
 
void main() 
{
	setlocale(0, "Russian");
	double xBegin, xEnd, dx, eps;
	cout << "Введите начальное и конечное значения x (в радианах)" << endl;
	cin >> xBegin >> xEnd;
	cout << "Введите шаг вычисления" << endl;
	cin >> dx;
	cout << "Введите точность вычислений" << endl;
	cin >> eps;
	while(xBegin <= xEnd) //цикл с предусловием рассчета значения функции для промежутка с заданным шагом
	{
		cout << "x = " << xBegin << endl;
		cout << "(cos(x))^2 = " << value(xBegin, eps, true) << endl;
		xBegin = xBegin + dx;
	}
	getch();
}
 
long double value(long double x, long double e, bool boolean) 
{
	if (boolean)	//проверка на то, вызывали или нет функцию до этого
	{
		k = 1;		//если нет - задаем начальные параметры: степень и коэфициент ряда Тейлора
		step = 2.0;
	}
	k *= -1;
	long double sum = k * (pow(2, step - 1) * pow(x, step)/fact(step));
	if (fabs(sum) <= e)	
		return 1 + sum;	//если достиглась необходимая точность, то возвращаем значение функции
	else 
	{
		step += 2.0;	//иначе - увеличиваем степень и добавляем следующий член ряда
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
