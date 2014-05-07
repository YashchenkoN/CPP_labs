#include <conio.h>
#include <iostream>
using namespace std;

void main()
{
	int n = 20;
	float factorial = 1;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	cout<<"The Factorial of "<<n<<" is "<<factorial<<endl;
	getch();
}