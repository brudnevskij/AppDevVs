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

//char *readValue(char* line, int wordsBefore){
//	char saveLine[100];
//	strcpy(saveLine, line);
//	char *token = strtok(line, " ");
//	//printf("%s", token);
//	for (int i = 0; i < wordsBefore; i++) {
//		token = strtok(NULL, " ");
//	}
//	printf("%s", token);
//	return token;
//}
int readSignal(char* line) {
	//char saveLine[100];
	int result;
	//strcpy(saveLine, line);
	char* token = strtok(line, ":");
	token = strtok(NULL, "%");
	result = atoi(token);
	return result;
}

int readCh(char* line) {
	//char saveLine[100];
	int result;
	//strcpy(saveLine, line);
	char* token = strtok(line, ":");
	result = atoi(token);
	return result;
}

char* readValue(char* line) {
	//char saveLine[100];
	//strcpy(saveLine, line);
	char* token = strtok(line, ":");
	//printf("%s", token);
	token = strtok(NULL, "\n");
	//printf("%s", token);
	return token;
}


void wlanAnalyse(FILE* fp) {


	int ssidCounter = -1;
	int bsidCounter = 0;
	char line[100];
	int ssidNumb = wlanCount(fp);
	struct ssid*ssidList = malloc(ssidNumb * sizeof(struct ssid));
	
	//for (int i = 0; i < ssidNumb; i++)
	//{
	//	char prob[20];
	//	sprintf(prob,"%d", i);

	//	//printf("%s\n", prob);
	//	
	//	strcpy(ssidList[i].ssid, "Hello Bogdan");
	//	strcat(ssidList[i].ssid,prob);
	//}

	while (fgets(line, 100, fp) != NULL) {
		switch (whatLine(line))
		{
		case -1:
			break;
		case 0:
			
			ssidCounter++;
			ssidList[ssidCounter].numAp = 0;
			bsidCounter = 0;
			strcpy(ssidList[ssidCounter].ssid, readValue(line));
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			strcpy(ssidList[ssidCounter].apList[bsidCounter].apmac, readValue(line));
			bsidCounter++;
			ssidList[ssidCounter].numAp++;
			break;
		case 10:
			ssidList[ssidCounter].apList[bsidCounter - 1].signalStrenght = readSignal(line);

			break;
		case 11:
			break;
		case 12:
			strcpy(ssidList[ssidCounter].apList[bsidCounter - 1].channel, readValue(line));
			break;
		default:
			break;
		}
	}


	for (int i = 0; i < ssidNumb; i++)
	{
		printf("ESSID: %s\n", ssidList[i].ssid);
		printf("Quantity of access points: %d\n", ssidList[i].numAp);
		for (int j = 0; j < ssidList[i].numAp; j++) {
			printf("          AP %d:", j+1);
			printf(" %s ", ssidList[i].apList[j].apmac);
			printf("signal strength: %d ", ssidList[i].apList[j].signalStrenght);
			printf(" channel: %s \n", ssidList[i].apList[j].channel);
		}
		printf("\n");

		//printf("%d\n", ssidList[i].apList[0].channel);

		//for (int j = 0; -1 != ssidList[i].apList[j].channel; j++) {
		//	printf("%s\n", ssidList[i].apList[j].apmac);
		//	//printf("%s\n", ssidList[i].apList[j].channel);

		//}

	}
	
	//while (fgets(line, 100, fp) != NULL) {
	//	if (line[0] != '\n') {
	//		
	//		printf("%s", line);
	//		if (whatLine(line) == SSID) {
	//			bsidCounter = 0;
	//			ssidCounter++;
	//			*ssidList[ssidCounter].ssid = readValue(line, 3);
	//			printf("%s", *ssidList[ssidCounter].ssid);
	//			printf("hello");
	//		}
	//		else if (whatLine(line) == NET || whatLine(line) == AUTH || whatLine(line) == ENCRYP) {
	//			continue;
	//		}
	//		else if (whatLine(line) == BSSID) {
	//			readValue(line, 1);
	//		}
	//	}
	//	else{
	//		continue;
	//	}

	//}
}