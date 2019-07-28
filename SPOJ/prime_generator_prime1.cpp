#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;

vector<ll>primes;
vector<ll>final_primes;

void print_primes() {
	vector<ll>::iterator it = final_primes.begin();
	while (it != final_primes.end()) {
		printf("%lli\n", *it);
		it++;
	}
	printf("\n");
}

void init_base_primes() {
	bool marked[32001];
	memset(marked, true, sizeof(marked));
	for (int i = 2; i*i <= 32000; i++) {
		if (marked[i]) {
			for (int j = i*i; j <= 32000; j += i) {
				marked[j] = false;
			}
		}
	}
	for (int i = 2; i <= 32000; i++) {
		if(marked[i]) primes.push_back(i);
	}
}

void find_primes(ll n, ll m) {
	vector<ll>::iterator it = primes.begin();
	ll cap = floor(sqrt(m)) + 1;
	bool marked[m - n + 2];
	memset(marked, true, sizeof(marked));
	for (; it != primes.end(); it++) {
		if (*it > cap) break;
		ll lowLim = floor(n/(*it)) * (*it);
		if (lowLim < n) lowLim += (*it);
		if (lowLim == *it) lowLim += *it;
		for (ll j = lowLim; j <= m; j += *it) {
			marked[j - n] = false;
		}
	}
	for (ll i = n; i <= m; i++) {
		if (marked[i-n]) final_primes.push_back(i); 
	}

}

int main() {
	int t; ll m, n;
	cin >> t;
	init_base_primes();
	while (t--) {
		cin >> n;
		cin >> m;
		if(n == 1 || n == 0) n = 2;
		find_primes(n, m);
		print_primes();
		final_primes.clear();
	}
}