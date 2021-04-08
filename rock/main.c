#include "appdev.h"

int main(void) {
	time_t t;
	srand((unsigned)time(&t));
	rock r;
	printf("App Dev Rock!\n");
	printf("enter rocker's name:");
	scanf_s("%s", r.rname,  (unsigned) _countof(r.rname));
	r.max = rand() % 50 + 51;
	r.min = rand() % 50 + 1;
	send_data(r);
	printf("Rock' Roll\n");
	return 0;
}