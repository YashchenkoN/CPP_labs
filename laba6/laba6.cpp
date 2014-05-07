#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	setlocale(0, "Russian");
	cout<<"¬ведите сумму дл€ внесени€ в банк, срок (в годах) и ставку"<<endl;
	float s;
	int i, r, p;
	cin>>s>>r>>p;
	for (i = 1; i <= r; i++)
	{
		s += s*p/100;
		cout<<"—умма вклада после завершени€ "<<i<<" года - "<<s<<endl;
	}
	getch();
}
