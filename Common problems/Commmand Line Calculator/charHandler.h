class CharHandler{
public:
	bool isOperator(char);
	int checkForPrecedence(char, char);
};

extern CharHandler charHandler;