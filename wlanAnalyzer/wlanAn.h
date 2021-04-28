#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define CMD "netsh wlan show networks mode=bssid > wlan.txt"

enum LINE_TYPE {UNKNOWN=-1, SSID, NET, AUTH, ENCRYP, BSSID, SIG=10, RADIO, CH};

struct ap {
	char apmac[20];
	int signalStrenght;
	int channel;
};

struct ssid {
	char ssid[30];
	int numAp;
	struct ap apList[20];
};

int wlanCount(FILE*);
void wlanAnalyse(FILE* fp);
int wlanNumber(char*);
char* readValue(char*, int);
enum LINE_TYPE whatLine(char*);
void showWlan(struct ssid*, int);
void takeAwayNewLine(char*);