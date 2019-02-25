#include <iostream>

using namespace std;

int find_factorial(int number){
	if(number == 0)
		return 1;
	if(number == 1)
		return 1;
	return number*find_factorial(number - 1);
}

int main(){
	
	int number, factorial;
	printf("Enter the number for finding factorial: ");
	cin >> number;

	factorial = find_factorial(number);
	printf("%d\n", factorial);
}