#include "expressionHandler.h"
#include "charHandler.h"
#include <string.h>
#include <iostream>

CharHandler charHandler;

char* Prefix::convertToPrefix(char *expression){
	
	int expLength = strlen(expression);

	for(int i = 0; i < expLength; i++){

		if(charHandler.isOperator(expression[i])){
			if (operatorBuffer.empty()){
				operatorBuffer.push(expression[i]);
			}else{
				int precedence = charHandler.checkForPrecedence(
					expression[i],
					operatorBuffer.top()
				);
				if (precedence == 0){
					while(!operatorBuffer.empty()){
						pushToExpBuffer(operatorBuffer.top());
						operatorBuffer.pop();
					}
					operatorBuffer.push(expression[i]);
				}else{
					operatorBuffer.push(expression[i]);
				}
			}
		}else{
			int operand = 0;
			while(i < expLength && 
				!charHandler.isOperator(expression[i])){
				operand = (operand*10) + (expression[i] - '0');
				i++;
			} i--;
			pushToExpBuffer((operand+'0'));
		}
	}

	while(!operatorBuffer.empty()){
		pushToExpBuffer(operatorBuffer.top());
		operatorBuffer.pop();
	}

	return prefixBuffer;
}

int Prefix::evalPrefixedExp(char* prefixExp){
	int prefixExpLen = strlen(prefixExp);

	for(int i = 0; i < prefixExpLen; i++){
		if(charHandler.isOperator(prefixExp[i])){
			char rightOperand = operatorBuffer.top();
			operatorBuffer.pop();
			char leftOperand = operatorBuffer.top();
			operatorBuffer.pop();
			int result = calculateExp(
				prefixExp[i], leftOperand, rightOperand
			);
			operatorBuffer.push(result+'0');
		}else{
			operatorBuffer.push(prefixExp[i]);
		}
	}
	return (operatorBuffer.top()-'0');
}

int Prefix::
calculateExp(char operation, char leftOperand, char rightOperand){
	int leftOpr = leftOperand - '0';
	int rightOpr = rightOperand - '0';
	
	switch(operation){
		case '+':
		return leftOpr+rightOpr;
		break;

		case '-':
		return leftOpr-rightOpr;
		break;

		case '*':
		return leftOpr*rightOpr;
		break;

		case '/':
		return leftOpr/rightOpr;
		break;
	}
}

void Prefix::pushToExpBuffer(char value){
	if(!prefixBuffer[0]){
		prefixBuffer[0] = value;
		activeBufferIndex = 1;
	}else{
		prefixBuffer[activeBufferIndex] = value;
		activeBufferIndex++;
	}
}