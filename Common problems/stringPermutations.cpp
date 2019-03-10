// Program to print all the possible permutations of a string

#include <iostream>
#include <cstring>

using namespace std;

int swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *a, int l, int r){
	if(l == r){
		printf("%s\n", a);
	}else{
		for(int i = l; i <= r; i++){
			swap(a+l, a+i);
			permute(a, l+1, r);
			swap(a+l, a+i);
		}
	}
}

int main(){
	char str[] = "ABC";
	int l = strlen(str);
	permute(str, 0, l-1);
}