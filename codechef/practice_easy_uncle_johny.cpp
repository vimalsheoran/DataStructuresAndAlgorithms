// Gotta figure out why this shit wouldn't run with binary search

#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int start_index, int end_index, int query, int *arr){
	int mid = (start_index + end_index) / 2;
	if(arr[mid] == query) return mid;
	if(arr[mid] > query) return binary_search(start_index, mid, query, arr);
	if(arr[mid] < query) return binary_search(mid, end_index, query, arr);
}

int main(){
	int t, N, prev_index, search;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> N;
		int playlist[N];
		for(int j = 0; j < N; j++){
			cin >> playlist[j];
		}
		cin >> prev_index;
		int search = playlist[prev_index - 1];
		sort(playlist, playlist+N);
		for(int k = 0; k < N; k++){
			if(playlist[k] == search) printf("%d\n", k+1);
		}
		// int curr_index = binary_search(0, N - 1, search, playlist);
		// printf("%d\n", curr_index+1);
	}
}
