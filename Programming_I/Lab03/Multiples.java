/* 
 * File Name: Multiples.java
 * Author: Brandon Lammey
 * KUID: 2855296
 * Assignment: EECS168 Lab3.3
 * Description: Assume user input positive integer values above 0 for the number. 
 * Take multiples of the user inputed number based on user inputed multiples. 
 * An if statement is used to make sure multiples are greater than 0.  
 * Date: September 21, 2015
 */

import java.util.Scanner;

public class Multiples 
{
	public static void main(String[] args)
	{
		int num = 0;
		int multiple = 0;
		Scanner myScan = new Scanner(System.in);
		
		System.out.println("What number do you wish to see multiples of?");
		num = myScan.nextInt();
		
		System.out.println("How many multiples?");
		multiple = myScan.nextInt();
				
		if(multiple > 0) //program will loop if multiples is not less than or equal to zero
		{
			for(int i = num; i<=num*multiple ; i=i+num)
			{
				System.out.println(i);
			}
		}
		else
		{
			System.out.println("Error: The ammount of multiples to display must be greater than zero.");
		}
	}
}
