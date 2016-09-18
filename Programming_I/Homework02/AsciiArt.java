/*
 * File Name: AsciiArt.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework Assignment Number: 2.1
 * Description: Using if statements and nested for loops this program will
 * create one of four patterns(Stripes, Checker Board, Double Diagonal/X, or Two Islands)
 * or it will output "Error." The choice is based on user input for pattern and size using
 * integer values. Patterns will use "*" and spaces except in the case of Two Islands
 * which will use "*" for separation between islands, "!"  for top left corner island,
 * "?" for bottom right corner island, and "~" for remaining empty space representing water.
 * Last Changed: October 2, 2015 
 */
	
import java.util.Scanner;
	
public class AsciiArt 
{
	public static void main(String[] args)
	{
		//variable declarations
		int pattern = 0;
		int size = 0;
		Scanner kb = new Scanner(System.in);
		
		//Talk to user about pattern type
		System.out.println("Choose on of the following patterns by typing the corresponding number:");
		System.out.println("1) Stripes");
		System.out.println("2) Checker Board");
		System.out.println("3) Double Diagonal");
		System.out.println("4) Two Islands");
		pattern = kb.nextInt(); //retrieve user input 
		System.out.println("");
		
		//check user input is valid for pattern
		if(5 > pattern && pattern > 0)
		{
			//continue with program retrieve size
			System.out.println("Input a size (must be larger than 1):");
			size = kb.nextInt(); 
			System.out.println("");
			
			//check user input
			if(size>1)
			{
				//run program with valid inputs for size
				if(pattern == 1)//Stripes with user entered rows and 6 columns
				{
					for(int r=0; r<size; r++)//controls line position
					{
						System.out.print(r+" ");
						for(int i=0; i<size; i++)//controls line contents
						{
							if((i%2) == 0)
							{
								System.out.print("*");
							}
							else
							{
								System.out.print(" ");
							}
						}
						System.out.println("");
					}
				}
				else if(pattern == 2)//Checker Board with user entered rows and 8 columns
				{
					for(int r=0; r<size; r++)//controls line position
					{
						System.out.print(r+" ");
						for(int i=0; i<size; i++)//controls line contents
						{
							//statement to control "*" position
							if((r+i)%2==0)
							{
								System.out.print("*");
							}
							else
							{
								System .out.print(" ");
							}
						}
						System.out.println("");
					}
				}
				else if(pattern == 3)//Double Diagonal (X) with user entered rows
				{
					for(int r=0; r<size; r++)//controls line position
					{
						System.out.print(r+" ");
						for(int i=0; i<size; i++)//controls line contents
						{
							//statement to control "*" position
							if((r+i)==(size-1) || r==i)
							{
								System.out.print("*");
							}
							else
							{
								System .out.print(" ");
							}
						}
						System.out.println("");
					}
				}
				else//Two Islands
				{
					for(int r=0; r<size; r++)//controls line position
					{
						System.out.print(r+" ");
						for(int i=0; i<size; i++)//controls line contents
						{
							//statement to control "*" position
							if((r+i)==(size-1))//border
							{
								System.out.print("*");
							}
							else if(r < (size/2) && i < (size/2))//island "!"
							{
								System.out.print("!");
							}
							else if(r >= ((size/2)+(size%2)) && i >= ((size/2)+(size%2)))//island "?"
							{
								System.out.print("?");
							}
							else//water
							{
								System .out.print("~");
							}
						}
						System.out.println("");
					}
				}
				
			}
			else
			{
				System.out.println("Error." + "\n");
			}
		}
		else
		{
			System.out.println("Error." + "\n");
		}
		
	}
}
