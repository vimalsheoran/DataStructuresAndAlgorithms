#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector <long long> primes;

void simple_seive(long long lower_limit, long long upper_limit) {
	long long limit = upper_limit-lower_limit + 1;
	bool marked[limit+1];
	memset(marked, true, sizeof(marked));
	for (int i = 2; i*i <= limit; i++) {
		if (marked[i] == true) {
			for (int j = i*i; j <= limit; j += i) marked[j] = false;
		}
	}

	for (int i = 2; i <= limit; i++) {
		if (marked[i] == true) {
			primes.push_back(i);
			printf("%d ", i);
		}
	}
	printf("\n");
}

void segmented_seive(long long start, long long end) {
	
	long long lower_limit = start;
	long long limit = floor(sqrt(end)) + 1;
	long long upper_limit = end;

	vector<long long>::iterator it = primes.begin();
	simple_seive(lower_limit, limit);
	bool marked[limit+1];

	long long low = limit;
	long long high = 2*limit;

	while(low < end) {
		if (high > end) high = end;
		memset(marked, true, sizeof(marked));
		for(; it != primes.end(); it++) {
			for (long long i = low; i < high; i += *it) {
				marked[i - low] = false;
			}
		}
		for (int i = 0; i <= limit; i++) {
			if (marked[i]) {
				printf("%lli ", i+low);
				primes.push_back(i+low);
			}
		}
		low += limit;
		high += limit;
	}
}

int main() {
	long long start = 1, end = 10;
	scanf("%lli", &start);
	scanf("%lli", &end);
	segmented_seive(start, end);
	printf("\n");
	return 0;
}