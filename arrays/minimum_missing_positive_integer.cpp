#include <iostream>
#include <string.h>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int max = arr[0];
	
	for (int i = 0; i < N; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	int aux[max+1];
	memset(aux, 0, sizeof(aux));

	for (int i = 0; i < N; i++) {
		if (arr[i] > 0)
			aux[arr[i]] = 1;
	}

	for (int i = 1; i < max+1; i++) {
		if (aux[i] == 0) {
			printf("Smallest missing positive is: %d\n", i);
			return 0;
		}
	}
}