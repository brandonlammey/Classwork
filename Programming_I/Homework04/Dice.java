
/*
 * File Name: Dice.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: 4
 * Description: This class will use a random number generator to create dice objects. 
 * Last Changed: November 17, 2015 
 */

import java.util.Random;

public class Dice 
{
	final int numSides;
	
	//constructor set size of dice
	public Dice(int sides)
	{
		numSides = sides;
	}
	
	//selects a random value (1-numSides)
	public int roll()
	{
		int result = 0;
		Random diceRoll = new Random();
		result = diceRoll.nextInt(numSides) + 1;
		
		return (result);
	}
		
}
