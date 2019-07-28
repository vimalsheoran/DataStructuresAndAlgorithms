#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void simple_seive(int lower_bound, int upper_bound) {
	int limit = (upper_bound-lower_bound) + 1;
	bool marked[limit];
	memset(marked, true, sizeof(marked));
	int i = lower_bound;
	while (i*i < upper_bound) {
		if (marked[i - lower_bound] == true) {
			for(int j = i*i; j <= upper_bound; j+=i)
				marked[j - lower_bound] = false;
		}
		i += 1;
	}
	for (int i = 0; i < limit; i++) {
		if (marked[i] == true) printf("%d ", i+lower_bound);
	}
	printf("\n");
}

int main() {
	int lower_bound, upper_bound;
	cin >> lower_bound >> upper_bound;
	simple_seive(lower_bound, upper_bound);
}