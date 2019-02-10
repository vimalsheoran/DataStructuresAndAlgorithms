#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

bool checkForBalanceParans(char *expression){

	int expLen = strlen(expression);
	stack <char> openingBracks, closingBracks;

	for (int i = 0; i < expLen; i++){
		if( expression[i] == '(' ||
			expression[i] == '{' ||
			expression[i] == '['){
			openingBracks.push(expression[i]);
		}
	}

	for (int i = expLen; i > 0; i--){
		if (expression[i] == ')' ||
			expression[i] == '}' ||
			expression[i] == ']'){
			closingBracks.push(expression[i]);
		}
	}

	int numberOfParans = openingBracks.size();

	if(closingBracks.size() != openingBracks.size()){
		printf("debugging\n");
		return false;
	}else{
		for(int i = 0; i <= numberOfParans; i++){
			if(openingBracks.empty() && closingBracks.empty()){
				return true;
			}else{
				if( (openingBracks.top() == '{' && closingBracks.top() == '}') ||
					(openingBracks.top() == '(' && closingBracks.top() == ')') ||
					(openingBracks.top() == '[' && closingBracks.top() == ']')){
					openingBracks.pop(); closingBracks.pop();
				}else{
					printf("debugging\n");
					return false;
				}
			}
		}
	}
}

int main(){
	char inputExpression[100];
	printf("Enter your expression: ");
	cin >> inputExpression;
	bool flag = checkForBalanceParans(inputExpression);
	if(flag){
		printf("The parantheses are balanced\n");	
	}else{
		printf("The parantheses are unbalanced\n");
	}
}