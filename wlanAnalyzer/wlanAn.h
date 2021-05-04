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
	char channel[10];
};

struct ssid {
	char ssid[50];
	int numAp;
	struct ap apList[20];
};

int wlanCount(FILE*);
void wlanAnalyse(FILE* fp);
enum LINE_TYPE whatLine(char*);
void showWlan(struct ssid*, int);
int readSignal(char*);
int readCh(char*);
char* readValue(char*);
int wlanCount(FILE* );
enum LINE_TYPE whatLine(char*);