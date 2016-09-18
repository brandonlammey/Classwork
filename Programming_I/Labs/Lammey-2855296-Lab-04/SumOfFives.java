/* 
 * File Name: SummationOfFives.java  
 * Author: Brandon Lammey
 * KUID: 2855296 
 * Email Address: archerlammey@ku.edu
 * Assignment: Lab04 
 * Description: Program takes multiples of a number determined by
 * user input and stops once a max value is reached determined by user. 
 * Then program takes the sum of all multiples. If user inputs value below
 less than "1" program will produce the message "ERROR". 
 * Last Changed: September 28, 2015
*/

import java.util.Scanner;

public class SumOfFives 
{
	public static void main(String[] args)
	{
		//variables
		Scanner userInput = new Scanner(System.in);
		int multiple = 0;
		int growth = 0;
		int endValue = 0;
		int summation = 0;
	 
		//talk to user and get inputs
		System.out.print("Please input a multiple larger than 1: ");
		multiple = userInput.nextInt();
		System.out.print("Please input a positive integer as the end value: ");
		endValue = userInput.nextInt();
	 
		//if statement for proper user input 
		if(multiple > 1 && endValue > 1)
		{
			//while statement to calculate summation 
			while((growth + multiple) <= endValue)
			{
				growth = growth + multiple;
				summation = growth + summation;
			}
			System.out.println("The summation is: " + summation);
		}
		else
		{
			System.out.println("ERROR");
		}
	}
}