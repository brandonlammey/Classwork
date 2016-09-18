/*
 * File Name: SquareMatrix.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework Assignment Number: 2.2
 * Description: Using nested for loops this program will take a user inputed
 * inputed integer assuming valid input it will calculate and display its square 
 * matrix and transpose of the square matrix. To create the square matrix the 
 * program will begin with the internal row number starting with 1 and increment 
 * by user input "n" multiplied by the line number starting with 0.
 * To calculate the transpose the program will begin with the row number 
 * starting with 1 and increment by "n" multiplied by internal row position starting with 0.
 * Last Changed: October 2, 2015 
 */

import java.util.Scanner;

public class SquareMatrix 
{
	public static void main(String[] args)
	{
		//variable declarations
		int n = 0;
		Scanner kb = new Scanner(System.in);
		
		System.out.print("Enter the size of the Square Matrix:");
		n = kb.nextInt();
		
		System.out.println("Square Matrix");
		//square matrix
		for(int l=0; l< n; l++)
		{
			for(int i=1; i<= n; i++)
			{
				System.out.print(i+(n*l) + " ");;
			}
			System.out.println("");
		}
		
		System.out.println("Transpose");
		//Transpose
		for(int l=1; l<= n; l++)
		{
			for(int i=0; i< n; i++)
			{
				System.out.print(l+(n*i) + " ");;
			}
			System.out.println("");
		}
	}
}
