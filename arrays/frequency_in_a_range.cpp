#include <iostream>
#include <unordered_map>

using namespace std;

void count_freq_hashmap(int *a, int N) {
	unordered_map<int, int> counter;
	for (int i = 1; i <= N; i++)
		counter[i] = 0;
	for (int i = 0; i < N; i++)
		counter[a[i]] += 1;
	for (int i = 1; i <= N; i++)
		cout << i << " occuring " << counter[i] << " times." << endl;
}

void count_freq_optimized(int *a, int N) {
	for (int i = 0; i < N; i++) {
		a[i] -= 1;
	}
	for (int i = 0; i < N; i++) {
		a[a[i]%N] += N;
	}
	for (int i = 0; i < N; i++) {
		cout << i+1 << " occuring " << a[i]/N << " times." << endl;
	}
}

int main() {
	
	int N;
	printf("Enter the size of the array.\n");
	cin >> N;
	int a[N];

	printf("Enter the elements of the array.\n");
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	count_freq_hashmap(a, N);
	count_freq_optimized(a, N);
}