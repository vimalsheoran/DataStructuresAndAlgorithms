#include <iostream>
#include <string.h>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr[N];
	int least_index;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> least_index;

	int _max = arr[0];
	for (int i = 1; i < N; i++) {
		if (_max < arr[i]) _max = arr[i];
	}

	int aux[_max+1];
	memset(aux, 0, sizeof(aux));
	for (int i = 0; i < N; i++) {
		aux[arr[i]] = 1;
	}

	int count = 0;
	for (int i = 1; i < _max+1; i++) {
		count += aux[i];
		if (least_index == count) {
			cout << i << endl;
			break;
		}
	}
}