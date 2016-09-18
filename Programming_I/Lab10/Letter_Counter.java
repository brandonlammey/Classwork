
/*
 * File Name: Letter_Counter.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab: 10
 * Description: This program takes user input for file names to read in.
 * Try-catch loops are used to verify proper input and handle exceptions. 
 * Once user inputs file name properly, this program will read the file and 
 * count the amount of each letter, case sensitive, and then output the 
 * results to a new file. 
 * Last Changed: November 18, 2015 
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Letter_Counter 
{
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);

		FileReader myFileReader = null;
		BufferedReader myBufferedReader = null;
		FileWriter myFileWriter = null; 
		BufferedWriter myBufferedWriter = null;

		String filename;

		//array to hold counts 
		int countArray[];
		countArray = new int[52];

		//array to hold letters
		char letterArray[];
		letterArray = new char[52];

		for(int i=0; i<26; i++)
		{
			letterArray[(i)] = (char)(65+i);
		}

		for(int i=26; i<52; i++)
		{
			letterArray[i] = (char)(71+i);
		}


		while(true)
		{
			System.out.print("Input a file name: ");
			filename = kb.nextLine();

			//make sure proper user input
			//collect the quantity of each letter into an array
			try
			{

				myFileReader = new FileReader(filename);
				myBufferedReader = new BufferedReader(myFileReader);

				//reach each line and modify as needed
				String line;
				line = myBufferedReader.readLine();
				while(line != null)
				{
					//calculate value of each letter CAPITOLS
					for(int i = 0; i < 26; i++)
					{
						for(int j=0; j< line.length(); j++)
						{
							if(line.charAt(j) == (char)(i+65))
							{
								countArray[i]++;
							}
						}
					}

					//calculate value of each letter LOWERCASE
					for(int i = 26; i < 52; i++)
					{
						for(int j=0; j< line.length(); j++)
						{
							if(line.charAt(j) == (char)(i+71))
							{
								countArray[i]++;
							}
						}

					}


					//Now read in a new line
					line = myBufferedReader.readLine();
				}

				myBufferedReader.close();//close the file
				break;
			}
			catch (Exception e)
			{
				System.out.println("Invalid filename given. Input another.");//print the error
			}
		}

		System.out.println("");

		//create new file
		//print values to new file
		try
		{
			String newFile;
			System.out.print("Input an out file name: ");
			newFile = kb.nextLine();
			myFileWriter = new FileWriter(newFile);
			myBufferedWriter = new BufferedWriter(myFileWriter);


			//print values to file 
			for(int i=0; i<52; i++)
			{
				myBufferedWriter.write(letterArray[i] + " = " + countArray[i]);
				myBufferedWriter.newLine();
			}

			System.out.println("");
			System.out.println("Reading from " + filename);
			System.out.println("");

			myFileReader = new FileReader(filename);
			myBufferedReader = new BufferedReader(myFileReader);

			//print out original file
			String line;
			line = myBufferedReader.readLine();
			
			while(line != null)
			{
				System.out.println(line);
				line = myBufferedReader.readLine();
			}
			
			System.out.println("Results stored in " + newFile);
			
			myBufferedWriter.close();
		}
		catch (Exception e)
		{
			System.err.println("Error: " + e.getMessage());
		}
	}
}
