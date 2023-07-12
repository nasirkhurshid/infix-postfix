#include "InfixToPostfixHeader.h";

int main(int argc,char* argv[])
{
	string s = argv[1];					//storing expression in infix notation to s
	string s2 = toPostfix(argv[1]);		//storing postfix expression to s2 after calling toPostfix()
	cout << "Expression in Infix Notation: " << s << endl << "Expression in Postfix Notation: " << s2 << endl;	//displaying infix and postfix expressions
	return 0;
}