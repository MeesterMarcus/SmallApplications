package main;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import length.*;

/**
 * This lab demonstrates inheritance in the form of length conversions. The length package
 * contains all Length classes and Length superclass. The default package contains this main file
 * which will execute and test the data. 
 * @author Marcus Lorenzana
 *
 */

public class Lab4 {

	public static void main(String[] args) {
		
		ArrayList <Length> list = new ArrayList <Length>();
		
		
		Scanner in = null;
		try {
		    in = new Scanner(new File("data.txt"));
		} catch (FileNotFoundException exception) {
		    throw new RuntimeException("failed to open data.txt");
		}
		// need more code for other parts of this assignment
		while (in.hasNextDouble()) {
		    double value = in.nextDouble();
		    String unit = in.next();
		    Length length = null;
		    
		    // code here to use the value of unit to create the
		    // right type of Length object and store it in length.
		    if (unit.indexOf("meter")  ==0){
		    	length = new Meter(value); 
		    	
		    } else if (unit.indexOf("inch")==0){
		    	length = new Inch(value); 
		    	
		    } else if (unit.equals("foot") || unit.equals("feet")){
		    	length = new Foot(value); 
		    	
		    } else if (unit.indexOf("yard")==0){
		    	length = new Yard(value); 
		    	
		    } else {
		    	System.out.println("Invalid input.");
		    	continue; 
		    }
		    
		    // need more code for other parts of this assignment
		    list.add(length);   
		    System.out.println(length);

		}
		// need more code for other parts of this assignment
		printMinMax(list); 
		printFirstLast(list); 
		printLastFirst(list); 
		
		in.close(); 
	
	}
	/**
	 * Prints out the minimum and maximum length of all the lengths
	 * in the data file
	 * @param a
	 */
	public static void printMinMax(ArrayList<Length> a){
		Length minLength = a.get(0); 
		Length maxLength = a.get(0); 
		
		for (int i = 0; i < a.size(); i++){
			if (a.get(i).compareTo(minLength)==-1){
				minLength = a.get(i); 
			} else if (a.get(i).compareTo(maxLength)==1){
				maxLength = a.get(i); 
			} else {
				continue; 
			}
		}
		
		System.out.println("\nMinimum is "+minLength); 
		System.out.println("Minimum is "+maxLength); 
	}
	
	/**
	 * Print the sum of the lengths adding from first to last. 
	 * @param a
	 */
	public static void printFirstLast(ArrayList<Length> a){
		System.out.println("\nSum of Lengths Adding from First to Last");
		Length fMeter = new Meter(0); 
		Length fInch = new Inch(0); 
		Length fFoot = new Foot(0); 
		Length fYard = new Yard(0);
		
		for (int i = 0; i < a.size(); i++){
			fMeter.add(a.get(i)); 
			fInch.add(a.get(i)); 
			fFoot.add(a.get(i)); 
			fYard.add(a.get(i)); 
		}
		
		System.out.println(fMeter);
		System.out.println(fInch);
		System.out.println(fFoot);
		System.out.println(fYard);
		
	}
	
	/**
	 * Print the sum of the lengths adding from last to first. 
	 * @param a
	 */
	public static void printLastFirst(ArrayList <Length> a){
		System.out.println("\nSum of Lengths Adding from Last to First");
		int lastIndex = a.size()-1; 
		Length lMeter = new Meter(0); 
		Length lInch = new Inch(0); 
		Length lFoot = new Foot(0); 
		Length lYard = new Yard(0);
		for (int i = lastIndex; i >= 0; i--){
			lMeter.add(a.get(i)); 
			lInch.add(a.get(i)); 
			lFoot.add(a.get(i)); 
			lYard.add(a.get(i)); 
		}
		
		System.out.println(lMeter);
		System.out.println(lInch);
		System.out.println(lFoot);
		System.out.println(lYard);
		
	}

}
