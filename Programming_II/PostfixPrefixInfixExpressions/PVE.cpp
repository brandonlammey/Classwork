/*
 * File Name: PreconditionViolationException.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: Implemetation of PVE class
 */

#include "PVE.h"  

PVE::PVE(const string& message): logic_error(message)//message will be defined in throw
{
}  // end constructor

// End of implementation file.


