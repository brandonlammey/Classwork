/*
 * File Name: QueueInterface.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Base class of queue. This base class creates a queue with basic functions to check if
 * queue is empty, enqueue nodes rear of queue, remove nodes from front of queue, and peek at the front value 
 * in the queue. In the case of improper method calls, exceptions handled with meaningful outputs.   
 */

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include<iostream>
#include<vector>

#include"PreconditionViolationException.h"

template<typename T>
class QueueInterface
{
	public:
	
	virtual ~QueueInterface() {};

	//returns true if the queue is empty false otherwise
	virtual bool isEmpty() const = 0;

	//Entry added to front of stack with set value
	virtual void enqueue(const T& newEntry) throw (PreconditionViolationException) = 0;

	//assumes the queue is not empty
	//front of queue is removed
	//throws PreconditionViolationException when enqueue is attempted on an empty queue. Does not 
	//return a value in this case.
	virtual void dequeue() throw(PreconditionViolationException) = 0;

	//assumes the queue is not empty
	//returns the value at the front of the queue
	//throws a PreconditionViolationException if queue is empty. Does not return a 
	//value in this case
	virtual T peekFront() const throw(PreconditionViolationException) = 0;
};

#endif
