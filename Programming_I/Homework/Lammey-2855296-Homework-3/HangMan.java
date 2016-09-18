
/*
 * File Name: HangMan.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: 3
 * Description: This user defined class uses methods to check a inputed letter against a user defined word. 
 * It automatically updates all instance variables accordingly and keeps count of each game played.
 * When the game is over the instance variables are reset. The program disguises a user inputed word
 * and uses markers to keep track of misses. 
 * Last Changed: November 9, 2015 
 */

public class HangMan 
{
	
	//variables 
	private String secretWord;
	private char[] disguisedWord;
	private int guessCount;
	private final int MAX_MISSES_ALLOWED;
	private char[] missedMarkers;
	private static int gamesPlayed = 0;
	private int missesCount;
	private boolean checker; //used to determine if correct guess is made
	
	//Constructor
	//initialize all variables
	public HangMan(String initialWord)
	{
		MAX_MISSES_ALLOWED = 7;
		secretWord = initialWord;
		disguisedWord = new char[secretWord.length()];
		missedMarkers = new char[MAX_MISSES_ALLOWED];
		guessCount=0;
		missesCount=0;
		gamesPlayed++;
		
		for(int i=0; i<MAX_MISSES_ALLOWED; i++)
		{
			if(i<missesCount)
			{
				missedMarkers[i]='X';
			}
			else
			{
				missedMarkers[i]='O';
			}
			
		}
		
		for(int i=0; i< secretWord.length(); i++)
		{
			if(secretWord.charAt(i) == ' ')
			{
				disguisedWord[i] = ' ';
			}
			else
			{
				disguisedWord[i] = '?';
			}
			
		}
		
		
	}
	
	//Guesses that a character c is in the secret word
	//Updates all instance variables accordingly
	//Returns true if c is present in the secret word
	public boolean guessCharacter(char c)
	{
		//updates disguised word
		for(int i=0; i< secretWord.length(); i++)
		{
			if(secretWord.charAt(i)==c)
			{
				disguisedWord[i]= c;
				checker = true;
			}
		}
		guessCount++;

		//returns true if c is in the word
		//if false update missedMarkers
		if(checker == true)
		{
			checker=false;
			return(true);
		}
		else
		{
			missesCount++;
			for(int w=0; w < 7; w++)
			{
				if(w<missesCount)
				{
					missedMarkers[w]='X';
				}
				else
				{
					missedMarkers[w]='O';
				}
			}
			return(false);
		}

	}

	//Returns true if the user is out of guesses or the word was found
	public boolean isGameOver()
	{
		if(missesCount == MAX_MISSES_ALLOWED || secretWord.equals(new String(disguisedWord)))
		{
		return(true);
		}
		else
		{
		return(false);
		}
	}
	
	//Returns true if the secret word was discovered 
	//(all characters in the secret word have been guessed)
	public boolean isFound()
	{
		if(missesCount<7)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	
	//Returns Disguised word, which contains correctly guessed letters 
	//in their correct positions and unknown letters as ?
	//this is returning a String not a char[]
	public String getDisguisedWord()
	{
		String result = new String(disguisedWord);
		return(result);
	}
	
	//Returns the number of guesses made
	public  int getGuessCount()
	{
		return(guessCount);
	}
	
	//Returns the number of incorrect guesses made
	public int getMissesCount()
	{
		return(missesCount);
	}
		
	//Turns missedMarkers array into a string
	//Returns a string representing the missed guess markers
	public String getMissedCount()
	{
		
		String result = new String(missedMarkers);
		return(result);
	}
	
	//returns the number of instances of HangMan that have been constructed
	public int getGamesPlayed()
	{
		return(gamesPlayed);
	}
	
	//set a new secret word
	//call on reset to reset all variables 
	public void setSecretWord(String r)
	{
		secretWord = r;
		reset();
	}
	//resets all variables 
	private void reset()
	{
		disguisedWord = new char[secretWord.length()];
		missedMarkers = new char[MAX_MISSES_ALLOWED];
		guessCount=0;
		missesCount=0;
		gamesPlayed++;
		
		for(int i=0; i<MAX_MISSES_ALLOWED; i++)
		{
			if(i<missesCount)
			{
				missedMarkers[i]='X';
			}
			else
			{
				missedMarkers[i]='O';
			}
			
		}
		
		for(int i=0; i< secretWord.length(); i++)
		{
			if(secretWord.charAt(i) == ' ')
			{
				disguisedWord[i] = ' ';
			}
			else
			{
				disguisedWord[i] = '?';
			}
			
		}
	}
}
