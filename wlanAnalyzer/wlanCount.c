#include "wlanAn.h"

int wlanCount(FILE* fp) {
	char line[100];
	int result;
	for (int i = 0; i < 3; i++) {

		fgets(line, 100, fp);
		if (i == 2) {
			char* token = strtok(line, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			result = atoi(token);
		}
	}
	return result;
}