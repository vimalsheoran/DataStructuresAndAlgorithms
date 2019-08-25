// Assuming that the array is sorted
// Other wise sort and follow the same approach

#include <iostream>
#include <map>

using namespace std;

void find_triplet(int arr[], int N) {
	int squares[N];
	map <int, int> buff;

	for (int i = 0; i < N; i++) {
		int sq = arr[i] * arr[i];
		buff[sq] = i;
	}

	for (int i = 0; i < N; i++) {
		squares[i] = arr[i] * arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			try {
				int sum = squares[i] + squares[j];
				int index = buff.at(sum);
				printf("Triplet: %d %d %d\n", arr[i], arr[j], arr[index]);
			} catch (out_of_range err) {

			}
		}
	}
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	find_triplet(arr, N);	
}