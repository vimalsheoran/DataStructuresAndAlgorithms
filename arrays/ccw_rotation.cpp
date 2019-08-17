// Counter clockwise rotation of a given array

#include <iostream>
#include <vector>

using namespace std;

int A[10] = {1,2,3,4,5,6,7,8,9,10};

void rotate(int N) {
	vector <int> temp;
	for (int i = 0; i < N; i++) temp.push_back(A[i]);
	for(int i = N; i < 10; i++) {
		A[i-N] = A[i];
	}
	for(int i = 0; i < N; i++) {
		A[10-N+i] = temp[i];
	}
	for (int i = 0; i < 10; i++) printf("%d ", A[i]);
	printf("\n");
}

int main () {
	int N;
	cin >> N;
	rotate(N);
}