/*
 * File Name: NumberGuessingGame.java 
 * Author: Brandon Lammey
 * KUID: 2855296 
 * Email Address: archerlammey@ku.edu
 * Assignment: Lab04 
 * Description: Program takes user inputed number and loops until user
 * guesses the number "73" correctly. 
 * Last Changed: September 28, 2015
 */

import java.util.Scanner;

public class NumberGuessingGame 
{
	public static void main(String[] args)
	{
		//variables
		Scanner userInput = new Scanner(System.in);
		int guess = 0;
		 
		//Talk to user
		System.out.println("Welcome to the number guessing game.");
		 
		//Loop user guess till they guess correctly
		do
		{
			//take user input for guess
			System.out.print("Guess a number: ");
			guess = userInput.nextInt();
			 
			//determine if guess is high, low, or correct
			if(guess > 73)
			{
				System.out.println("Sorry, your guess is too high.");
			}
			else if(guess < 73)
			{
				System.out.println("Sorry, your guess is too low.");
			}
			else
			{
				System.out.println("You win!");
			}
		}while(guess != 73); //loop till correct
	}
}
