#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int *arr, int l_bound, int r_bound){
	
	if(l_bound < r_bound){
		int mid = (l_bound + r_bound)/2; // use l_bound + (r_bound - l_bound)/2 to avoid overflow
		merge_sort(arr, l_bound, mid);
		merge_sort(arr, mid+1, r_bound);
		merge(arr, l_bound, mid, r_bound);
	}
	return;
}

int main(){
	// base array declaration
	int arr[100], size;

	printf("Enter the size of the array: ");
	cin >> size;

	printf("Enter the elements of the array: ");
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	merge_sort(arr, 0, size-1);

	int i = 0;
	printf("Sorted array:\n");
	while(size--){
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}