#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	printf("Enter 2 numbers");
	scanf("%d%d", &a, &b);
	if (a>b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	int c = 0;
	for (int i = a; i <= b; i++)
	{
		
		if (i % 3 == 0)
		{
			printf(" %6d ", i);
			c++;
			if (c % 4 == 0) printf("\n");
		}
		
		
	}
	return 0;
}