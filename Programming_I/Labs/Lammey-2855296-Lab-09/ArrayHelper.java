/*
 * File Name: ArrayHelper.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 9
 * Description: This user defined class will take an array passed in and can print all values in the array,
 * calculate the sum and average of each line and the entire array, and find the maximum integer value in the array.  
 * Last Changed: November 9, 2015 
 */
public class ArrayHelper 
{
	int sum1D;
	double avg1D;
	int sum2D;
	double avg2D;
	int largestValue; 
	
	
	
	//constructor 
	public ArrayHelper()
	{
		sum1D = 0;
		avg1D = 0.0;
		sum2D = 0;
		avg2D = 0.0;
		largestValue=0;
	 
	}
	
	//takes and prints 2D Array
	public void print2dArray(int[ ][ ] array)
	{
		for(int i=0; i<array.length; i++)
		{
			for(int j=0; j< array[i].length; j++)
			{
				System.out.print(array[i][j]);
				if(j< array[i].length-1)
				{
					System.out.print(", ");
				}
			}
			System.out.println("");
		}
	}

	
	
	//takes 1D array and returns sum of values 
	public int arraySum(int[] array)
	{
		sum1D = 0;
		for(int i=0; i<array.length; i++)
		{
			sum1D += array[i];
		}
		return(sum1D);
	}
	//returns 1D sum
	public int getArraySum()
	{
		return(sum1D);
	}
	
	

	
	//takes in 1D array and returns average of values
	public double arrayAvg(int[] array)
	{
		avg1D = 0;
		
		for(int i=0; i<array.length; i++)
		{
			avg1D += array[i];
		}
		avg1D = avg1D/array.length; 
		
		return(avg1D);
	}
	public double getArrayAverage()
	{
		return(avg1D);
	}
	
	
	
		
	//takes in a 2D array and returns the sum of all values 
	public int arraySum2D(int[][] array)
	{
		sum2D=0;
		for(int i=0; i<array.length; i++)
		{
			for(int j=0; j<array[i].length; j++)
			{
				sum2D += array[i][j];
			}
		}
		return(sum2D);
	}
	
	
	
	
	//takes in 2D array and returns average of values
	public double arrayAvg2D(int[][] array)
	{
		avg2D=0;
		for(int i=0; i<array.length; i++)
		{
			for(int j=0; j<array[i].length; j++)
			{
				avg2D += array[i][j];
			}
		}
		avg2D = avg2D / (array.length * array[0].length);
		return(avg2D);
	}
	
	
	
	
	//takes in 2D array and returns largest value
	public int arrayMax2D(int[][] array)
	{
		largestValue = array[0][0];
		
		for(int i=0; i< array.length;i++)
		{
			for(int j=0; j<array[i].length; j++)
			{
				if(largestValue < array[i][j])
				{
					largestValue = array[i][j];
				}
			}
		}
		return(largestValue);
	}
	
}
