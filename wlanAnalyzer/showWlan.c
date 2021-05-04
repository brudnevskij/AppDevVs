#include "wlanAn.h"

void showWlan(struct ssid* ssidList, int q) {
	for (int i = 0; i < q; i++)
	{
		printf("ESSID: %s\n", ssidList[i].ssid);
		printf("Quantity of access points: %d\n", ssidList[i].numAp);
		for (int j = 0; j < ssidList[i].numAp; j++) {
			printf("          AP %d:", j + 1);
			printf(" %s ", ssidList[i].apList[j].apmac);
			printf("signal strength: %d ", ssidList[i].apList[j].signalStrenght);
			printf(" channel: %s \n", ssidList[i].apList[j].channel);
		}
		printf("\n");
	}
}