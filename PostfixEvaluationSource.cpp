#include "PostfixEvaluationHeader.h";

float evaluate(const string& s) {				//function for evaluating postfix expression
	stack<float> st;							//stack for storing numbers
	string temp;								//string for converting character to float
	int n = s.length();							//getting length of expression
	float i1, i2, res;							//variables for evaluation
	for (int i = 0; i < n; i++) {				//loop for reading every character of string
		temp = s[i];							//storing character to temp string
		if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-') {		//if character is operator
			if (st.empty()) {					//if first character is operand then returning false
				cout << "Wrong Postfix expression!\n";
				return 0;
			}
			i2 = st.top();				//storing element at top to i2
			st.pop();					//popping element
			i1 = st.top();				//storing element at top to i1
			st.pop();					//popping element
			switch (s[i]) {				//checking operator
			case '/': res = i1 / i2; break;			//performing different
			case '*': res = i1 * i2; break;			//operations according
			case '+': res = i1 + i2; break;			//to the
			case '-': res = i1 - i2; break;			//operators
			default: cout << "No operator found!\n";
			}
			st.push(res);				//pushing result back to stack
		}
		else {
			st.push(stof(temp));		//if character is number, converting it to float and pushing to stack
		}
	}
	return (st.top());					//returning the result, which is always at the top
}