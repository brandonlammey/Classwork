/*
 * File Name: MethodPractice.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 4.1
 * Description: Using methods to solve problems this program will take user inputed int values
 * and choose the large value, take a user inputed radius for a sphere and calculate the area,
 * and take a user inputed string and print out the string "print" times with the user inputing
 * an int value for "print". 
 * Last Changed: October 5, 2015 
 */

import java.util.Scanner;

public class MethodPractice 
{
	public static void main(String[] args)
	{
		//variables for max value
		int x=0;
		int y=0;
		//variables for radius
		double radius = 0.0;
		//variables for printWord
		String userWord = "";
		int print = 0;
		//Scanner
		Scanner myScan = new Scanner(System.in);
		
		
		//receives variables for max value 
		System.out.println("Input two numbers:");
		x = myScan.nextInt();
		y = myScan.nextInt();
		int z=max(x, y);//call on method "max"
		//calls on method "max" to choose max value
		System.out.println("The max of " + x + " and " + y + " is: " + z);
		System.out.println("");
		
		//receives a value for radius
		System.out.print("Input a radius: ");
		radius = myScan.nextDouble();
		double area = SphereArea(radius); // call on Method "SphereArea"
		//calls on method "SphereArea" to calculate area
		System.out.println("The area of a sphere with this radius is: " + area);
		System.out.println("");
		
		userWord = myScan.nextLine();//purge remainder in scanner
		
		//Asks for a string and amount of times to print then outputs 
		System.out.println("Input a string:");
		userWord = myScan.nextLine();
		System.out.println("");
		System.out.print("How many times do you want to print it?: ");
		print = myScan.nextInt();
		printWord(userWord, print); //calls on function
		
	}
	public static int max(int a, int b)//determines max value using if statement 
	{
		int maxNum = 0;
		
		if(a > b)
		{
			maxNum = a;
		}
		else
		{
			maxNum = b;
		}
		return (maxNum);
	}
	
	public static double SphereArea(double r)
	{
		double area = 0.0;
		
		if (r>0.0)
		{
			area = 4*3.14159*r*r;
		}
		else
		{
			area = 0.0;
		}
		return area;
	}
	public static void printWord(String word, int timesToPrint)
	{
		for(int i=0; i<timesToPrint; i++)
		{
			System.out.println(word);
		}
	}
}
