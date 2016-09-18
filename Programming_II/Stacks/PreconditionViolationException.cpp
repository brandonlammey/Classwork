/*
 * File Name: PreconditionViolationException.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 04
 * Description: Implemetation of PreconditionViolationException class
 */

#include "PreconditionViolationException.h"
//class PreconditionViolationException: public std::runtime_error

PreconditionViolationException::PreconditionViolationException(const char* message): std::runtime_error(message)
{
}

