
/*
 * File Name: KUStudentTest.java
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Lab Number: 8
 * Description: This program will create a file using a user defined class
 * by using a user taking user name, KUID, and department. Then the program will print the file  
 * Last Changed: November 2, 2015 
 */

import java.util.Scanner;

public class KUStudentTest 
{
	public static void main(String[] args)
	{
		//variables
		KUStudent userStudent = new KUStudent();
		Scanner kb = new Scanner(System.in);
		
		//get name from user EASY WAY
		System.out.println("Please input the student's name (firstname lastname):");
		userStudent.set_name(kb.next(),kb.next());
		
		//DIFFICULT WAY 
		//String test= "Brandon Lammey";
		//String[] arr=test.split(" ");
		//arr[0];
		//arr[1];
		
		System.out.println("Please input the student's KUID and department:");
		userStudent.set_kuinfo(kb.next(),kb.next());
		
		System.out.println("");
		//Output student, KUID, and department 
		System.out.println("Student: " + userStudent.get_fname() + " " + userStudent.get_lname());
		System.out.println("KUID: " + userStudent.get_id());
		System.out.println("Department: " + userStudent.get_dept());
		
	}
}
