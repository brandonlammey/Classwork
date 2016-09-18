/* 
 * File Name: ColorRange.java
 * Author: Brandon Lammey
 * KUID: 2855296
 * Assignment: EECS168 Lab3.1
 * Description: Program will take user inputed wavelength in nanometers
 * and use an if-else statement to determine the corresponding color in the visible spectrum 
 * Date: September 21, 2015
 */

import java.util.Scanner;

public class ColorRange 
{
	public static void main(String[] args)
	{
		double frequency = 0.0;
		String color = "";
		Scanner myScan = new Scanner(System.in);
		
		System.out.println("Enter a wavelength in nm: ");
		frequency = myScan.nextDouble();
		
		//Use if-else statement to determine color based on wavelength
		//If not part of the color spectrum print message stating not part of spectrum 
		if(380 <= frequency && frequency < 450)
		{
			color = "Violet";
			System.out.println("The color is " + color);
		}
		else if(450 <= frequency && frequency < 495)
		{
			color = "Blue";
			System.out.println("The color is " + color);
		}
		else if(495 <= frequency && frequency < 570)
		{
			color = "Green";
			System.out.println("The color is " + color);
		}
		else if(570 <= frequency && frequency < 590)
		{
			color = "Yellow";
			System.out.println("The color is " + color);
			
		}
		else if(590 <= frequency && frequency < 620)
		{
			color = "Orange";
			System.out.println("The color is " + color);
		}
		else if(620 <= frequency && frequency < 750)
		{
			color = "Red";
			System.out.println("The color is " + color);
		}
		else
		{
			color = "";
			System.out.println("The entered wavelength is not part of the visable spectrum");
		}
		
	}
}
