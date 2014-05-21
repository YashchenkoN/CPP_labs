#include <iostream>
#include <fstream>
#include <math.h>
#include <conio.h>
using namespace std;

//функция для рассчета факториала
long double fact(long long n);
//рекурсивная Функция для рассчета значения функции (cosx)^2
long double value(long double x, long double e, long double step, int k);

void main() 
{
	setlocale(0, "Russian");
	double xBegin, xEnd, dx, eps;
	char c;
	bool boolean;
	cout << "Для ввода с файла введите f, для ввода с клавиатуры - k" << endl;
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
			cout << "Файл не найден, продолжайте ввод данных с клавиатуры" << endl;
			boolean = true;
		}
	}
	if((c == 'k')||(boolean))
	{
		cout << "Введите начальное и конечное значения x (в радианах)" << endl;
		cin >> xBegin >> xEnd;
		cout << "Введите шаг вычисления" << endl;
		cin >> dx;
		cout << "Введите точность вычислений" << endl;
		cin >> eps;
	}

	ofstream f;
	f.open("D:\\out.txt");
	f << "\tcos(x)^2 \t\t Формула Тейлора \t Контрольная формула" << endl;
	cout << "\tcos(x)^2 \t\t Формула Тейлора \t Контрольная формула" << endl;
	while(xBegin <= xEnd) //цикл с предусловием рассчета значения функции для промежутка с заданным шагом
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
	//if (boolean)	//проверка на то, вызывали или нет функцию до этого
	//{
	//	k = 1;		//если нет - задаем начальные параметры: степень и коэфициент ряда Тейлора
	//	step = 2.0;
	//}
	k *= -1;
	long double sum = k * (pow(2, step - 1) * pow(x, step)/fact(step));
	if (fabs(sum) <= e)	
		return 1 + sum;	//если достиглась необходимая точность, то возвращаем значение функции
	else 
	{
		step += 2.0;	//иначе - увеличиваем степень и добавляем следующий член ряда
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