
/*
 * File Name: Pokemon.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: 4
 * Description: This class will create Pokemon objects with an hp, defense, and attack. 
 * This program will also call on Dice.java to build two dice to use random numbers used
 * in the attack method. This class will have an attack method where two objects used
 * to conduct a "fight" and will update values of hp, attack, and defense of each object
 * respectively. 
 * Last Changed: November 17, 2015 
 */

public class Pokemon 
{
	//private member variables of each Pokemon
	private int hp; //health points
	private int attackLevel; //attack
	private int defenseLevel; //defense
	private String name; //name
	private Dice d20; //20 sided dice
	private Dice d6; //six sided dice
	
	
	//constructor
	//initializes all data to 0 and strings to empty
	//initializes dice to correct size
	public Pokemon()
	{
		hp = 0;
		attackLevel = 0;
		defenseLevel = 0;
		
		name = "";
		
		d20 = new Dice(20); //20 sided dice
		d6 = new Dice(6); //6 sided dice	
		
	}
	
	
	//Roll d20 to determine attackBonus and defenseBonus
	//Attacker: attackLevel+attackBonus > Defender: defenseLevel+defenseBonus 
		//roll for damage 
		//else miss return false
	//Attack Lands: damage = Roll 3 d6 and add 
	//display attack information 
		//defender HP < 0 return true
		//else return false
	public boolean attack(Pokemon opponent)  
	{
		int attackBonus = d20.roll(); //ERROR NULL POINTER
		int defenseBonus = d20.roll();
		int damage = 0;

		System.out.println(this.getName() + " rolls an attack bonus of " + attackBonus);
		System.out.println(opponent.getName() + " rolls a defense bonus of " + defenseBonus);

		if(attackBonus + this.attackLevel < defenseBonus + opponent.getDefenseLevel()) //finish this
		{
			System.out.println("The attack missed!");
			return(false); 
		}
		else
		{
			System.out.println("The attack hits dealing 3-D6 damage!");

			System.out.print("The rolls are ");
			for(int i=0; i<3; i++)
			{
				int j = d6.roll();
				damage += j;

				if (i<2)
					System.out.print(j + ", ");
				else
					System.out.println("and " + j + " totalling: " + damage + " damage!");
			}

			opponent.setHp(opponent.getHp()-damage);

			if(opponent.getHp() > 0 )
			{
				System.out.println(opponent.getName() + " has " + opponent.getHp() + " hit points left");
				return (false);
			}
			else
			{
				return(true);
			}
		}
	}
	
	
	//get methods to return HP, attack level, defense level, and name
	public int getHp()
	{
		return(hp);
	}
	public int getAttackLevel()
	{
		return(attackLevel);
	}
	public int getDefenseLevel()
	{
		return(defenseLevel);
	}
	public String getName()
	{
		return(name);
	}
	
	//set methods to set HP, attack level, defense level, and name
	public void setHp(int h)
	{
		hp = h;
	}
	public void setAttackLevel(int a)
	{
		attackLevel = a;
	}
	public void setDefenseLevel(int d)
	{
		defenseLevel = d;
	}
	public void setName(String n)
	{
		name = n;
	}
	
	
	
}
