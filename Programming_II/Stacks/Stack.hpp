/*
 * File Name: Stack.hpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 04
 * Description: Implements stack class. 
 */

//#include "StackInterface.h"
//#include "Node.h"
//#include "PreconditionViolationException.h"
//#include <iostream>

template<typename T>
Stack<T>::Stack()
{
	m_size = 0;
	top = nullptr;//initialize top pointer to null empty stack  
}

template<typename T>
Stack<T>::~Stack()
{
	while(m_size!=0)
	{
		Node<T>* tempNode = top->getNext(); //create temp pointer to next node 
		delete(top);//delete top node
		top = tempNode; //set top pointer to next node 		 

		m_size--;//decrease size of stack
	}

}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template<typename T>
int Stack<T>::size() const
{
	return(m_size);
}

template<typename T>
void Stack<T>::push(const T value)
{
	//create new node and set value to passed in parameter	
	Node<T>* newNode = new Node<T>();
	newNode->setValue(value);
	
	//set new node to point to what top is pointing to
	//set top to new node
	newNode->setNext(top);
	top = newNode; 

	//increment size 
	m_size++; 
	
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PreconditionViolationException("Pop attempted on an empty stack");
	}
	else
	{
		if(top->getNext() == nullptr)//case when only one node in stack
		{
			delete(top);//delete top node
			top = nullptr;//avoid dangling pointer
			m_size--;//decrease size of stack
		}
		else
		{		
			Node<T>* tempNode = top->getNext(); //create temp pointer to next node 
			delete(top);//delete top node
			top = tempNode; //set top pointer to next node 		 

			m_size--;//decrease size of stack 
		}	
	}
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PreconditionViolationException("Peek attempted on empty stack");
	}
	else
	{
		return(top->getValue());
	}
}

template<typename T>
std::vector<T> Stack<T>::toVector() const
{
 
	std::vector<T> listContents;//creates new vector to hold values
	

	if(top != nullptr)
	{
		Node<T>* tempNode = top; 
				
		for(int i=0; i<m_size; i++)//traverse list and input values into vector
		{
			listContents.push_back(tempNode->getValue());
			tempNode = tempNode->getNext(); 
		}
		
	}

	return(listContents); 
}

template <typename T>
void Stack<T>::printStack() const
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

