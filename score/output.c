#include "score.h"

void output_results(int m[], int st[]){
	printf("here are the marks:\n");
	for (int i = 0; i < MAX && m[i] != -1; i++) {
		printf("%4d", m[i]);
	}
	puts("");
	printf("Here are statistics: \n");
	printf("%5s%10s\n---------------\n", "Mark", "Hits");
	for (int i = 0; i < 6; i++) {
		printf("%5d%10d\n", i, st[i]);
	}
}