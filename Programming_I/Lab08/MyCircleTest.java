
/*
 * File Name: MyCircleTest.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 8
 * Description: This program will take a user input for radius and then using the user defined class MyCircle.java
 * will display the are, circumference, and radius of a circle of radius r.  
 * Last Changed: November 2, 2015 
 */


import java.util.Scanner;

public class MyCircleTest 
{
	public static void main(String[] args) 
	{

		// Declare a new circle called myCircle
		// Declare any other variables you need (e.g. Scanner, double)
		MyCircle userCircle = new MyCircle();
		Scanner kb = new Scanner(System.in);
		
		//Get a radius from the user
		System.out.print("Input a radius: ");
		userCircle.setRadius(kb.nextDouble());
		
		//Use the method area() from myCircle to print the area                         
		System.out.println("The area is: " + userCircle.area());
		
		//Use the method circumference() from myCircle to print the circumference
		System.out.println("The circumference is: " + userCircle.circumference());
		
		//Using only a method call to diameter()  to print the diameter
		System.out.println("The diameter is: " + userCircle.diameter());
	}
}
