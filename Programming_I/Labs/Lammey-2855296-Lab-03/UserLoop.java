/* 
 * File Name: UserLoop.java
 * Author: Brandon Lammey
 * KUID: 2855296
 * Assignment: EECS168 Lab3.2
 * Description: Using a for statement a user inputed value will be looped till it reaches a
 * user inputed end value. An if statement is used to ensure start value is smaller than end value.
 * The assumption is made that the use will input integers greater than or equal to 0.  
 * Date: September 21, 2015
 */

import java.util.Scanner;

public class UserLoop 
{
	public static void main(String[] args)
	{
		int startValue = 0;
		int endValue = 0;
		
		Scanner myScan = new Scanner(System.in);
		
		System.out.print("Input a start value(included): ");
		startValue = myScan.nextInt();
						
		System.out.print("Input an ending value(excluded): ");
		endValue = myScan.nextInt();
		
		//if-else statement will be used to vet improper user input
		if(endValue > startValue)
		{
			//if statement is true loop will run starting with startValue increasing by one
			//loop will stop once endValue is reached without printing end value 
			for(int i = startValue; i < endValue; i=1+i)
			{
				System.out.println(i);
			}
		}
		else
		{
			System.out.println("Invalid Input");
		}
	}
}