/*
 * File Name: Stack.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Inherits stack interface. Implements all methods from StackInterface. 
 * Uses node class to build the stack of nodes. Any invalid calls returns meaningful error messages. 
 */

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include<iostream>
#include<vector>



//implemetns all methods from stackInterface
template<typename T>
class Stack: public StackInterface<T>
{
	//precondition, postcondition, return, and throws comments in this class
	//use templated node class as building block of the stack

	private:
	int m_size = 0; //size of stack
	Node<T>* top; //top node in stack
	
	public:
	Stack(); // Constructor 
	~Stack(); //Destructor 
	

	//returns true if the stack is empty false otherwise
	bool isEmpty() const;

	//returns the size of the stack
	int size() const;

	//Entry added to top of stack
	void push(const T value);


	//assumes the stack is not empty
	//top of the stack is removed
	//throws PreconditionViolationException when a pop is attempted on an empty stack. Does not 
	//return a value in this case.
	void pop() throw(PreconditionViolationException);

	//assumes the stack is not empty
	//returns the value at the top of the stack
	//throws a PreconditionViolationException is attempted on an empty stack. Does not return a 
	//value in this case
	T peek() const throw(PreconditionViolationException);
	
	//traverses list and prints values in stack
	//void printStack() const;
	
};

#include "Stack.hpp"
#endif
