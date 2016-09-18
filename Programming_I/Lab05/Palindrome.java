/*
 * File Name: Palindrome.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 4.3
 * Description:The program will take a user input integer number and using methods it will find the length
 * and reverse of the number and determine if the number is a palindrome. The program will loop until the 
 * user is done inputing integer numbers.
 * Last Changed: October 5, 2015 
 */

import java.util.Scanner;

public class Palindrome 
{
	public static void main(String[] args)
	{
		//variable declarations 
		int num = 0;
		int reverseNum = 0;
		int length = 0;
		int loop = 1;
		Scanner myScan = new Scanner(System.in);
		
		//looping statement 
		do
		{
			System.out.println("Please enter a Number:");
			num = myScan.nextInt();
			length = lengthOfNumber(num);
			reverseNum = reverse(num);//method call to determine reverse of the number
						
			System.out.println("The length of the number is: " + length);
			System.out.println("The reverse of the number is: " + reverseNum);
			
			num = num-reverseNum;//used for Palindrome method
				
			if(isPalindrome(num)==true)
			{
				System.out.println("The number is a Palindrome.");
			}
			else
			{
				System.out.println("The Number is not a Palindrome.");
			}
						
			System.out.println("");
		
			System.out.println("Want to try it again?(y=1/n=0)");
			loop = myScan.nextInt();
			
			System.out.println("");			
			
		}while(loop==1);
		
		System.out.println("Thank you!");
		
	}
	//method to determine if input is a Palindrome 
	public static boolean isPalindrome(int x)
	{
		//if the number is a palindrome then number-reverseNumber will = 0
		if(x==0)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	//method to determine the reverse of the input
	public static int reverse(int x)
	{
		int reverse = 0;//variable to be calculated and returned
		
		do//loop to reverse number
		{
			reverse = reverse*10;
			reverse = reverse +x%10;
			x=x/10;
		}while(x>0);
		return(reverse);
	}
	//method to determine the length of the inputed number
	public static int lengthOfNumber(int x)
	{
		int length = 0;//variable to be calculated and returned
		
		do
		{
			x=x/10;
			length = length+1;
		}while(x>0);
		return(length);
	}
}
