/*File Name: Pyramid.java  
 * Author: Brandon Lammey
 * KUID: 2855296 
 * Email Address: archerlammey@ku.edu 
 * Assignment: Lab04 
 * Description: Program takes user input for the base of a pyramid then
 * begins on line one with one asterisk then progresses to a new line
 * adding an asterisk and repeating till a line reaches the user input 
 * amount for the variable base. Program assumes user input is a positive
 * real number integer value. 
 * Last Changed: September 28, 2015
*/

import java.util.Scanner;

public class Pyramid 
{
	public static void main(String[] args)
	{
		//variables
		Scanner userInput = new Scanner(System.in);
		int base = 0;
		 
		System.out.print("Enter the number of asterisks for the base of the triangle: ");
		base = userInput.nextInt();
		 
		for(int n = 1; n<= base; n++)//controls the row
		{
			for(int i = 1; i<= n; i++)//individual row
			{
				System.out.print("*");//prints “*” until loop ends
			}
		System.out.println("");//ends row and begins next row
		}	
	}
		
}
