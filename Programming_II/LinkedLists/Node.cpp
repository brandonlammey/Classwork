/*
 * File Name: Node.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Quarantine
 * Description: Implementation of Node class. 
 */

#include"Node.h"

Node::Node()
{
	//constructor initilizes each node to a value of 0 and the pointer to null	
	m_value = 0;
	m_next = nullptr; 
}

void Node::setValue(int val)
{
	m_value = val;
}

int Node::getValue() const
{
	return(m_value);
}

void Node::setNext(Node* prev)
{
	m_next = prev; 
}

Node* Node::getNext() const
{
	return(m_next);
}
