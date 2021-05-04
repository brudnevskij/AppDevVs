#include "wlanAn.h"

void wlanAnalyse(FILE* fp) {
	int ssidCounter = -1;
	int bsidCounter = 0;
	char line[100];
	int ssidNumb = wlanCount(fp);
	struct ssid*ssidList = malloc(ssidNumb * sizeof(struct ssid));

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
	showWlan(ssidList, ssidNumb);
}