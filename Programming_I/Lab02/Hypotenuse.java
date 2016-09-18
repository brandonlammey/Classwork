/*
 * File Name: Hypotenuse
 * Author: Brandon Lammey archerlammey@ku.edu
 * Assignment: EECS168 LAB2_4
 * Description: This program will compute the hypotenuse of a triangle using user input for sides a and b
 * Date: September 14, 2015
 */

import java.util.Scanner;
import java.lang.Math;

public class Hypotenuse 
{
	public static void main(String[] args)
	{
	//declare variables
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	Scanner myScan = new Scanner(System.in);
	
	System.out.println("Using a^2 + b^2 = c^2 to solve for the hypotenuse of a triangle");
	
	//obtain user inputs then plug into formula
	System.out.print("Input a value for a: ");
	a = myScan.nextDouble();
	System.out.print("Input a value for b: ");
	b = myScan.nextDouble();
	c = Math.sqrt((a*a)+(b*b));
	
	System.out.println("The hypotenuse is: " + c);

	
	}
}
