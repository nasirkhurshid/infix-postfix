#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct node {							//structure for implementing stack
	T data;								//variable for storing data
	node<T>* next;						//pointer for linking one element to other
};

template <typename T>
class stack {							//class for implementing stack
private:
	node<T>* topp;						//pointer for keeping record of data at top of the stack
public:
	stack() {
		topp = NULL;					//setting topp=NULL
	}
	~stack() {
		makeempty();					//deleting data stored in stack
	}
	void push(const T& val) {			//function for pushing value into stack
		node<T>* temp;					//temporary pointer for storing value
		temp = new node<T>;				//allocating new memory
		temp->data = val;				//storing value in data variable
		temp->next = topp;				//storing address of previous node in next pointer
		topp = temp;					//storing address of temp into top pointer 
	}
	T top() {							//function for getting data at the top of stack
		return topp->data;
	}
	void pop() {						//function for removing data from stack
		node<T>* temp;					//temporary variable for removing data
		temp = topp;					//storing top pointer's address into temp
		topp = topp->next;				//linking top pointer to previous node
		delete temp;					//deleting node pointed by temp
	}
	bool empty() {						//function for checking whether stack empty or not
		return topp == NULL;			//if NULL returning true
	}
	void makeempty() {					//function for making stack empty
		while (!empty()) {
			pop();						//popping elements while stack is not empty
		}
	}
	bool full() {						//function for checking whether stack full or not
		node<T>* temp;
		temp = new node<T>;				//allocating new memory 
		if (temp == NULL) {
			return true;				//if memory is not allocated returning true
		}
		else {
			delete temp;				//else deleting memory and returning false
			return false;
		}
	}
};
float evaluate(const string&);				//function for evaluating postfix expression