#include "score.h"

void classification(int m[], int st[]){
	int i;
	for (i = 0; i < MAX && m[i] != -1; i++) {
		switch (m[i]) {
		case 0:st[0]++; break;
		case 1:st[1]++; break;
		case 2:st[2]++; break;
		case 3:st[3]++; break;
		case 4:st[4]++; break;
		case 5:st[5]++; break;
		default: printf("Invalid mark!\n");
		}

	}
	printf("%d marks are classified\n", i);

}