#include "triangle.h"


int main() {
	int a;

	a = get_int(MIN, MAX);
	for (int i = 0; i < a; i++) {
		pascal_triangle(i);
	}
	

	return 0;
}