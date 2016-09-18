/*File Name: WordGuessingGame.java  
 * Author: Brandon Lammey
 * KUID: 2855296 
 * Email Address: archerlammey@ku.edu 
 * Assignment: Lab04 
 * Description: Program takes user inputed string and checks if string
 * is equal to "valentine". Program loops till user guesses word 
 * "valentine" correctly.
 * Last Changed: September 28, 2015
*/

import java.util.Scanner;

public class WordGuessingGame 
{
	public static void main(String[] args)
	{
		//variables
		Scanner userInput = new Scanner(System.in);
		String guess = "";
		String correct = "valentine"; 
		 
		//talk to user and take initial input
		System.out.println("Welcome to the word guessing game.");
		System.out.print("Guess a word: ");
		guess = userInput.nextLine();
		 
		while(!(guess.equals(correct)))
		{
			System.out.print("Incorrect. Guess again: ");
			guess = userInput.nextLine();
		}
		System.out.print("You win!");
	}
}
