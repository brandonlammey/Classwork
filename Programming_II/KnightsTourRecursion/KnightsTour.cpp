/*
 * File Name: KnightsTour.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 07
 * Description: Implementation of KnightsTour.h
 */

#include<iostream>


#include "KnightsTour.h"

KnightsTour::KnightsTour(int r, int c, int startRow, int startCol)
{
        initialKnightRow = startRow-1;
        initialKnightCol = startCol-1;
        Row = r;
        Column = c;

        
        //for dynamically allocated 2D array for board
        board = new int*[r];
        for(int i = 0; i < r; ++i) 
        {
            board[i] = new int[c];
        }
        
        
        counter = 1; //keeps track of moves
}

//for dynically allocated 2D array board
KnightsTour::~KnightsTour()
{
    for(int i = 0; i < Row; ++i) 
    {
        delete [] board[i];
    }
    delete [] board;
    board = nullptr;
}


void KnightsTour::setBoard()
{
    //set all positions in array to -1 
    for (int r=0; r<Row; r++) 
    {
        for (int c = 0; c < Column; c++)
        {
            board[r][c] = 0; // Initialize all elements to 0
        }  
    }   
} 

void KnightsTour::doKnightsTour() 
{

    //Set chess board
    //Set initial position of knight
    //proper sizes and initial position checked in main
    setBoard();
    board[initialKnightRow][initialKnightCol] = 0; 
    
    
        
 
    //attempt to move knight to each position on the KnightsTour without repeats
    if (moveKnight(initialKnightRow, initialKnightCol) == true) 
    {
        std::cout << "Success!" <<'\n';
        printKnightsTour();
    }
    else
    {
        std::cout << "Failed!" <<'\n';
        printKnightsTour();
    }
}
 
bool KnightsTour::attemptMove(int r, int c) 
{
    //move invalid if:
        //out of board paramters 
        //position has already been hit
    if((r < 0) || (r >= Row) || (c < 0) || (c >= Column)) 
    {
        return(false);
    }
    else if((board[r][c] != 0) || ((r == initialKnightRow) && (c == initialKnightCol) ))
    {
        return(false);
    }
    else
    {
        return(true);
    }
    
}

bool KnightsTour::moveKnight(int r, int c)
{
    //potential next move
    int nextRow = 0; //4
    int nextCol = 0; //6
 
    //current position
    int currentRow = r; //4
    int currentCol = c; //6
    
    //base case
    //all values in array are great than 0
    if(isDone() == true)
    {
        return(true);
    }
    
    //Recursion: moves
    //loop to check combination array for valid moves from possible knight movement
    for (int i = 0; i < 8; i++)
    {
        nextCol = currentCol + movesCol[i]; //4+ 1 //5
        nextRow = currentRow + movesRow[i]; //6+ -2 //4
        
        if((attemptMove(nextRow, nextCol)) == true)
        {
            
            board[nextRow][nextCol] = counter;
            
            counter++;
            if ((moveKnight(nextRow, nextCol))==true) //if move possible return true for current moveKnight
            {
                return(true);
            }
            else //backtrack if no move possible 
            {
                
                board[nextRow][nextCol] = 0;
                counter--;
            }
        }
        
    }
    return(false);
}

bool KnightsTour::isDone()
{
    for(int r =0; r <Row; r++)
    {
        for(int c = 0; c<Column;c++)
        {
            if((board[r][c] == 0) && ((r != initialKnightRow) || (c != initialKnightCol)))
            {
                    return(false);
            }
        }
    }
    return(true);
}

void KnightsTour::printKnightsTour()
{
    for(int r =0; r <Row; r++)
    {
        for(int c = 0; c<Column;c++)
        {
            if((board[r][c] == 0) && ((r != initialKnightRow) || (c != initialKnightCol)))
            {
                std::cout<< "[" << "  " << "]";
            }
            else
            {
                if(board[r][c]<10)
                {
                    std::cout<< "[ " << board[r][c] << "]";
                }
                else
                {
                    std::cout<< "[" << board[r][c] << "]";
                }
            }
        }
        std::cout<<'\n';
    }
}