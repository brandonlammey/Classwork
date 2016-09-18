/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Queue and Stack objects will be used to store customers either in a queue for regular
 * customers or stack for VIP's. VIP's will be served first as they come and when stack is empty then 
 * regular customers will be served. 
 */

#include<string>
#include<limits>
#include<stdexcept>
#include<iostream>
#include<fstream>

#include "Stack.h"
#include "Queue.h"
#include "StackInterface.h"
#include "QueueInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"

int main(int argc, char** argv)
{ 

	string input = "";
	std::string fileInput = argv[1];

	std::ifstream readFile; 
	readFile.open(fileInput);

	readFile >> input; //read in first command / name

	Stack<string> vip; //a stack created for VIP's 
	Queue<string> customer; //a queue created for customers
	
	while(!readFile.eof())
	{
	
		//"done" command request will use try catch to determine if stack or queue is empty
		if(input == "done")//person being served currently is complete and dequeued or popped 
		{
		
			try//attempt to complete vip (pop) 
			{
				std::cout << vip.peek() << " is done; ";
				vip.pop(); //attempt VIP completion 

				try //try to start next vip
				{
					std::cout << "Lydia starts serving " << vip.peek() << '\n';
				}
				catch(PreconditionViolationException e)//vip stack empty try to start customer
				{
					try
					{
						std::cout << "Lydia starts serving " << customer.peekFront() << '\n';
					}
					catch(PreconditionViolationException e)//no one left waiting in stack or queue
					{
						std::cout << e.what(); //prints out exception message						
					}			
				}


			}
			catch(PreconditionViolationException e)//vip stack empty attempt customer completion
			{
				try //attempt to complete customer (dequeue)
				{			
					std::cout << customer.peekFront() << " is done; ";
					customer.dequeue(); //attempt customer completion
				
					try //try to start next customer
					{
						std::cout << "Lydia starts serving " << customer.peekFront() << '\n';
					}
					catch(PreconditionViolationException e)//no one left waiting in stack or queue
					{
						std::cout << e.what(); //prints out exception message				
					}
				}
				catch(PreconditionViolationException e)//no vips, no customers 
				{
					std::cout << "No one is currently being served; No one is waiting; Lydia is resting..." << '\n';			
				}
			}
	

		}
		else if(input == "show")//show current state of simulation who is being served and who is waiting
		{
			if(vip.isEmpty() && customer.isEmpty())//empty stack and queue 
			{
				std::cout << "*** No customers waiting or being served; Lydia is curently resting ***" << '\n';  
			}
			else
			{
				if(vip.isEmpty())//no VIP's in stack  
				{
					std::cout << "***No VIP's are waiting or being served; " << customer.peekFront() << " is currently being served ***" << '\n'; 
				}
				else if(customer.isEmpty())//no one in queue
				{
					std::cout << "*** " << vip.peek() << " is currently being served; no one currently waiting in queue ***" << '\n';
				}
				else//stack and queue not empty
				{
					std::cout << "*** " << vip.peek() << " is currently being served; " << customer.peekFront() << " is waiting at the front of the queue ***" << '\n';
				}
			}

		}
		else//input is a customer 
		{
			//handle VIP's and regular customers
			if( input == "VIP0" || input == "VIP1" || input == "VIP2"|| input == "VIP3"|| input == "VIP4"|| input == "VIP5"|| input == "VIP6"|| input == "VIP7"|| input == "VIP8"|| input == "VIP9")//VIP
			{
						
				if(vip.isEmpty())//no current vips 
				{
					vip.push(input);				
					if(customer.isEmpty())//no regular customers currently being served
					{
						std::cout << vip.peek() << " arrives and starts being served" << '\n';  
					}
					else //suspend current customer being served
					{
						std::cout << vip.peek() << " arrives; " << customer.peekFront() << " is suspended; Lydia starts serving " << vip.peek() << " immediately" << '\n';
					}
				}			
				else if(input > vip.peek())//vip is more important
				{
					std::cout << input << " arrives; " << vip.peek() << " is suspended; Lydia starts serving " << input << " immediately" << '\n';
					vip.push(input);
				}
				else//vip is less important and leaves
				{
					std::cout << input << " arrives and see's " << vip.peek() << " being served; " << input << " immediately leaves" << '\n'; 
				}
			}
			else//customer
			{
						
				std::cout << input << " arrives and is added to queue; ";
	
				if(vip.isEmpty() && customer.isEmpty())//empty queue and stack start serving
				{
					customer.enqueue(input); //adds customer to queue 
					std::cout << "Lydia starts serving " << customer.peekFront() << " immediately" << '\n';
				} 
				else//currently serving another
				{
					customer.enqueue(input);//adds customer to queue
					std::cout<< '\n';
				}
			}

		}
	
		readFile >> input; //read in next command / name

	}

	while(!vip.isEmpty() || !customer.isEmpty())//pop and dequeue till all are served
	{
		try//attempt to complete vip (pop) 
			{
				std::cout << vip.peek() << " is done; ";
				vip.pop(); //attempt VIP completion 

				try //try to start next vip
				{
					std::cout << "Lydia starts serving " << vip.peek() << '\n';
				}
				catch(PreconditionViolationException e)//vip stack empty try to start customer
				{
					try
					{
						std::cout << "Lydia starts serving " << customer.peekFront() << '\n';
					}
					catch(PreconditionViolationException e)//no one left waiting in stack or queue
					{
						std::cout << e.what(); //prints out exception message						
					}			
				}


			}
			catch(PreconditionViolationException e)//vip stack empty attempt customer completion
			{
				try //attempt to complete customer (dequeue)
				{			
					std::cout << customer.peekFront() << " is done; ";
					customer.dequeue(); //attempt customer completion
				
					try //try to start next customer
					{
						std::cout << "Lydia starts serving " << customer.peekFront() << '\n';
					}
					catch(PreconditionViolationException e)//no one left waiting in stack or queue
					{
						std::cout << e.what(); //prints out exception message				
					}
				}
				catch(PreconditionViolationException e)//no vips, no customers 
				{
					std::cout << "No one is currently being served; No one is waiting; Lydia is resting..." << '\n';			
				}
			}
	}
	
	std::cout<< '\n';
	return(0); 
}
