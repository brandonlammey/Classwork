/*
 * File Name: ComputeCircleArea
 * Author: Brandon Lammey archerlammey@ku.edu
 * Assignment: EECS168 LAB2_2
 * Description: This program will compute the area of a circle with a user inputed radius.
 * Date: September 14, 2015
 */
import java.util.Scanner;

public class ComputeCircleArea 
{
	public static void main(String[] args)
	{
		//variable and constant declarations
		final double PI = 3.141592;
		double radius;
		double area;
		Scanner userInput = new Scanner(System.in);
		
		//obtain user input for radius
		System.out.println("Input circle radius: ");
		radius = userInput.nextDouble();
		
		//use user input in equation to solve
		area = PI * radius * radius;
		
		System.out.println("The area for the circle of radius " + radius + " is " + area);
	}
}
