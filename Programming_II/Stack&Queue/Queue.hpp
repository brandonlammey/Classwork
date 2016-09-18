/*
 * File Name: Queue.hpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Implements Queue class. 
 */

//#include "QueueInterface.h"
//#include "Node.h"
//#include "PreconditionViolationException.h"
//#include <iostream>

template<typename T>
Queue<T>::Queue()
{
	front = nullptr;//initialize front pointer to null empty stack 
	rear = nullptr;//initialize rear pointer to null empty stack 
}

template<typename T>
Queue<T>::~Queue()
{
	while(front!= nullptr)
	{
		Node<T>* tempNode = front->getNext(); //create temp pointer to next node 
		delete(front);//delete front node
		front = tempNode; //set top pointer to next node 		 
	}
	rear = front = nullptr; 

}

template<typename T>
bool Queue<T>::isEmpty() const
{
	if(front == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template<typename T>
void Queue<T>::enqueue(const T& newEntry) throw (PreconditionViolationException) 
{
	
	//create new node and set value to passed in parameter	
	Node<T>* newNode = new Node<T>();
	newNode->setValue(newEntry);
	
	if(newNode == nullptr)
	{
		throw PreconditionViolationException("Heap Memory Full");
	}
	else
	{
		if(front == nullptr)
		{	 	
			front = newNode;
			rear = newNode; 
		}		
		else
		{		
			rear->setNext(newNode);
			rear = newNode;

		}
	}
}

template<typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(front == nullptr)//check to see if queue is empty and handle error
	{
		throw PreconditionViolationException("Empty queue");
	}
	else
	{

		Node<T>* tempNode = front->getNext(); //create temp pointer to next node 
		delete(front);//delete top node
		front = tempNode; //set top pointer to next node 


		if(front == nullptr)// last item removed 
		{		
			rear = nullptr;
		}


	}	
	
}

template<typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
	if(front == nullptr)//check to see if queue is empty and handle error
	{
		throw PreconditionViolationException("no one is currently waiting; Lydia rests...");
	}
	else
	{
		return(front->getValue());
	}
}

/*
template <typename T>
void Queue<T>::printQueue() const
{
	//enters if statement as long as the Stack is not empty
	if(m_size == 0)
	{
		std::cout<<"Empty Stack"<<'\n';
	}
	else	
	{	Node<T>* tempNode = top;

		//Traverse stack to print values 
		while(tempNode != nullptr)
		{
			std::cout << tempNode->getValue();
			tempNode = tempNode->getNext();
		}
	}
}

*/

