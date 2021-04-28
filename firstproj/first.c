#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dlen(int n) {
	int len = 0;
	while (n > 0) {
		n /= 10; ++len;   // these two statement will be executed as one step.
	}
	return len;
}

int main(void) {
	/*int a, b;
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
		
		
	}*/
	printf("%d", dlen(10234));
	
	return 0;
}