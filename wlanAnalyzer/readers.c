#include "wlanAn.h"

int readSignal(char* line) {
	int result;
	char* token = strtok(line, ":");
	token = strtok(NULL, "%");
	result = atoi(token);
	return result;
}

int readCh(char* line) {
	int result;
	char* token = strtok(line, ":");
	result = atoi(token);
	return result;
}

char* readValue(char* line) {
	char* token = strtok(line, ":");
	token = strtok(NULL, "\n");
	return token;
}