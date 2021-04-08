#include "score.h"

//define function input scores

void input_scores(int s[]) {
	int input = 0, i;
	printf("Enter scores, -1 to end: \n");
	for ( i = 0; i < MAX && input != -1; i++) {
		scanf("%d", &input);
		if (input < -1 || input > 100) {
			while (input<-1 || input > 100)
			{
				printf("Wrong value");
				scanf("%d", &input);
			}
		}
		s[i] = input;
	}
	printf("%d scores are given.\n", i-1);
}