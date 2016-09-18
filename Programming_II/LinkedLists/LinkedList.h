/*
 * File Name: LinkedList.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 03
 * Description: This linked list contains two variables. The initial pointer to the first node and the
 * size of the list. The linked list contains methods to check if the list is empty, check size of list, 
 * search for a specific value in held by the nodes, print list, add, and remove nodes. 
 */



#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"
#include<iostream>
#include<vector>


class LinkedList
{
	private:
		//private memory variables 		
		Node* m_front;
		int m_size; 
		
	public: 
		//constructor and deconstructor 		
		LinkedList();
		~LinkedList();
		
		//returns true if list is empty
		//returns false otherwise
		bool isEmpty() const; 
		
		//returns size of the linked list
		int size() const; 

		//returns true if the value exists in any node
		//returns false otherwise
		bool search(int value) const; 

		//prints the list to the console
		//if list is empty print empty string 
		void printList() const;

		//adds 1 new node to back or front of the list
		//increments size
		void addBack(int value);
		void addFront(int value); 
	
		//removes 1 node to back or front of the list
		//decrements size
		bool removeBack();
		bool removeFront(); 

		//creates new vector 
		//copy contents of list into vector
		//returns a standard vector with the contents of the list inside
		//used by test class to varify contents of list 
		std::vector<int> toVector() const;
};

#endif
