#include <iostream>
#include <vector>

using namespace std;

int a[9] = {6, 2, 3, 4, 5, 1, 2, 3, 4};

void calculate_water_logged(int i, int j, int &total, vector<int>submerged) {
	int k = a[i] < a[j] ? i : j;
	vector<int>::iterator it = submerged.begin();
	for (; it != submerged.end(); it++) {
		total += a[k] - a[*it];
	}
}

int main() {
	
	vector<int>submerged;
	int total_water_logged = 0;

	for (int i = 0; i < 7; i++) {
		if (a[i] > a[i+1]) {
			int j = i + 1;
			while (a[j] < a[i] && a[j] < a[j+1] && j < 9) {
				submerged.push_back(j);
				j++;
			}
			calculate_water_logged(i, j, total_water_logged, submerged);
			submerged.clear();
			i = j-1;
		}
	}

	printf("%d\n", total_water_logged);
}