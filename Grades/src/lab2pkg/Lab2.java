package lab2pkg;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * This is the main class that tests the methods and the functionality
 * of the Grades.java class. It reads from a file "data.txt" that contains
 * the names of students and their grade and will add that data to each
 * Grades object, with each object being on student and their grades. It then
 * tests all the functions of the Grades class.
 * 
 * @author Marcus Lorenzana
 *
 */

public class Lab2 {

	/**
	 * Main method for testing.
	 * @param args
	 */
	public static void main(String[] args) {
		//Create an array of Grades
		Grades[] g = new Grades[4];
		
		//Initialize each Grades object
	    for (int i = 0; i < g.length; i++) {
	    	g[i] = new Grades();
	    }
		
	    //Counter that respresents each Grades object
	    int n = 0; 
	    
	    //Read data from file and initialize
		Scanner in = null;
		try {
		    in = new Scanner(new File("data.txt"));
		} catch (FileNotFoundException exception) {
		    System.err.println("failed to open data.txt");
		    System.exit(1);
		}
		while (in.hasNext()) {
			
		    String name = in.next();
		    g[n].addName(name); 
		    
		    while (in.hasNextInt()) {
		        int grade = in.nextInt();
		        g[n].addGrade(grade); 
		    }
		    n++;
		    
		}    
		
		//Test the functions on each Grades object
		for (int i = 0; i < g.length; i++) {
			testGrades(g[i]);
		}
		

	}
	
	/**
	 * Function that tests methods in Grades.java
	 * @param grades
	 */
	public static void testGrades(Grades grades) {
	    System.out.println(grades.toString()); 
	    System.out.printf("\tName:    %s\n", grades.getName());
	    System.out.printf("\tLength:  %d\n", grades.length());
	    System.out.printf("\tAverage: %.2f\n", grades.average());
	    System.out.printf("\tMedian:  %.1f\n", grades.median());
	    System.out.printf("\tMaximum: %d\n", grades.maximum());
	    System.out.printf("\tMininum: %d\n", grades.minimum());
	   
	}

}
