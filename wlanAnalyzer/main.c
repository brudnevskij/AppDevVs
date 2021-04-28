#include "wlanAn.h"


int main() {
	system(CMD);
	FILE* fp = fopen("wlan.txt", "r");
	if (fp != NULL) {
		wlanAnalyse(fp);
		fclose(fp);
	}
	else {
		printf("Error file: wlan.txt doesent exist.");
	}
	return 0;
}
