#include "charHandler.h"
#include <iostream>

bool CharHandler::isOperator(char parsedCharacter){
	if (parsedCharacter == '+' ||
		parsedCharacter == '-' ||
		parsedCharacter == '*' ||
		parsedCharacter == '/')
		return true;
	return false;
}

int CharHandler::checkForPrecedence(char oper1, char oper2){
	if ((oper1 == '+' ||
		oper1 == '-') &&
		(oper2 == '*' ||
		oper2 == '/')) return 0;
	return 1;
}