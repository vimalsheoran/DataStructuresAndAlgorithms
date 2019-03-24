// To find the length of the longest common substring
// Using dynamic programming approach

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

void subs_length(char *s1, char *s2){

	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	int result = 0;
	int sub_struc[s1_len+1][s2_len+1];

	for(int i = 0; i <= strlen(s1); i++){
		for(int j = 0; j <= strlen(s2); j++){
		
			if(i == 0 || j == 0){
				sub_struc[i][j] = 0;
			}
			else if(s1[i] == s2[j]){
				sub_struc[i][j] = sub_struc[i-1][j-1] + 1;
				result = max(result, sub_struc[i][j]);
			}
			else{
				sub_struc[i][j] = max(sub_struc[i-1][j],
					sub_struc[i][j-1]);
			}
		}
	}
	
	printf("The length of the longest substring is: %d\n", result);
	return;
}

int main(){
	char s1[100], s2[100];
	printf("Enter two strings\n");
	scanf("%s", s1);
	scanf("%s", s2);
	subs_length(s1, s2);
}