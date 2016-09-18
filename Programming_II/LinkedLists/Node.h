/*
 * File Name: Node.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 03
 * Description: This class will create a node with a pointer initially set to null and a value within
 * the node. Corresponding get and set methods are included. 
 */

#ifndef NODE
#define NODE

class Node
{
	private:
	int m_value;	//value in the node 
	Node* m_next;	//pointer to another node

	public:
	//constructor for each node includes a value and a pointer to another node	
	Node();

	//set and get methods for the value within the node
	void setValue(int val);
	int getValue() const;
	
	//set and get methods for the pointer of each node 
	void setNext(Node* prev);
	Node* getNext() const;
};

#endif
