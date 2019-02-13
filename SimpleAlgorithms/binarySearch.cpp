// A simple demonstration of binary search on a sorted array

#include <iostream>

using namespace std;

int sampleArray[] = {8, 10, 15, 20, 37, 45, 60, 120, 137, 200};
int startIndex = 0;
int endIndex = 9;
int median = endIndex/2;

bool search(int searchQuery){
	if(searchQuery == sampleArray[median]){
		return true;
	}else if(median == 0){
		return false;
	}else if(searchQuery > sampleArray[median]){
		startIndex = median;
		median = startIndex + (endIndex - startIndex)/2;
		search(searchQuery);
	}else if(searchQuery < sampleArray[median]){
		endIndex = median;
		median = (endIndex - startIndex)/2;
		search(searchQuery);
	}else{
		return false;
	}
}

int main(){
	
	int searchQuery;

	printf("Welcome to this simple number search\n");
	printf("Enter a number you wish to search for: ");
	cin >> searchQuery;

	bool result = search(searchQuery);
	if(result){
		printf("Record exists!\n");
	}else{
		printf("No match found\n");
	}
}