#include "expressionHandler.h"
#include "charHandler.h"
#include <string.h>

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
			pushToExpBuffer(expression[i]);
		}
	}

	while(!operatorBuffer.empty()){
		pushToExpBuffer(operatorBuffer.top());
		operatorBuffer.pop();
	}

	return prefixBuffer;
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