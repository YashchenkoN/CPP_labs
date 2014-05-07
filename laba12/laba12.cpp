#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

void enter();
void input(char *st);
void edit(char *st1, char *st2);
void output(char *st);
void main()
{
	enter();
	getch();
}

void enter()
{
	char str1[100], str2[100] = "";
	input(str1);
	if (str1[3] == '0')
	{
		switch(str1[4])
		{
		case '1':
			strcpy(str2, "January ");
			break;
		case '2':
			strcpy(str2, "February ");
			break;
		case '3':
			strcpy(str2, "March ");
			break;
		case '4':
			strcpy(str2, "April ");
			break;
		case '5':
			strcpy(str2, "May ");
			break;
		case '6':
			strcpy(str2, "June ");
			break;
		case '7':
			strcpy(str2, "July ");
			break;
		case '8':
			strcpy(str2, "August ");
			break;
		case '9':
			strcpy(str2, "September ");
			break;
		default:
			cout << "Error";
		}
	}
	if (str1[3] == '1')
	{
		switch (str1[4])
		{
		case '0':
			strcpy(str2, "October ");
			break;
		case '1':
			strcpy(str2, "November ");
			break;
		case '2':
			strcpy(str2, "December ");
			break;
		default:
			cout << "Error";
		}
	}
	strncat(str2, str1, 2);
	strncat(str2, ", 20", 4);
	strncat(str2, &str1[6], 2);
	output(str2);
}

void input(char *st)
{
	cout << "Enter data dd.mm.yy" << endl;
	cin >> st;
}

void output(char *st2)
{
	cout << st2;
}