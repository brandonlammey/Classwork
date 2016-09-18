/*
 * File Name: Colosseum.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 01
 * Description: This colosseum object will assist in the bulding of the Pokemon object(s)
 * and play the game by calculating attack and defense bonuses and if damage occurs. It
 * will update variables as needed and determine when the game will end 
 */

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>
#include <string>

#include "Pokemon.h"
#include "Dice.h"


 
 class Colosseum
 {
 private: 
 	Dice d20;
 	Dice d6;
	Dice d2;
 
 public:
 	//constructor
 	//initializes dice to proper size
 	Colosseum(); 
 
 	//sets all values for name, hp, attackLevel, and defenseLevel 
 	//hp (1-50)
 	//attackLevel+defenseLevel (1-50)
 	//prompt for good input
 	void userBuild(Pokemon& p);
 
	//calculate attack and defense bonus using d20
 	//attack hits = attack+attack bonus > defense+defense bonus
 	//damage = 3 d6 
 	//display attack info
 	//determine if defender died (true = death) (false otherwise)
 	bool attack(const Pokemon& attacker, Pokemon& defender);
 
 	//handles 10 round fight 
 	//uses d2 to determine first attacker
 	//display round info and calls attack() for attack info
 	//determine when game ends
 	void play(Pokemon& p1, Pokemon& p2); 
 
 };

#endif
