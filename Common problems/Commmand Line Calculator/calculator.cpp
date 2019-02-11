#include <iostream>
#include <string.h>
#include <vector>
#include "expressionHandler.h"

Prefix prefix;

using namespace std;

int main(){
	char expression[100];
	printf("Start doing your calculations\n");
	cin >> expression;
	char *prefixExp = prefix.convertToPrefix(expression);
	printf("%s\n",prefixExp);
}