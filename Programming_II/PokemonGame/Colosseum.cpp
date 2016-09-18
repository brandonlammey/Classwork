/*
 * File Name: Colosseum.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 01
 * Description: This is the implementation file for the colosseum object 
 */

#include "Colosseum.h"

using namespace std;

 Colosseum::Colosseum()
 {
 	d20 = Dice(20); //20 sided dice
 	d6 = Dice(6); //6 sided dice
 }

 void Colosseum::userBuild(Pokemon& p)
 {
     string name = "";
     int hp = 0;
     int attack = 0;
     int defense = 0;

     std::cout << "Please name your pokemon: ";
     std::cin >> name;

     std::cout << '\n';

     while(name == "")
     {
         std::cout << "Sorry. Your pokemon must have a name: ";
         std::cin >> name;
         std::cout << '\n';
     }

     std::cout << "How many hitpoints will it have? (1-50): ";
     std::cin >> hp;
     std::cout << '\n';

     while(hp < 1 || hp > 50)
     {
         std::cin >> hp;
         std::cout << '\n';
     }

     std::cout << "Split fifty points between attack level and defense level"
               << '\n' << "Enter your attack level (1-49): ";
     std::cin >> attack;
     std::cout << '\n';

     while(attack < 1 || attack > 49)
     {
         std::cout << "Sorry. The attack level must be between 1 and 49: ";
         std::cin >> attack;
         std::cout << '\n';
     }

     std::cout << "Enter you defense level? (1-" << 50-attack << "): ";
     std::cin >> defense;
     std::cout << '\n';

     while(defense < 1 || defense > 50-attack)
     {
         std::cout << "Sorry. The defense level must be between 1 and " << 50-attack << ": ";
         std::cin >> defense;
         std::cout << '\n';
     }



     p.setName(name);
     p.setHp(hp);
     p.setAttackLevel(attack);
     p.setDefenseLevel(defense);
 }

 bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
 {
	int attackBonus = d20.roll();
	int defenseBonus = d20.roll();
	int damage = 0;	
	
	std::cout<< attacker.getName() << " rolls an attack bonus of " << attackBonus << '\n'
		<< defender.getName() << " rolls an attack bonus of " << defenseBonus << '\n';
	
	if(attackBonus + attacker.getAttackLevel() < defenseBonus + defender.getDefenseLevel())
	{
		std::cout << "The attack missed!" << '\n';
		return(false);	
	} 
	else
	{
		std::cout << "The attack hits dealing 3-D6 damage!" << '\n'
			<< "The rolls are "; 
		
		for(int i=0; i<3; i++)
		{
			int j = d6.roll();
			damage += j;

			if (i<2)
			{
				std::cout << j << ", ";
			}
			else
			{
				std::cout << "and " << j << " totalling: " 
					<< damage << " damage!" << '\n';
			}

		}

		defender.setHp(defender.getHp()- damage);

		if(defender.getHp() > 0 )
		{
			std::cout << defender.getName()
				<< " has " << defender.getHp() << " hit points left"<< '\n';
			return(false);
		}
		else
		{
			return(true);
		}

	}

	
	
 
 }

 void Colosseum::play(Pokemon& p1, Pokemon& p2)
 {
 	d2 = Dice(2); //2 sided dice
	int round = 0;

	
	std::cout << "Choosing which player to go first: " << '\n';

	if(d2.roll() == 1)
	{

		std::cout << "Player 1 will go first." << '\n';
		while(p1.getHp() > 0 && p2.getHp() > 0 && round<10)
		{
			round+=1;

			std::cout << '\n' <<'\n'
			<< "Round " << round << "!" << '\n' << '\n';

			std::cout << p1.getName() << " is attacking " << p2.getName();
			attack(p1, p2); //THIS

			if(p2.getHp() < 1)
			{
				std::cout << p2.getName() << " has been defeated!" << '\n';
			}
			else
			{
				std::cout << p2.getName() << " is attacking " << p1.getName() << '\n';
				attack(p2, p1); //THIS
				
				if(p1.getHp()<1)
				{
					std::cout << p1.getName() << " has been defeated!" << '\n';
				}
			}
		}
	}
	else
	{
		std::cout << "Player 2 will go first." << '\n';
		while((p1.getHp() > 0 && p2.getHp() > 0) && round<10)
		{
			round+=1;

			std::cout << '\n' << '\n'
			<< "Round " << round << "!" << '\n' << '\n';

			std::cout << p2.getName() << " is attacking " << p1.getName();
			attack(p2, p1); //THIS

			if(p1.getHp() < 1)
			{
				std::cout << p1.getName() << " has been defeated!" << '\n';
			}
			else
			{
				std::cout << p1.getName() << " is attacking " << p2.getName() << '\n';
				attack(p1, p2); //THIS
				
				if(p2.getHp()<1)
				{
					std::cout << p2.getName() << " has been defeated!" << '\n';
				}
			}
		}
	}

	if(p1.getHp() > 0 && p2.getHp() > 0)
		{
			std::cout << "Both fighters are still standing! Its a draw!" << '\n';
		}
		
	
 }
