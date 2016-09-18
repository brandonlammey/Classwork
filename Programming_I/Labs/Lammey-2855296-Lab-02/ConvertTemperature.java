
/*
 * File Name: ConvertTemperature
 * Author: Brandon Lammey archerlammey@ku.edu
 * Assignment: EECS168 LAB2_3
 * Description: This program will convert the input temperature from Fahrenheit to Celsius. 
 * Date: September 14, 2015
 */
import java.util.Scanner;

public class ConvertTemperature 
{
	public static void main(String[] args)
	{
		//variable and constant declarations
		double Fahrenheit = 0.0;
		double Celsius = 0.0;
		Scanner userInput = new Scanner(System.in);
		
		//collecting user input
		System.out.println("Enter the temperature in Fahrenheit:");
		Fahrenheit = userInput.nextDouble();
		
		Celsius = (Fahrenheit - 32.0) * (5.0/9.0);
		
		System.out.println("Conversion:");
		System.out.println(Fahrenheit + " degrees Fahrenheit = " + Celsius + " degrees Celsius.");
	}
}
