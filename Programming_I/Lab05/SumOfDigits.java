/*
 * File Name: SumOfDigits.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 4.2
 * Description: This program will take a user inputed integer and call upon
 * a method to sum the digits in the integer and then output that value. The 
 * program will loop till the user is done inputing values. 
 * Last Changed: October 5, 2015 
 */

import java.util.Scanner;

public class SumOfDigits 
{
	public static void main(String[] args)
	{
		//variable declarations
		int num = 0;
		int sum = 0;
		Scanner myScan = new Scanner(System.in);
		int loop = 1;
				
		
		//runs program and loops based on user input
		do
		{
			System.out.println("");
			
			//take user input then call on method
			System.out.println("Please enter a No:");
			num = myScan.nextInt();
			sum = addDigits(num);//call on method to calculate
			System.out.println("The sum of digits is: " + sum);
			System.out.println("");
			
			System.out.println("Want to try it again?(y=1/n=0):");
			loop = myScan.nextInt();
			
		}while(loop==1);
		
		System.out.println("Thank you!");		
		
	}
	//method takes in integer and sums the digits in the integer
	public static int addDigits(int x)
	{
		int answer = 0;
		int sumValue = 0;
		
		while(x>0)
		{
			sumValue = x%10;
			answer = sumValue + answer;
			x=x/10;
		}
		return (answer);
	}
}
