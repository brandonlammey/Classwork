/*
 * File Name: Executive.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 02
 * Description: This class will take into a constructor a text file of records. 
 * The constructor will read the file and create a dynamically allocated array 
 * of objects with each object being a drivers license record that the executive
 * class will write into. 
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "DriversLicenseRecord.h"
#include<iostream>
#include<fstream>

using namespace std;

class Executive
{
	private:
		int n;
		DriversLicenseRecord* records;
		
	public: 
		//Executive Contructor takes in file from argv[1]
		//open file
		//read number of records, 
		//dynamically allocate an array of DriversLicenseRecords to correct size
		//coordinate the reading of the data into the array
		Executive(char* filename);
		~Executive();
		
		//loops through 4 options for user to choose from 
		//print all instances that match user input: last name, age range, or registration
		//quit
		void run();

		void searchLast(string lastName);
		void searchAge(int age);
		void searchRegistered(string registered);

};


#endif
