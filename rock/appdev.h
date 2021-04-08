#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <time.h>
#include <curl/curl.h>
#include <stdlib.h>
#define N 20

typedef struct {
	int max;
	int min;
	char rname[N];
}rock;

void send_data(rock);