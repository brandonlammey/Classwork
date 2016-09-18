/*
 * File Name: DriversLicenseRecord.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 02
 * Description: Implementation of DriversLicenseRecord class.
 */

#include "DriversLicenseRecord.h"

using namespace std; 
 DriversLicenseRecord::DriversLicenseRecord()
{
	lastName = "";
	firstName = "";
	age = 0;
	DLN = 0;
	registered = 'x';
}
//DriversLicenseRecord::DriversLicenseRecord(std::string fName, std::string lName, int a, std::string reg, int d)
//{
	//lastName = lName;
	//firstName = fName;
	//age = a;
	//DLN = d;
//}
 
string  DriversLicenseRecord::getLastName() const
{
	return(lastName);
}
 
string DriversLicenseRecord::getFirstName() const
{
	return(firstName);
}
 
string DriversLicenseRecord::getRegistered() const
{
	if(registered == "Y")
	{
		return("registered to vote");
	}	
	else
	{
		return("not registered to vote");
	}
}
 
int DriversLicenseRecord::getAge() const
{
	return(age);
}
 
int DriversLicenseRecord::getDLN() const
{
	return(DLN);
}

//set methods
void DriversLicenseRecord::setLastName(string l)
{
	lastName = l; 
}
 
void DriversLicenseRecord::setFirstName(string f)
{
	firstName = f;
}
 
void DriversLicenseRecord::setRegistered(string r)
{
	registered = r;
}
 
void DriversLicenseRecord::setAge(int a)
{
	age = a;
}
 
void DriversLicenseRecord::setDLN(int d)
{
	DLN = d; 
}
 


