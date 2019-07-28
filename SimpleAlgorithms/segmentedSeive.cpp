#include <iostream>
#include <cmath>
#include <cstring>
#include <set>

#define ll long long

using namespace std;

set<ll>primes;

void print_primes(ll lower_limit) {
	set<ll>::iterator it;
	for (it = primes.begin(); it != primes.end(); it++) {
		if (*it >= lower_limit) printf("%lli ", *it);
	}
	printf("\n");
}

void simple_seive(ll limit) {
	bool marked[limit+1];
	memset(marked, true, sizeof(marked));
	for (ll i = 2; i*i <= limit; i++) {
		for (ll j = i*i; j <= limit; j += i) {
			marked[j] = false;
		}
	}
	for (ll i = 2; i <= limit; i++) {
		if (marked[i]) {
			primes.insert(i);
		}
	}
}

void segmented_seive(ll lower_limit, ll upper_limit) {
	ll limit = floor(sqrt(upper_limit)) + 1;
	simple_seive(limit);
	
	ll low = limit;
	ll high = limit*2;

	while (low < upper_limit) {
		if (high > upper_limit) high = upper_limit;
		bool marked[limit+1];
		memset(marked, true, sizeof(marked));
		set<ll>::iterator it;
		for (it = primes.begin(); it != primes.end(); it++) {
			ll loLim = floor(low/(*it)) * (*it);
			if (loLim < low) loLim += (*it);
			for (ll j = loLim; j < high; j += (*it)) {
				marked[j-low] = false;
			}
		}
		for (ll i = low; i < high; i++) {
			if (marked[i - low]) primes.insert(i);
		}
		low += limit;
		high += limit;
	}
}

int main() {
	ll lower_limit, upper_limit;
	cin >> lower_limit >> upper_limit;
	segmented_seive(2, lower_limit - 1);
	segmented_seive(lower_limit, upper_limit);
	print_primes(lower_limit);
}