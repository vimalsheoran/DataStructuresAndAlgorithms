#include <iostream>

using namespace std;

void tower_of_hanoi(int n, char from, char to, char aux){
	if(n == 1){
		printf("peg %d moved from %c to %c\n", n, from, to);
		return;
	}
	tower_of_hanoi(n-1, from, aux, to);
	printf("peg %d moved from %c to %c\n", n, from, to);
	tower_of_hanoi(n-1, aux, to, from);
}

int main(){
	int n;
	printf("Enter the number of pegs in the tower: ");
	cin >> n;

	tower_of_hanoi(n, 'A', 'C', 'B');
}