/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: Program will prompt for and read a series of strings from the console and test whether
 * each represents a valid postfix expression. Any invlaid character detected during parsing will reject
 * the string as syntactically invalid and throw a meaningful output. Any invalid postfix expression 
 * will throw meaningful exception message. Program will continue prompting for strings until the user
 * enters a single '#' at the prompt. 
 */


#include<string>
#include<limits>
#include<stdexcept>
#include<iostream>
#include<cctype>

#include "Stack.h"
#include "StackInterface.h"
#include "Node.h"
#include "PVE.h"

int main(int argc, char** argv)
{

	std::string input = "";
	std::string character = "";

	std::cout << "Enter a string: ";
	std::cin >> input;
	bool invalid = false; 

	Stack<std::string> container;//used to hold each element of expression 
		
	
	//Prompts for input
	//Operands: push each operand into stack
	//Operator: pop when operator reached
	//Evaluate: expression will be created with two operators and operand within parenthesis 
	//Expression: push expression into stack
	//Continue: Process till expression is converted completely 
		//Lack of operators or operands will throw and handle exception
		//Invalid characters will throw and handle exception
	//Loop: continue prompting for strings until the user enters a single '#' at the prompt.
	while(input != "#")
	{
		//read through string character by character
		//either push operand or peek and pop top two elements and put between operator then push expression		
		for(unsigned int i=0; i<input.length(); i++)
		{
			
			if(isalpha(input.at(i)))
			{
				character = input.at(i);
				container.push(character);				
			}			
			else if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/')
			{
				std::string temp1 = "";
				std::string temp2 = "";
				std::string tempFinal = "";
				
				//determines if there are enough operands(xyz...)
				try
				{
					temp1 = container.peek();
					container.pop();
					temp2 = container.peek();
					container.pop();
					tempFinal = "(" + temp2 + input.at(i) + temp1 + ")";
				
					container.push(tempFinal);
				}catch(PVE e)
				{
					break;//exit for loop too many operators 
				}
				
			}
			else//if string character is not a valid operator or operand
			{
				std::cout << "You entered an invalid postfix string: it contains the illegal character ";
				std::cout << "'" << input.at(i) << "'" <<'\n';
				invalid = true;//invalid input exists
				break; 
			}
		
		}//exit for loop stack operations 
		
		
		//determine if result is valid
		//invalid results: not enough operators, not enough operands, number input
		//invalid results determined by try catch and handled 
		if(invalid == false)//no invalid characters
		{		
			try
			{
				input = container.peek(); //set initial input to converted expression 			
				container.pop(); //remove converted expression 

			
				try// if pop allowed not enough operators(+-*/)
				{
					container.pop();
					std::cout << "You entered an invalid postfix string: it is missing one or more operators" << '\n';
				}
				catch(PVE e)
				{
					//if pop does not work stack is empty
					//not missing operators or operands
					std::cout << "You entered a valid postfix string. The equivalent infix: ";
					std::cout << input << '\n'; 
				}

			
			}
			catch(PVE e)//nothing in stack not enough operands
			{
				std::cout << e.what()<< '\n'; 
			
			}
		}
		
		//empty stack for next expression
		while(!container.isEmpty())
		{
			container.pop();
		}	
		
		
		
		//prompt for new input
		input = "";		
		std::cout << "Enter a string: ";
		std::cin >> input;
		invalid = false;	
	
	}//end while loop

	return(0);
}
