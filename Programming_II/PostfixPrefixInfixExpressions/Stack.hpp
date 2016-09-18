/*
 * File Name: Stack.hpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: Implements stack class. 
 */


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
void Stack<T>::push(const T& value)
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
void Stack<T>::pop() throw(PVE)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PVE("You entered and invalid postfix string: ");
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
T Stack<T>::peek() const throw(PVE)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PVE("You entered an invalid postfix string: it is missing operands"); 
	}
	else
	{
		return(top->getValue());
	}
}

