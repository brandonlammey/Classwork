/*
 * File Name: StackInterface.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: Base class of stack. This base class creates a stack with basic functions to check if
 * stack is empty, push nodes into stack, remove nodes from top of stack, and peek at the top value 
 * instack. In the case of improper method calls, exceptions handled with meaningful outputs.   
 */


#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H


#include<iostream>
#include "PVE.h"

template<class T>
class StackInterface
{
public:
	
	virtual ~StackInterface() {};

	//Checks if stack is empty.
	//returns true if the stack is empty false otherwise
	virtual bool isEmpty() const = 0;
   
	//Adds a new entry to the top of this stack.
	//If the operation was successful, newEntry is at the top of the stack.
	//throw PVE if no memory available for the new item
	virtual void push(const T& newEntry) = 0;
   
	//Removes the top of this stack.
	//If the operation was successful, the top of the stack has been removed.
	//throw PVE if the stack is empty when called
	virtual void pop() throw (PVE) = 0;
   
	//Returns the top of this stack.
	//return the top of the stack; does not change stack
	//throw PVE if the stack is empty when called
	virtual T peek() const throw (PVE) = 0;

}; // end StackInterface
#endif

