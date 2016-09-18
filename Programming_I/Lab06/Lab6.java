/*
 * File Name: Lab6.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 6
 * Description:A user defined array is used to calculate the sum of all values,
 * the average of all the values, the largest, and smallest value. 
 * Last Changed: October 5, 2015 
 */

import java.util.Scanner;

public class Lab6 
{
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		int arraySize = 0;
		int sum = 0;
		int average = 0;
		int largestValue = 0;
		int smallestValue = 0; 
		
		//loop statement to verify user input greater than 0
		while(arraySize == 0 || arraySize < 0 )
		{
			System.out.print("Input an array size: ");
			arraySize = kb.nextInt();
		}

		System.out.println("Now please enter " + arraySize + " numbers");
		int[] userArray = new int[arraySize]; // array to hold int values
		
		//for loop to assign values into array
		for(int i=0; i<userArray.length; i++)
		{
		System.out.print("Input a number into your array: ");
		userArray[i] = kb.nextInt();
		}	
		
		System.out.println("Here are all the numbers in your array:");
		for(int i=0; i<userArray.length; i++)
		{
			System.out.println(userArray[i]);
		}
		
		//loop to calculate sum
		for(int i=0; i<userArray.length; i++)
		{
			sum = userArray[i]+sum;
		}
		//average
		average = sum/arraySize;
		//largest value
		for(int i=0; i<userArray.length; i++)
		{
			if(i==0)
			{
				largestValue=userArray[i];
			}
			else if(userArray[i]>largestValue)
			{
				largestValue=userArray[i];
			}
		}
		//smallest value
		for(int i=0; i<userArray.length; i++)
		{
			if(i==0)
			{
				smallestValue=userArray[i];
			}
			else if(userArray[i]<smallestValue)
			{
				smallestValue=userArray[i];
			}
		}
		
		System.out.println("The sum of all the values: " + sum);
		System.out.println("The average of all the values is: " + average);
		System.out.println("The largest value is: " + largestValue);
		System.out.println("The smallest values is: " + smallestValue);
	}

}
