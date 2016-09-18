/*
 * File Name: Stack.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: Inherits StackInterface. Implements all methods from StackInterface. 
 * Uses node class to build the stack of nodes. Any invalid calls returns meaningful error messages. 
 */

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PVE.h"

#include<iostream>

//implements all methods from StackInterface
template<typename T>
class Stack: public StackInterface<T>
{
	//precondition, postcondition, return, and throws comments in this class
	//templated node class used as building block of the stack

	private:
	int m_size = 0; //size of stack
	Node<T>* top; //top node in stack
	
	public:
	Stack(); // Constructor 
	~Stack(); //Destructor 

	//Checks if stack is empty.
	//returns true if the stack is empty false otherwise
	bool isEmpty() const;

	//returns the size of the stack
	int size() const;

	//Adds a new entry to the top of this stack.
	//If the operation was successful, newEntry is at the top of the stack.
	void push(const T& value);


	//Removes the top of this stack.
	//If the operation was successful, the top of the stack has been removed.
	//throw PVC if the stack is empty when called
	void pop() throw(PVE);

   
	//Returns the top of this stack.
	//return the top of the stack; does not change stack
	//throw PVC if the stack is empty when called
	T peek() const throw(PVE);
	
};

#include "Stack.hpp"
#endif
