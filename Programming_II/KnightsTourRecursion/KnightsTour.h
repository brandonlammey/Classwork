 /*
 * File Name: KnightsTour.h
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 07
 * Description: Class will take in 4 parameters (board rows, board columns, initial row, initial column) 
 * to create a Knights Tour object. A recursive approach is used to determine if a knight can be 
 * moved around the 2D chess board array touching each square only once till it has touched every square once with no repeats. 
 */

#ifndef KnightsTour_H
#define KnightsTour_H

#include<iostream>


//You are to get the four parameters m, n, initial-knight-row, initial-knight-col 
//from the argv commands. (Use atoi to convert argv[i] into an integer.) 

//Make sure the KnightsTour size is at least 1x1, 

class KnightsTour
{
    private:
        int initialKnightRow;
        int initialKnightCol;
        int Row; 
        int Column;
        int counter;
        //int board[8][8];//assumes board size will be no larger than 8x8
        int** board; //dynically allocated board 
         
        //possible moves for a Knight that will not change
        //movesRow: movement in the y direction 
        //movesCol: movement in the x direction
        const int movesRow[8] = {1,-1,2,-2,1,-1,2,-2};
        const int movesCol[8] = {2,2,1,1,-2,-2,-1,-1};
        
        //set all initial values in array to 0
        void setBoard();
        
        //Attempt to move knight
        //conditions: 
            //x coordinate cannot go out of bounds
            //y coordinate cannot go out of bounds
            //knight can only move onto untouched space
        bool attemptMove(int r, int c);
        
        //Begins moving knight
        //tries all possible knight movements
        //continues to move till base case is reached
            //base case: all values in array > -1
            //if move not possible change previous move
        bool moveKnight(int r, int c); 
        
        //checks if all values in knights tour are greater than -1
            //returns true if greater than one and thus knights tour is done
            //returns false otherwise 
        bool isDone();
        
       
    public:
        //constructor with initial values set by user 
        KnightsTour(int r, int c, int startRow, int startCol);
        ~KnightsTour(); //needed if board is dynically allocated 

        //displays KnightsTour using a 2-D array
        void printKnightsTour();
        
        //initiates knights tour
            //sets board
            //attempts to place knight at initial position
            //attempts moves 
        void doKnightsTour();
        
};

#endif