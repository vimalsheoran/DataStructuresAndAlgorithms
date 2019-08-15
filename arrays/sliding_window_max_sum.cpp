/**
	For a given array say A = {1, 4, 2, 10, 23, 3, 1, 0, 20}
	find the maximum sum of a subarray of size four, subarray
	constructed from the same array.
*/

#include <iostream>

using namespace std;

int main () {

	int a[9] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
	int k = 4;
	int max_sum = INT8_MIN;
	for (int i = 0; i <= k; i++) {
		int curr_sum = 0;
		for (int j = 0; j < k; j++) {
			curr_sum += a[i+j];
		}
		max_sum = max(curr_sum, max_sum); 
	}
	printf("%d\n", max_sum);
}