#include "PostfixEvaluationHeader.h";

int main(int argc, char* argv[])
{
	string s = argv[1];					//storing expression into string
	float result = evaluate(argv[1]);			//returning result of expression
	cout << "Expression in Postix Notation: " << s << endl << "Expression's Evaluation: " << result << endl;	//displaying expression and its result
	return 0;
}