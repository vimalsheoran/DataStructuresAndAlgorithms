#include <iostream>

using namespace std;

void solve(int a, int b);

int main(){
	int a, b;
	cin >> a >> b;
	solve(a, b);
}

void solve(int a, int b){
	int diff = a - b;
	if(diff%10 != 9) diff++; else diff--;
	printf("%d\n", diff);
}