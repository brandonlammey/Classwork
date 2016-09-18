/*
 * File Name: PVE.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 06
 * Description: this class inherits from std::runtime_error. This class will catch basic exceptions and 
 * will take in a message to output if an exception is encountered. 
 */

#ifndef PVE_H
#define PVE_H

#include <stdexcept>
#include <string>

using namespace std;

class PVE : public logic_error
{
public:
   PVE(const string& message = "");
}; // end PVE 
#endif

