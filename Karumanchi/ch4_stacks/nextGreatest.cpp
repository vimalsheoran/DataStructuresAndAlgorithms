#include <iostream>

using namespace std;

void replace_next_great(int *a, int length){
	int next_great = a[0];
	for(int i = 1; i < length; i++){
		if (a[i] > a[i+1] ||
			i == length - 1){
			continue;
		}
		int j = i;
		while(j < length){
			if(a[j] > next_great){
				next_great = a[j];
				break;
			}
			j++;
		}
		a[i] = next_great;
	}

	for(int i = 0; i < length; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	int size;
	printf("Enter the size of the array: ");
	cin >> size;
	int arr[size];

	printf("Enter array elements");
	for(int i = 0; i < size; i++)
		cin >> arr[i];

	replace_next_great(arr, size);
}