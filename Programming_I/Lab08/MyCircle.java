
/*
 * File Name: MyCircle.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 8
 * Description: This user defined class with the private variable PI and public variable radius will use methods to 
 * calculate circumference, radius, and diameter of a circle with radius r.
 * Last Changed: November 2, 2015 
 */

public class MyCircle 
{
	//Define the constant PI.
	//The MyCircle class has one property: radius
	public static final double PI = 3.141592; //static variables are initialized outside of a constructor
	private double radius;

	//First create a constructor that sets the radius to 0.0.
	public MyCircle()
	{
		radius = 0.0;
	}
	
	public double getRadius()
	{
		return(radius);
	}
	
	public void setRadius(double r)
	{
		radius = r;
	}

	//Make a method that calculates the diameter of a circle. Recall the radius is half of the diameter.
	//This method will take no parameters and return a double.
	public double diameter()
	{
		double result = radius * 2;
		return (result);
	}

	//Make a method that returns the area of a Circle.
	//This method takes no parameters.  It returns a double.
	public double area()
	{
		double result = MyCircle.PI * radius * radius;
		return (result);
	}

	//Make a method that returns the circumference of a Circle.
	//This method takes no parameters.  It returns a double.
	public double circumference()
	{
		double result = 2 * MyCircle.PI * radius;
		return (result);
	}

}
