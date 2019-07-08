#include <iostream>

using namespace std;

int main(){
	int test_cases, length;
	cin >> test_cases;
	while (test_cases--) {
		cin >> length;
		int min_coin_index = -1;
		double coin_arr[length], coin_sum = 0;
		for (int i = 0; i < length; i++) {
			cin >> coin_arr[i];
			coin_sum += coin_arr[i];
		}
		double mean_intial = coin_sum/double(length);
		for (int i = 0; i < length; i++) {
			double new_mean = (coin_sum - coin_arr[i])/double(length - 1);
			if (new_mean == mean_intial) {
				if (min_coin_index == -1) {
					min_coin_index = i;
				} else if (coin_arr[i] < coin_arr[min_coin_index]) {
					min_coin_index = i;
				}
			}
		}
		if (min_coin_index == -1) printf("Impossible\n");
		else printf("%d\n", min_coin_index+1);
 	}
}