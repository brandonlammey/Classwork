/*
 * File Name: BananaStand.java
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework Assignment Number: Homework01
 * Description: This program will collect user inputs for a type of banana, 
 * 	color of banana, and quantity of bananas. Using this information a
 * 	markup will be added based on type of banana, a discount will be calculated 
 * 	based on color of bananas, and the total cost of bananas including 
 * 	initial cost, markups,and discounts will be calculated. This program 
 * 	assumes the user will input type, color, and quantity of bananas correctly 
 * 	using positive int values for quantity, (r, o, g, R, O, G) for type, 
 * 	and (y, g, m ,Y, G, M) for color.
 * Last Changed: September 25, 2015
 */
		 

import java.util.Scanner;

public class BananaStand 
{
	
	public static void main(String[] args)
	{
		//declare and initialize variables
		int bananas = 0;
		String initialType = "";
		char type ='\0';
		String initialColor = "";
		char color = '\0';
		double initialCost = 0.00; 
		double markups = 0.00;
		double discounts = 0.00;
		double totalCost  = 0.00;
		Scanner myScan = new Scanner(System.in);
		
		String city = "";
		String state ="";
		String streetAddress = "";
		int zipCode = 0;
		
		//greet user
		System.out.println("Welcome to the Banana Stand!"); 

		System.out.println("--------------------");
	
		//Take user input for banana type
		System.out.println("Select type of banana: ");
		System.out.println("Regular (r/R) (no markup)");
		System.out.println("Organic (o/O) (20% markup)");
		System.out.println("Saturated with Gamma Rays (g/G) (50% markup)");
		System.out.print("Input your choice: ");
		initialType = myScan.nextLine();
		initialType = initialType.toLowerCase(); //convert choice to lower case
		type = initialType.charAt(0); //Using string input for char variable
		

		System.out.println("--------------------");
	
		//Take user input for banana color
		System.out.println("Select color of banana: ");
		System.out.println("Yellow (y/Y) (no discount)");
		System.out.println("Green (g/G) (10% discount)");
		System.out.println("Mixed (m/M) (5% discount)");
		System.out.print("Input your choice: ");
		initialColor = myScan.nextLine();
		initialColor = initialColor.toLowerCase(); //convert choice to lower case
		color = initialColor.charAt(0); //Using string input for char variable

		System.out.println("--------------------");
		
		//Take user input for banana quantity 
		System.out.print("How many bananas do you want?: ");
		bananas = myScan.nextInt();
		myScan.nextLine(); //purge scanner for address information
		
		System.out.println("--------------------");
		
		//take use address information
		System.out.print("Input your street address: ");
		streetAddress = myScan.nextLine();
		System.out.print("Input your city: ");
		city = myScan.nextLine();
		System.out.print("Input your state: ");
		state = myScan.nextLine();
		System.out.print("Input your zipcode: ");
		zipCode = myScan.nextInt();
		
		System.out.println("--------------------");
		
		//Initial cost of bananas
		initialCost = 0.03 * bananas; 
				
		//value of mark up
		if(type == 'o')
		{
			markups = 0.20*initialCost;
		}
		else if(type == 'g')
		{
			markups = 0.50*initialCost;
		}
		else
		{
			markups = 0.00;
		}

		//value of discount
		if(color == 'g')
		{
			discounts = 0.10*initialCost;
		}
		else if(color == 'm')
		{
			discounts = 0.05*initialCost;
		}
		else
		{
			discounts = 0.00;
		}

		//total cost of bananas
		totalCost = initialCost + markups - discounts;

		//Print initial cost, mark up, discount, and cost
		System.out.printf("Total cost for " + bananas + " banana(s) before markups or discounts: $%.2f", initialCost);
		System.out.println();
		System.out.printf("Total markups: $%.2f", markups);
		System.out.println();
		System.out.printf("Total discount: $%.2f", discounts);
		System.out.println();
		System.out.printf("Total cost: $%.2f", totalCost);
		System.out.println();
		
		//Print Shipping information
		System.out.println("Shipping to: ");
		System.out.println("\t" + streetAddress);
		System.out.println("\t" + city);
		System.out.println("\t" + state);
		System.out.println("\t" + zipCode);
	}
}