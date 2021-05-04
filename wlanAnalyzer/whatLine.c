#include "wlanAn.h"

enum LINE_TYPE whatLine(char* line) {
	char saveLine[100];
	strcpy(saveLine, line);
	char* token = strtok(saveLine, " ");
	if (strcmp(token, "SSID") == 0) {
		return SSID;
	}
	else if (strcmp(token, "Network") == 0) {
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
