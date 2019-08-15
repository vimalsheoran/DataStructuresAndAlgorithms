#include <iostream>

using namespace std;

int* get_prefix_array(int *arr, int N) {
	for (int i = 1; i < N; i++) {
		arr[i] = arr[i] + arr[i-1];
	}
	return arr;
}

int get_sum(int *arr, int l_index, int r_index) {
	if (l_index == 0 || l_index == r_index)
		return arr[r_index];
	return arr[r_index] - arr[l_index - 1]; 
}

bool check_for_equillibrium(int *a, int N) {
	int *prefix_arr = get_prefix_array(a, N);
	bool equillibrium_found = false;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (get_sum(prefix_arr, 1, N-1) == 0) 
				equillibrium_found = true;
		} else if (i == N-1) {
			if (get_sum(prefix_arr, 0, N-2) == 0)
				equillibrium_found = true;
		} else {
			if (get_sum(prefix_arr, 0, i-1) == get_sum(prefix_arr, i+1, N-1))
				equillibrium_found = true;
		}
	}
	return equillibrium_found;
}

int main () {
	int N;
	printf("Enter the size of the array: ");
	cin >> N;
	int a[N];
	printf("Please provide elements to this array:\n");
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	bool equillibrium = check_for_equillibrium(a, N);

	if (equillibrium) {
		printf("Array is in equillibrium.\n");
	} else {
		printf("Array is not in equillibrium.\n");
	}
}