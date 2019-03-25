#include <iostream>

using namespace std;

void insertion_sort(int length, int *unsorted_arr){
	if(length == 1){
		printf("%d\n", unsorted_arr[0]);
		return;
	}
	
	int key;
	
	for(int i = 0; i < length; i++){
		
		if(i != length-1){
			key = unsorted_arr[i+1];
		}else{
			key = unsorted_arr[length-1];
		}

		for(int j = i; j >= 0; j--){
			if(key < unsorted_arr[j]){
				unsorted_arr[j+1] = unsorted_arr[j];
				unsorted_arr[j] = key;
			}
		}
	}

	printf("Sorted array: ");
	for(int i = 0; i < length; i++){
		printf("%d ", unsorted_arr[i]);
	}
	printf("\n");

}

int main(){
	int length;
	int *unsorted_arr = new int[100];
	printf("Enter the length of the array: ");
	cin >> length;
	printf("Enter the elements of the array space separated: \n");
	for(int i = 0; i < length; i++){
		cin >> unsorted_arr[i];
	}

	insertion_sort(length, unsorted_arr);
}