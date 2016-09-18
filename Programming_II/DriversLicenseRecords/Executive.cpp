/*
 * File Name: Executive.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 02
 * Description: Implementation of DriversLicenseRecord class. 
 */

#include "Executive.h"
#include "DriversLicenseRecord.h"
#include<limits>

using namespace std; 
 
Executive::Executive(char* filename)
{
	//opens external file
	std::ifstream inp(filename); 
	
	//reads in size for array
	inp >> n; 
	
	//DriversLicenseRecord* records;
	records = new DriversLicenseRecord[n];

	string tempFirst;
	string tempLast;
	int tempAge;
	string tempReg;
	int tempDLN; 

	for(int i=0; i<n; i++)
	{
		
		inp >> tempFirst;
		records[i].setFirstName(tempFirst);
		inp >> tempLast;
		records[i].setLastName(tempLast);
		inp >> tempAge; 
		records[i].setAge(tempAge);
		inp >> tempReg;
		records[i].setRegistered(tempReg);
		inp >> tempDLN; 
		records[i].setDLN(tempDLN);

		//records[i] = new DriversLicenseRecord(tempFirst, tempLast, tempAge, tempReg, tempDLN);
	}                                  
	
}

Executive::~Executive()
{
	delete[] records; 
	records = nullptr;//if this gives errors delete it
}

void Executive::run()
{
	int choice = 0;
	bool findRecord; 
	std::string name;
	int min = 0;
	int max = 0;
    
	while(choice != 4)
	{
		//sets to false at the beginning of each query
		findRecord = false;  
 
		std::cout <<  "1: Query last name" << endl 
		<< "2: Query age range" << endl 
		<< "3: Query registered voters" << endl 
		<< "4: Quit" << endl;
 		
		
		cin >> choice;
 		
		//Ensure proper user input
		while(cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "Improper Input Try Again: " ; 
			cin >> choice;

		}
		
 		//if statements to choose how to query or
		if(choice==1)
		{
			std::cout <<  "Enter last name: ";
			std::cin >> name;
			
			for(int i=0; i<n; i++)
			{
				if (records[i].getLastName() == name) 
				{
					std::cout << "Record: "<< records[i].getFirstName()
					<< " " << records[i].getLastName() << "; " 
					<< "age " <<  records[i].getAge() << "; "
					<< records[i].getRegistered() << "; license number: "
					<< records[i].getDLN() << '\n'; 
					findRecord = true;
				}
			}
			if (!findRecord)  
			{
				std::cout << "No matching records!" << endl;
			}
			
		}
		else if(choice==2)
		{
			std::cout <<  "Enter age range" << endl 
			<< "min: ";
			std::cin >> min;
			
			//Ensure proper user input
			while(cin.fail())
			{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "Improper Input. Enter minimum age: " ; 
			cin >> name;

			}

			std::cout <<  "max: ";
			std::cin >> max;

			//Ensure proper user input
 			while(cin.fail())
			{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "Improper Input. Enter maximum age: " ; 
			cin >> name;

			}

			for(int i=0; i<n; i++)
			{
				if (records[i].getAge() >= min && records[i].getAge() <= max) 
				{
					std::cout << "Record: "<< records[i].getFirstName()
					<< " " << records[i].getLastName() << "; " 
					<< "age " <<  records[i].getAge() << "; "
					<< records[i].getRegistered() << "; license number: "
					<< records[i].getDLN() << '\n'; 
					findRecord = true;
				}
			}
			if (!findRecord)  
			{
				std::cout << "No matching records!" << endl;
			}
		}
		else if(choice==3)
		{
			
			for(int i=0; i<n; i++)
			{
				if (records[i].getRegistered() == "registered to vote") 
				{
					std::cout << "Record: "<< records[i].getFirstName()
					<< " " << records[i].getLastName() << "; " 
					<< "age " <<  records[i].getAge() << "; "
					<< records[i].getRegistered() << "; license number: "
					<< records[i].getDLN() << '\n'; 
					findRecord = true;
				}
			}
			if (!findRecord)  
			{
				std::cout << "No matching records!" << endl;
			}
		}
		else
		{
			cout << "Invalid Input.";
		}
		
		cout << '\n' << '\n';  
	}
		
	std::cout << "Thanks for using our system!" << '\n' << "Bye" << '\n'; 
	
}


