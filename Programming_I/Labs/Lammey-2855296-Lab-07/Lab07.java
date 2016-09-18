/*
 * File Name: Lab07.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 7
 * Description: Program will create an array based on user input then create a larger resized array
 * determined by a new user input. Continue to prompt until large value is enterd. 
 * Then the program will count how many times a user inputed value 
 * occurs in the array as well as the minimum and maximum value.  
 * Last Changed: October 26, 2015 
 */

import java.util.Scanner;

public class Lab07 
{
	public static void main(String[] args)
	{
		int size = 0;
		int newArraySize = 0;
		double value = 0.0;
		int count = 0;
		double minimum = 0.0;
		double maximum = 0.0;
		
		Scanner kb = new Scanner(System.in);
		
		//loop till user inputs valid array size
		while(size <= 0) 
		{
			System.out.print("Input an array size: ");
			size = kb.nextInt();
		}
		System.out.println("");
		double[] userArray = new double[size]; //array created using user inputed size
		
		System.out.println("Now please enter " + size + " numbers");
		
		//loop to collect array values
		for(int i=0; i < userArray.length; i++) 
		{
			System.out.print("Input a number into your array: ");
			userArray[i]=kb.nextDouble();
		}
		
		System.out.println("Here are all the numbers in your array: ");
		printArray(userArray); //call on method to display all array values
		
		System.out.println("");
		
		//ask user for a larger array size		
		while(newArraySize<=size)
		{
		System.out.print("Input a new size: ");
		newArraySize = kb.nextInt();
		}
		
		//create a new array with a larger size
		userArray = arrayResize(userArray, newArraySize);
		
		System.out.println("You need to add " + (newArraySize-size) + " values");
		//add numbers to the empty spots in the array 
		for(int i=size; i<userArray.length; i++)//
		{
			System.out.print("Input a number to add to your array: ");
			userArray[i] = kb.nextDouble();
		}
		
		//print new array
		System.out.println("Here are all the numbers in your new array: ");
		printArray(userArray);
		
		
		System.out.println("");
		
		//Ask use for a value to count
		System.out.print("Enter a value to count: ");
		value = kb.nextDouble();
		
		//call on methods to determine the count of value, the min and max value in Array
		count = count(userArray, value);
		minimum = min(userArray);
		maximum = max(userArray)
				; 
		//print count, min, and max value
		System.out.println(value + " occurs " + count + " times in the array.");
		System.out.println("Min value in array: " + minimum);
		System.out.println("Max value in array: " + maximum);
	}
	
	//method prints all values entered into array in the form "[a, b, c]"
	public static void printArray(double[] arrayValues)
	{
		System.out.print("[");
		for(int i=0; i<arrayValues.length; i++)
		{
			System.out.print(arrayValues[i]);
			if(i<arrayValues.length-1)
			{
				System.out.print(", ");
			}
		}
		System.out.println("]");
	}
	
	//method to resize array
	public static double[] arrayResize(double[] oldArray, int newSize)
	{
		double[] newArray = new double[newSize];
		for(int i=0; i<oldArray.length; i++)
		{
			newArray[i]=oldArray[i];
		}
		return(newArray);
	}
	
	//counts the amount of times a value appears within the array
	public static int count(double[] arr, double value)
	{
		int sum = 0;
		for(int i=0; i< arr.length; i++)
		{
			if(value == arr[i])
			{
				sum = sum+1;
			}
		}
		return(sum);
	}
	
	//returns the value of the largest number in the array
	public static double max(double[] arr)
	{
		double maximum = 0.0;
		for(int i=0; i<arr.length; i++)
		{
			if(i==0)
			{
				maximum = arr[i];
			}
			else if(arr[i]>maximum)
			{
				maximum = arr[i];
			}
		}
		return(maximum);
	}
	
	//returns the value of the smallest number in the array 
	public static double min(double[] arr)
	{
		double minimum = 0.0;
		for(int i=0; i<arr.length; i++)
		{
			if(i==0)
			{
				minimum = arr[i];
			}
			else if(arr[i]<minimum)
			{
				minimum = arr[i];
			}
		}
		return(minimum);
	}
}
