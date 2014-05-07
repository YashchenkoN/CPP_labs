#include <iostream>
#include <conio.h>
using namespace std;

void enter();
int function(int, int);

void main()
{
	enter();
}
void enter()
{
	int a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;
	if (b < 0)
		cout << "a*b=" << -function(a, b);
	else
		cout << "a*b=" << function(a, b);
	getch();
}
int function(int c, int d)
{

	if ((d == 1)||(d == -1))
		return c;
	else
		if (d > 0)
		{
			c = c + function(c, d-1);
			return c;
		}
		else
		{
			if (d == 0)
				return 0;
			else
			{
				c = c + function(c, d + 1);
				return c;
			}
		}
}