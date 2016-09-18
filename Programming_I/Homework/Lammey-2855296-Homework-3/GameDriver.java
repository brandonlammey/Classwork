
/*
 * File Name: GameDriver.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: 3
 * Description: This program calls on the HangMan class to test user char inputs against a user defined secret word. 
 * The program will loop until the user is finished playing. Program is case sensitive assuming lower case input. 
 * Last Changed: November 9, 2015 
 */

import java.util.Scanner;


public class GameDriver 
{
	static Scanner console = new Scanner(System.in);
	public static void main(String[] args)
	{
		HangMan playGame = new HangMan("big bang");
		Scanner kb = new Scanner(System.in);
		String userInput;
		String playAgain = "";
		
		
		System.out.println("Welcome to the Hangman Game!");
		System.out.println("----------------------------");

		//loop to play game until user is done playing
		do
		{
			System.out.println("");
			
			//loop until the game ends
			do
			{
				System.out.println("Guess this: " + playGame.getDisguisedWord());
				System.out.println("Guesses so far: " + playGame.getGuessCount());
				System.out.println("Misses: " + playGame.getMissedCount());

				//take user guess
				System.out.print("Enter your guess character: ");
				userInput = kb.nextLine();
				userInput.toLowerCase();
				char guess = userInput.charAt(0);

				//statement to determine if guess is correct
				//uses guessCharacter method to compare guess with object
				if(playGame.guessCharacter(guess))
				{
					System.out.println(guess + " is in the secret word!");
				}
				else
				{
					System.out.println(guess + " is not in the secret word. Death draws Closer!");
				}
				System.out.println("");
				
								
			}while(!playGame.isGameOver());

			System.out.println("Game Over!");

			//tell user if they win or lose 
			if(playGame.isFound()==true)
			{
				System.out.println("Congratulations! You guessed the secret word " + playGame.getDisguisedWord() + " in " + playGame.getGuessCount() + " guesses!");
			}
			else
			{
				System.out.println("You died. Next time, guess as if your life depended on it.");
			}
			
					
			//ask user if they would like to play again
			System.out.println("Do you want to play again? (yes/no):");
			playAgain = kb.nextLine();
			playAgain.toLowerCase();

			//If play continues playing 
			//Ask user for a new secret word
			//clear the screen 
			if(playAgain.equals("yes"))
			{
				System.out.print("Input a new secret word: ");
				playGame.setSecretWord(kb.nextLine());
				
				for(int i=0; i<100; i++)
				{
					System.out.println("");
				}
			}
			

		}while(playAgain.equals("yes"));

		//returns games played
		System.out.println("Thanks for playing " + playGame.getGamesPlayed() + " games(s) of Hang Man!");
	}
}
