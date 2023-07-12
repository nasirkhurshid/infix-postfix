#include "InfixToPostfixHeader.h";

int precedence(char ch) {						//function for getting precedence of operators
	switch (ch) {
	case '/': case '*': return 2;
	case '+': case '-': return 1;
	default: return 0;
	}
}

string toPostfix(const string& s) {			//function for converting infix expression to postfix
	string str;								//str for output
	str = "";
	int n = s.length();						//getting length of infix expression
	char ch;								//character for getting element from stack
	stack<char> st;							//stack for storing operators
	for (int i = 0; i < n; i++) {			//loop for reading every character of string
		if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-') {			//if element is operator
			if (st.empty() || precedence(s[i]) > precedence(st.top()) || st.top() == '(') {
				st.push(s[i]);			//if stack is empty or top element of stack is ( or precedence of operator in string is greater than operator in stack then pushing character into stack
			}
			else if (precedence(s[i]) <= precedence(st.top())) {		//if precedence of operator is string is less than or equal to operator in stack
				while (!st.empty()) {
					while (!precedence(s[i]) > precedence(st.top())) {
						ch = st.top();					//while precedence of operator in string is not greater than operator in stack
						st.pop();						//then popping elements from stack until precedence of operator in string becomes greater than operator in stack
						str = str + ch;					//moving operator to output
						if (ch == '(') {				//if element at stack's top is (
							break;						//then breaking loop
						}
					}
					if (precedence(s[i]) > precedence(st.top())) {
						break;						//if  precedence of operator in string becomes greater than operator in stack then breaking
					}
					ch = st.top();
					st.pop();				//popping elements from stack until its empty
					str = str + ch;			//moving elements to output
				}
				st.push(s[i]);				//pushing character of string to stack
			}
		}
		else if (s[i] == '(') {
			st.push(s[i]);			//if character of string is ( then pushing it into stack
		}
		else if (s[i] == ')') {				//if character of string is ) then
			while (st.top() != '(') {		//popping elements from stack
				ch = st.top();				//until ( is triggered and
				st.pop();					//moving elements to
				str += ch;					//the out put
			}
			st.pop();						//popping ( from stack
		}
		else {
			str = str + s[i];				//if character is number, moving it to output
		}
	}
	while (!st.empty()) {				//removing all elements from
		ch = st.top();					//stack and moving
		st.pop();						//them to
		str += ch;						//the output
	}
	return str;							//returning postfix expression
}