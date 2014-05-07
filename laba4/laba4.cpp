#include <stdio.h>
#include <conio.h>

void main()
{
	float x, y, a, c;
	printf("Enter x, y, a, c: \n");
	scanf("%f%f%f%f", &x, &y, &a, &c);

	if ((y == 0) && (x == 0))
		printf("This point is zero of coordinate system and belongs to this area \n");
	else
		if (y + x < 0)
			printf("This point is outside of area \n");
		else
		{
			if (y <= - a * (x * x) + c)
				printf("This point belongs to this area");
			else
				printf("This point is outside of area");
		}
	getch();
}