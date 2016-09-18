
/*
 * File Name: Colosseum.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: 4
 * Description: This class will act as a game driver for Pokemon.java and Dice.java.
 * This class will use a method to assist in building a Pokemon object by taking 
 * user inputed information and setting values for two objects P1 and P2.
 * Once Pokemon are created and built this class will call on Pokemon.java to
 * automate the "fight".
 * Last Changed: November 17, 2015 
 */


import java.util.Scanner;

//game driver
public class Colosseum 
{
	//creates: 2 pokemon, 1 two sided dice
	//calls userBuild to allow each player to build pokemon
	//decides which player goes first: 1=player1 2=player2
	//makes pokemon fight for up to 10 rounds 
	//display round info
	public static void main(String[] args)
	{
		//object declaration
		Dice D2 = new Dice(2); //two sided dice
		Pokemon P1 = new Pokemon(); //player1
		Pokemon P2 = new Pokemon(); //player2
		int round = 0;

		System.out.println("Player 1, build your Pokemon!");
		System.out.println("=====================");
		//build player 1 Pokemon
		userBuild(P1);

		System.out.println("Player 2, build your Pokemon!");
		System.out.println("=====================");
		//build player 2 Pokemon
		userBuild(P2);

		System.out.println("=====================");
		//roll and attack
		System.out.println("Player 1 will roll a D2 and decides who goes first.");
		if(D2.roll() == 1)
		{

			System.out.println("Player 1 rolls a 1 and will go first.");
			System.out.println("=====================");
			System.out.println("");
			while(P1.getHp() > 0 && P2.getHp() > 0 && round<10)
			{
				round+=1;

				System.out.println("");
				System.out.println("Round " + round + "!");
				System.out.println("");

				System.out.println(P1.getName() + " is attacking " + P2.getName());
				P1.attack(P2);

				if(P2.getHp() < 1)
				{
					System.out.println(P2.getName() + " has been defeated!");
				}
				else
				{
					System.out.println(P2.getName() + " is attacking " + P1.getName());
					P2.attack(P1);
					if(P1.getHp()<1)
					{
						System.out.println(P1.getName() + " has been defeated!");
					}
				}
			}
		}
		else
		{
			System.out.println("Player 1 rolls a 2 and will go second.");
			System.out.println("=====================");
			System.out.println("");
			while((P1.getHp() > 0 && P2.getHp() > 0) && round<10)
			{
				round+=1;

				System.out.println("");
				System.out.println("Round " + round + "!");
				System.out.println("");

				System.out.println(P2.getName() + " is attacking " + P1.getName());
				P2.attack(P1);

				if(P1.getHp()<1)
				{
					System.out.println(P1.getName() + " has been defeated!");
				}
				else
				{
					System.out.println(P1.getName() + " is attacking " + P2.getName());
					P1.attack(P2);
					if(P2.getHp()<1)
					{
						System.out.println(P2.getName() + " has been defeated!");
					}
				}
			}
		}
		
		//determines if the fight was a draw 
		if(P1.getHp() > 0 && P2.getHp() > 0)
		{
			System.out.println("Both fighters are still standing! Its a draw!");
		}
}
	
	
	//interact with user
	//sets all values properly: name, HP, attack, and defense
		//cannot give empty sting for name && HP is between (1-50)
		//attack + defense is between (1-50)
		//attack>0 && defense>0		
	static void userBuild(Pokemon p)
	{
		Scanner kb = new Scanner(System.in);
		
		//Ask for pokemon name
		//loops till valid input: not empty or all white space
		System.out.print("Please name your pokemon: ");
		p.setName((kb.nextLine()).trim());
		System.out.println("");
		while(p.getName().equals(""))
		{
			System.out.print("Sorry. Your pokemon must have a name: ");
			p.setName((kb.nextLine()).trim());
			System.out.println("");
		}



		//Asks user for HP between 1-50
		//Loops till user enters value 1-50 (assumes numerical input)
		System.out.print("How many hit points will it have? (1-50): ");
		p.setHp(kb.nextInt());
		System.out.println("");
		while(p.getHp() < 1 || p.getHp() > 50)
		{
			System.out.print("Sorry. The hit points must be between 1 and 50: ");
			p.setHp(kb.nextInt());
			System.out.println("");
		}
				
		System.out.println("Split fifty points between attack level and defense level");
		
		//Asks user for attack 1-49
		//Loops till user enters valid input (assumes numerical input)
		System.out.print("Enter your attack level (1-49): ");
		p.setAttackLevel(kb.nextInt());
		System.out.println("");
		while(p.getAttackLevel() < 1 || p.getAttackLevel() > 49)
		{
			System.out.print("Sorry. The attack level must be between 1 and 49: ");
			p.setAttackLevel(kb.nextInt());
			System.out.println("");
		}
		
		//Asks user to enter defense 1-(50-Attack)
		//Loops till user enters valid input (assumes numerical input)
		System.out.print("Enter your defense level (1-" + (50 - p.getAttackLevel()) + "): ");
		p.setDefenseLevel(kb.nextInt());
		System.out.println("");
		while(p.getDefenseLevel() < 1 || p.getDefenseLevel() > (50 - p.getAttackLevel()))
		{
			System.out.print("Sorry. The defense level must be between 1 and " + (50 - p.getAttackLevel()) + ": ");
			p.setDefenseLevel(kb.nextInt());
			System.out.println("");
		}
			
	}
}
