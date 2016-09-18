/*
 * File Name: Lab09.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 9
 * Description: This program will take the parameters for a user defined array and pass the
 * array into the Lab09 class to print the values in the array, sum and average of each line,
 * sum and average of the entire array, and the largest value in the array.   
 * Last Changed: November 9, 2015 
 */

import java.util.Scanner;

public class Lab09 
{
	public static void main(String[] args)
	{
		//variable declarations 
		Scanner kb = new Scanner(System.in);
		int rows = 0;
		int columns = 0;
		int[][] userArray;
		ArrayHelper classArray = new ArrayHelper();
		
		
		//ask user for array size
		System.out.print("How many rows?: ");
		rows = kb.nextInt();
		System.out.print("How many columns?: ");
		columns = kb.nextInt();

		//array creation 
		userArray = new int[rows][columns];
		

		//array initialization
		for(int i=0; i<userArray.length; i++)
		{
			for(int j=0; j< userArray[i].length; j++)
			{
				System.out.print("Enter a value for position (" + i + "," + j + "): ");
				userArray[i][j] = kb.nextInt();
			}
			
		}

		//print values in array 
		System.out.println("Here is your array");
		classArray.print2dArray(userArray);

		//print 1D sum and average
		for(int i=0; i<userArray.length; i++)
		{
			classArray.arraySum(userArray[i]);
			classArray.arrayAvg(userArray[i]);

			System.out.println("row " + i + " sum= " + classArray.getArraySum() + ", avg = " + classArray.getArrayAverage());
		}

		//print largest value
		//print entire sum
		//print entire average
		System.out.println("The largest value in the array is = " + classArray.arrayMax2D(userArray));
		System.out.println("The sum for the entire array is = " + classArray.arraySum2D(userArray));
		System.out.println("The average for the entire array is = " + classArray.arrayAvg2D(userArray));
	}
}
