/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 04
 * Description: Main file creates a test file for stack to test the stack. Then user is prompted for 
 * numeric input until proper input then the numeric value is reveresed using a stack. The reverese is compared to 
 * the initial input to check if it is a palindrome. Palindrome check is looped until user chooses to
 * quit. 
 */

#include <string>
#include<limits>
#include<stdexcept>
#include<iostream>

#include "Stack.h"
#include "Test_Stack.h"
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"


int main(int argc, char** argv)
{ 
        
	int testSize = std::stoi(argv[1]); //convert from char* to int
        Test_Stack tester(testSize); //create a tester
        tester.runTests(); //run tests

	//Palindrome check
    //uses one stack to hold value
    //pop stack using algorithm to find reverse value
        //another method 
        //create 3 stacks
        //fill first one as normal 
        //fill second then dump into third
        //compare first and third 
	
	//variables 
    Stack<int> reverse; 
    
	int userInput = 0;
	int reverseInput = 0; 
	char quit = 'n'; 	
	
	//This will take in a user input number and reverse the number
	//The reverse will be compared to the original to check if palindrome
	//Loop will continue till user quits
	while(quit == 'n' ||quit == 'N' )//loop till user quits
	{
		std::cout << "Input a number: ";
		std::cin >> userInput; 

		//handle improper input
		while(cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "Improper Input. Input a number: " ; 
			cin >> userInput;
		}
		
		
        
		//check if input is positve, negative, or 0 
		//find reverse of input
		if(userInput >= 0) //non negative input
		{
            reverseInput = userInput; 
			if(userInput == 0)//if input is 0
			{			
				reverseInput = 0; 
			}
			else //if input is not 0
			{					 	
				int multiplier = 1;
                while(reverseInput != 0)//fill stack with each digit of the input
				{	
                    reverse.push(reverseInput%10); //pushes last value in number
                    reverseInput = reverseInput/10; //truncates value by one place
				}//end filling stack
                
                while(!reverse.isEmpty())//pop stack to create the reverse of the initial input
                {
                    reverseInput = (reverseInput + (reverse.peek()*multiplier)); 
                    multiplier *= 10; 
                    reverse.pop();
                }
			}	
		}
		else //negative input
		{
			
			reverseInput = userInput * -1;
            
            int multiplier = 1;
			while(reverseInput != 0)//fill stack with each digit of the input
			{	
                    reverse.push(reverseInput%10); //pushes last value in number
                    reverseInput = reverseInput/10; //truncates value by one place
			}//end filling stack
                
            while(!reverse.isEmpty())//pop stack to create the reverse of the initial input
            {
                    reverseInput = (reverseInput + (reverse.peek()*multiplier)); 
                    multiplier *= 10; 
                    reverse.pop();
            }//end reversing input
			reverseInput = (reverseInput * -1);
		}
		

		//check and print results
		if(userInput == reverseInput)
		{
			std::cout<< userInput << " backwards is " << reverseInput << '\n';
			std::cout<< userInput << " is a palindrome" << '\n' << '\n';
		}
		else
		{
			std::cout<< userInput << " backwards is " << reverseInput << '\n';
			std::cout<< userInput << " is not a palindrome" << '\n' << '\n';
		}

		reverseInput = 0; //reset reverseInput
		
		//Asks user if they wish to continue
		std::cout<<"Do you want to quit? (y/n): ";
		std::cin>>quit;

		//check proper user input
		while(quit != 'n' && quit != 'y' && quit != 'N' && quit != 'Y')		
		{
			std::cout<<"Invalid Input." <<'\n';
			std::cout<<"Do you want to quit? (y/n): ";
			std::cin>>quit;
		}

		std::cout<<'\n';


		
	}
	
	std::cout << "Thanks! Exiting..." << '\n'; 

        return (0);
}

