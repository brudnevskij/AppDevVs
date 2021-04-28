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

enum LINE_TYPE whatLine(char* line) {
	char saveLine[100]; 
	strcpy(saveLine, line);
	char* token = strtok(saveLine, " ");
	if (strcmp(token, "SSID") == 0) {
		return SSID;
	}
	else if (strcmp(token, "Network")== 0) {
		return NET;
	}
	else if (strcmp(token, "Authentication") == 0) {
		return AUTH;
	}
	else if (strcmp(token, "Encryption") == 0) {
		return ENCRYP;
	}
	else if (strcmp(token, "BSSID") == 0) {
		return BSSID;
	}
	else if (strcmp(token, "Signal") == 0) {
		return SIG;
	}
	else if (strcmp(token, "Radio") == 0) {
		return RADIO;
	}
	else if (strcmp(token, "Channel") == 0) {
		return CH;
	}
	else {
		return UNKNOWN;
	}	
}

char *readValue(char* line, int wordsBefore){
	char saveLine[100];
	strcpy(saveLine, line);
	char *token = strtok(line, " ");
	//printf("%s", token);
	for (int i = 0; i < wordsBefore; i++) {
		token = strtok(NULL, " ");
	}
	printf("%s", token);
	return token;
}

void wlanAnalyse(FILE* fp) {
	int ssidCounter = -1;
	int bsidCounter = 0;
	char line[100];
	int ssidNumb = wlanCount(fp);
	printf("%d\n", ssidNumb);
	struct ssid * ssidList = malloc(ssidNumb * sizeof(struct ssid));
	printf("%d\n", sizeof(ssidList));
	while (fgets(line, 100, fp) != NULL) {
		if (line[0] != '\n') {
			
			printf("%s", line);
			if (whatLine(line) == SSID) {
				bsidCounter = 0;
				ssidCounter++;
				*ssidList[ssidCounter].ssid = readValue(line, 3);
				printf("%s", *ssidList[ssidCounter].ssid);
				printf("hello");
			}
			else if (whatLine(line) == NET || whatLine(line) == AUTH || whatLine(line) == ENCRYP) {
				continue;
			}
			else if (whatLine(line) == BSSID) {
				readValue(line, 1);
			}
		}
		else{
			continue;
		}

	}
}