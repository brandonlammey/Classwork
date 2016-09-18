/*
 * File Name: main.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 07
 * Description: Four parameters m, n, initial-knight-row, initial-knight-col and used to create 
 * a KnightsTour object. Input will be checked to ensure chess board size is at least 1x1 and knight position is 
 * within the board. The parameters are taken in from the argv commands (Use atoi to convert argv[i] into an integer.). 
 * KinghtsTour class method doKnightsTour will be used to determine if a tour is possible with the parameters. 
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "KnightsTour.h"

int main(int argc, char* argv[])
{

    //size of board (rxc)
    int boardRows = std::stoi(argv[1]);
    int boardColumns = std::stoi(argv[2]);
    
    //initial position for the knight
    int initialRow = std::stoi(argv[3]);
    int initialColumn = std::stoi(argv[4]);
    
    std::cout << "Executing Lab 7" <<'\n';
    std::cout << "Board Size : (" << boardRows << "x" << boardColumns << ")" << '\n';
    std::cout << "Initial Knight Position: (" << initialRow << "x" << initialColumn << ")" << '\n' <<'\n';
    
    //Check: 
        //Board is at least (1x1)
        //initial Knight position within the board
    if(boardRows< 1|| boardColumns<1)
    {
        std::cout << "Failed! Board size invalid." << '\n';
    }
    else if(initialRow >= boardRows || initialColumn >= boardColumns|| initialRow < 0 || initialColumn < 0)
    {
        std::cout << "Failed! Initial knight placement out of bounds." << '\n';
    }
    else //board size is valid and initial position is valid
    {  
        KnightsTour userTour(boardRows, boardColumns, initialRow, initialColumn);
        userTour.doKnightsTour();
    }

    return 0;

}