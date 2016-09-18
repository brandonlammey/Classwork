/*
 * File Name: StackInterface.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Base class of stack. This base class creates a stack with basic functions to check if
 * stack is empty, push nodes into stack, remove nodes from top of stack, and peek at the top value 
 * instack. In the case of improper method calls, exceptions handled with meaningful outputs.   
 */

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include<iostream>
#include<vector>

#include"PreconditionViolationException.h"

template<typename T>
class StackInterface
{
	public:
	
	virtual ~StackInterface() {};

	//returns true if the stack is empty false otherwise
	virtual bool isEmpty() const = 0;

	//returns the size of the stack
	virtual int size() const = 0;

	//Entry added to top of stack with set value
	virtual void push(const T value) = 0;

	//assumes the stack is not empty
	//top of the stack is removed
	//throws PreconditionViolationException when a pop is attempted on an empty stack. Does not 
	//return a value in this case.
	virtual void pop() throw(PreconditionViolationException) = 0;

	//assumes the stack is not empty
	//returns the value at the top of the stack
	//throws a PreconditionViolationException is attempted on an empty stack. Does not return a 
	//value in this case
	virtual T peek() const throw(PreconditionViolationException) = 0;
};

#endif
