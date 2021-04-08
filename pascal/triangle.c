#include "triangle.h"

void pascal_triangle(int v) {
	int i, j;
	i = v;
	//some spaces
	for (j = 0; j <= i; j++) {
		printf("%6d", comb(i, j));
	}
	printf("\n");
}

int comb(int n, int m){
	if (n < m) return 0;
	return fact(n) / (fact(n - m) * fact(m));
}

unsigned long long int fact( int n) {
	unsigned long long int result = 1;
	for (int i = n; i > 1; i--) {
		result *= i;
	}
	return result;
}