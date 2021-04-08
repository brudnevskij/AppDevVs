#include "triangle.h"

int get_int(int min, int max) {
	int t;
	do {
		printf("enter a positive number between %d, %d", min, max);

		int r = scanf("%d", &t);
		if (r < 1) t = 0;

	} while (t <min || t > max);

	return t;
}