/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 01
 * Description: This will call on Pokemon and Colosseum objects in order to "play" the game.
 */

#include <iostream>
#include <string>

#include "Pokemon.h"
#include "Colosseum.h"

using namespace std;

int main()
{
    //declares two pokemon
    //declares colosseum 
    Pokemon P1;
    Pokemon P2;
    Colosseum Arena;
    char playing = 'y';
    
    while(playing == 'y')
    {
	std::cout << "Player 1, build your Pokemon!"<< '\n' << "====================="<< '\n';
	Arena.userBuild(P1);
    
	std::cout << "Player 2, build your Pokemon!"<< '\n' << "====================="<< '\n';
	Arena.userBuild(P2);

	Arena.play(P1, P2);
    
	std::cout << "Do you want to play again? (y/n): ";
	std::cin >> playing;
	
	if(playing == 'n')
	{
		std::cout << '\n' << "Thanks for playing!" << '\n';
	}
	else
	{	
		std::cout << '\n' << '\n' << '\n'; 
	} 
    }      
return 0;
}
