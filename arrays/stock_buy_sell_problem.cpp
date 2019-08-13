#include <iostream>

using namespace std;

int a[7] = {1, 5, 3, 8, 12, 11, 17};

int main () {
	int total_profit = 0;
	int local_minima = -1, local_maxima = -1;
	if (a[0] < a[1]) local_minima = a[0];
	for (int i = 1; i < 7; i++) {
		if (a[i] < a[i+1] && a[i] < a[i-1]) {
			local_minima = a[i];
		} else if (a[i] > a[i+1] && a[i] > a[i-1]) {
			local_maxima = a[i];
		}
		if (local_minima != -1 and local_maxima != -1) {
			total_profit += (local_maxima - local_minima);
			local_minima = -1; local_maxima = -1;
		}
	}
	printf("%d\n", total_profit);
}