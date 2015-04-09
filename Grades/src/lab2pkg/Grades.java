package lab2pkg;

import java.util.Arrays;

/**
 * This is the Grades class which has several functions that carries
 * out the operations on the grades. When a new Grade object is initialized
 * it will get a blank name and an array of grades. You can call its methods to 
 * add a new name or a new grade and also find the min,max,median, and average 
 * of the grades for the corresponding Grades object. 
 * 
 * @author Marcus Lorenzana
 *
 */

public class Grades {
	
	private int numGrades = 0; 
	private String name;
	private int[] grades;
	
	/**
	 * This is the constructor for Grades. Simply sets name
	 * to blank and initializes the grades array. 
	 */
	public Grades(){
		name = "";
		grades = new int[20];
	}
	
	/**
	 * Add a name to the Grades object.
	 * @param s
	 */
	public void addName(String s){
		name = s; 
	}
	
	/**
	 * Add a grade to "grades" inside the  corresponding Grades
	 * object.
	 * @param x
	 */
	public void addGrade(int x){
		
		if (numGrades >= grades.length){
			int newGrades[] = new int[grades.length*2];
			for (int i = 0; i < grades.length; i++) {
				newGrades[i] = grades[i]; 
			}
			grades = newGrades;
		}
		grades[numGrades]=x;
		numGrades++; 
	}

	/**
	 * Get the name of the student in this Grades object.
	 * @return name
	 */
	public String getName() {
		return name; 
	}
    
	/**
	 * Get the total number of grades for the corresponding
	 * student.
	 * @return numGrades
	 */
	public int length() {
		return numGrades;
	}
	
	/**
	 * Get the average of the student's grades.
	 * @return sum/numGrades
	 */
	public double average() {
		double sum = 0; 
		for (int i = 0; i < numGrades; i++){
			sum+=grades[i];
		}
		return sum/numGrades;
	}

	/**
	 * Get the median of the student's grades.
	 * @return median
	 */
	public double median() {
		//Have to create a temporary grades array to
		//make sure there are no zeroes in the array
		//that will count as grades.
		int[] t_grades = new int[numGrades];
		for (int i = 0; i < numGrades; i++){
			t_grades[i] = grades[i];
		}
		
		Arrays.sort(t_grades);
		
		double median;
		if (numGrades % 2 == 1){
			median= t_grades[numGrades/2]; 
		} else {
			double grade1 = t_grades[numGrades/2-1];
			double grade2 = t_grades[numGrades/2];
			median= (grade1+grade2)/2;
		}
		return median;
		
	}

	/**
	 * Get the highest score from the student's grades.
	 * @return max
	 */
	public int maximum() {
		int max =grades[0]; 
		for (int i = 1; i < numGrades; i++){
			if (grades[i] > max)
				max = grades[i];
		}
		return max; 
	}

	/**
	 * Get the minimum score from the student's grades.
	 * @return min
	 */
	public int minimum() {
		int min =grades[0]; 
		for (int i = 1; i < numGrades; i++){
			if (grades[i] < min)
				min = grades[i];
		}
		return min; 
	}
	
	/**
	 * Create a string that will ouput the student's name
	 * and their grades.
	 */
	public String toString(){
		String s = name+" [";
		for (int i = 0; i < numGrades; i++){
			if (i != numGrades-1)
				s = s + grades[i] +", ";
			else
				s = s + grades[i];
		}
		s = s + "]";
		return s; 
	}
	
}
