
/*
 * File Name: CircleArea.java
 * Author: Brandon Lammey archerlammey@ku.edu
 * Assignment: EECS168 LAB2_1
 * Description: This program will compute the area of a circle with a hard-coded radius.
 * Date: September 14, 2015
 */
public class CircleArea 
{
public static void main(String[] args)
	{
	//variable and constant declarations
	final double PI = 3.141592;
	double radius;
	double area;
	
	radius = 20.0;
	area = PI * radius * radius;
	
	System.out.println("The area for the circle of radius " + radius + " is " + area);
	
	}
}
