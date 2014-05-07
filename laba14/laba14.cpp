#include <iostream>
#include <conio.h>
using namespace std;

void enter();
void newfile();
void twofiles();
void reading();

void main()
{
	enter();
	getch();
}

void enter()
{
	FILE *f;
	f = fopen("D:\\f.dat", "rb");
	if (f)
		twofiles();
	else
	{
		newfile();
		twofiles();
	}
	reading();
}

void newfile()
{
	FILE *f;
	int a;
	f = fopen("D:\\f.dat", "wb");
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		fwrite(&a, sizeof(int), 1, f);
	}
	fclose(f);
}

void twofiles()
{
	FILE *f;
	FILE *f1;
	FILE *f2;
	int a;
	f = fopen("D:\\f.dat", "rb");
	f1 = fopen("D:\\f1.dat", "wb");
	f2 = fopen("D:\\f2.dat", "wb");
	while (fread(&a,sizeof(int), 1, f))
	{
		if (a % 2 == 0)
			fwrite(&a, sizeof(int), 1, f1);
		else 
			fwrite(&a, sizeof(int), 1, f2);
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}

void reading()
{
	FILE *f;
	FILE *f1;
	FILE *f2;
	f = fopen("D:\\f.dat", "rb");
	f1 = fopen("D:\\f1.dat", "rb");
	f2 = fopen("D:\\f2.dat", "rb");
	int a;
	cout << "file1" << endl;
	while (fread(&a, sizeof(int), 1, f))
		cout << a << "\t";
	cout << "file2" << endl;
	while (fread(&a, sizeof(int), 1, f1))
		cout << a << "\t";
	cout << endl;
	cout << "file3" << endl;
	while(!feof(f2))
	{
		fread(&a, sizeof(int), 1, f2);
		if (!feof(f2))
			cout << a << "\t";
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}