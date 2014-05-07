#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	float a, b, c, d, y;							
	printf("Please enter your values \n");
	scanf("%f%f%f%f", &a, &b, &c, &d);
	y = pow(c,d)/log(b) + 7 * sqrt(sin(fabs(a + c)));
	printf("%f", y);
	getch();
}
