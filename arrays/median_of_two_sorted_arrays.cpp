// Works only for arrays of equal size

#include <bits/stdc++.h>

using namespace std;

int median(int arr[], int N) {
	if (N%2 == 0)
		return (arr[N/2] + arr[N/2 - 1])/2;
	return arr[N/2];
}

int find_sorted_median(int arr1[], int arr2[], int N) {
	if (N <= 0) return -1;
	if (N == 1) return (arr1[0] + arr2[0])/2;
	if (N == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
	
	int m1 = median(arr1, N);
	int m2 = median(arr2, N);

	if (m1 == m2) return m1;
	if (m1 < m2) {
		if (N%2 == 0)
			return find_sorted_median(arr1+N/2-1, arr2, N-N/2+1);
		return find_sorted_median(arr1+N/2, arr2, N-N/2);
	}
	if (N%2 == 0)
		return find_sorted_median(arr1, arr2+N/2-1, N-N/2+1);
	return find_sorted_median(arr1, arr2+N/2, N-N/2);
}

int main() {

	int N;
	cin >> N;
	int arr1[N], arr2[N];
	for (int i = 0; i < N; i++) cin >> arr1[i];
	for (int i = 0; i < N; i++) cin >> arr2[i];

	int median = find_sorted_median(arr1, arr2, N);
	cout << median << endl;
}