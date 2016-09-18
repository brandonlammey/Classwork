/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 02
 * Description: Creates an executive object which is a dynamically allocated array of objects.
 * Then the run function is used to run the program allowing a user to search records based on 3 criteria. 
 */

#include "Executive.h"

int main(int argc, char* argv[])
{
    Executive exec(argv[1]);
    exec.run();
    return 0;
}
