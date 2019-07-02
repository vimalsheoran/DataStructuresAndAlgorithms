#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t, N;
	cin >> t;
	unsigned long int num_buff;
	for(int i = 0; i < t; i++){
		cin >> N;
		int skills[N];
		for(int j = 0; j < N; j++){
			cin >> num_buff;
			skills[j] = num_buff;
		}
		sort(skills, skills+N);
		int min_diff = -1;
		for(int i = 0; i < N;){
			if(i == N - 1) break;
			int curr = skills[i];
			int next = skills[++i];
			if(min_diff == -1){
				min_diff = next - curr;
			} else {
				int curr_diff = next - curr;
				if(min_diff > curr_diff)
					min_diff = curr_diff;
			}
		}
		printf("%d\n", min_diff);
	}
}