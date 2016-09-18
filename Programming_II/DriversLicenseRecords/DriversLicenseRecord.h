/*
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 02
 * Description: This class will create a Drivers License Object which will hold the
 * first name, last name, age, registration, and Dl number for an individual 
 */

#ifndef DRIVERSLICENSERECORD_H
#define DRIVERSLICENSERECORD_H

#include<string>

using namespace std; 

class DriversLicenseRecord
{
	private:
		//member variables for each record		
		std::string lastName;
		std::string firstName;
		int age; 
		std::string registered; 
		int DLN; 

	public:
		//Constructor
		//takes in values read in from executive
		//Stores information into individual records 		

		//DriversLicenseRecord(std::string fName, std::string lName, int a, std::string reg, int d);
		DriversLicenseRecord();
		//get methods to return information from the record
		std::string getLastName() const;
		std::string getFirstName() const;
		int getAge() const;
		std::string getRegistered() const;
		int getDLN() const;

		//set methods
		void setLastName(std::string l);
		void setFirstName(std::string f);
		void setAge(int a);
		void setRegistered(std::string r);
		void setDLN(int d);
		
};

#endif



