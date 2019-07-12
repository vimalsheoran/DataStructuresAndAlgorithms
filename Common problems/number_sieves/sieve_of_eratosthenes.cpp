#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	printf("Welcome to Sieve of Eratosthenes.\n");
	printf("Enter the upper limit for prime number finding: ");
	cin >> n;
	int marked[n];
	for(int i = 0; i < n; i++) marked[i] = true;
	vector <int> primes;
	for(int i = 2; i < n; i++){
		if(marked[i-1] == true){
			primes.push_back(i);
			for(int j = i; j*i < n; j++){
				marked[i*j - 1] = false;
			}
		}
	}
	vector<int>::iterator it = primes.begin();
	for(; it != primes.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
}