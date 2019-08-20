/*
	Find the smallest missing number in an array,
	with zero and negative elements as well.
*/

#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int a[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int max = a[0];
	for (int i = 1; i < N; i++) {
		if (a[i] > max) max = a[i];
	}

	int aux[max+1];

	for (int i = 0; i < N; i++) {
		if (a[i] > 0) aux[a[i]]++;
	}

	for (int i = 1; i < max+1; i++) {
		if (aux[i] == 0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << max+1 << endl;
}