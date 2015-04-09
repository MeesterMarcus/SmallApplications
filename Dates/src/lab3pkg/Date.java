package lab3pkg;

import java.text.ParsePosition;
import java.text.SimpleDateFormat;
import java.util.Scanner;

/**
 * This class will do most of the work in processing the Dates. It will initialize the Date, 
 * convert the date into a numeric format, and compare two Dates using the compareTo function.
 * @author Marcus Lorenzana
 *
 */

public class Date implements Comparable<Date> {
	String date;
	int dateArr[];

	/**
	 * Main constructor for initializing the String date and integer dateArr array.
	 * @param line
	 */
	public Date(String line) {
		date = line;
		dateArr = new int[3];
	}

	/**
	 * Compare two dates and check whether or not one is after, before, or equal
	 * to the other.
	 */
	public int compareTo(Date o) {
		if (dateArr[2] != o.dateArr[2]) {
			return Integer.compare(o.dateArr[2], dateArr[2]);
		} else if (dateArr[0] != o.dateArr[0]) {
			return Integer.compare(o.dateArr[0], dateArr[0]);
		} else {
			return Integer.compare(o.dateArr[1], dateArr[1]);
		}
	}

	/**
	 * Print the Date
	 */
	public String toString() {
		return "Date: " + date;
	}

	/**
	 * Initialize the date to the integer array dateArr. This will allow for
	 * easier processing of the data and comparisons.
	 */
	public void initDateArray() {
		String m;
		int d, y;
		Scanner scanner = new Scanner(date);

		//Need to create separate scanners for each part of the date,
		//mainly because of the comma.
		Scanner monScanner = new Scanner(scanner.next());
		Scanner dayScanner = new Scanner(scanner.next());
		Scanner yrScanner = new Scanner(scanner.next());

		monScanner.useDelimiter(" ");
		m = monScanner.next();

		dayScanner.useDelimiter(",");
		d = dayScanner.nextInt();

		yrScanner.useDelimiter(" ");
		y = yrScanner.nextInt();

	    //Initialize dateArr
		dateArr[0] = getMonthNum(m);
		dateArr[1] = d;
		dateArr[2] = y;

		//Close scanners
		monScanner.close();
		dayScanner.close();
		yrScanner.close();
		scanner.close();

	}

	/**
	 * This function will take in a string s in the format
	 * of yyyy-MM-dd and check to see if date is correct.
	 * @param s
	 * @return true or false
	 */
	boolean isLegalDate(String s) {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		sdf.setLenient(false);
		return sdf.parse(s, new ParsePosition(0)) != null;
	}

	/**
	 * Get the number equivalent of the month so we can do
	 * comparisons on which is after the other, etc.
	 * @param month
	 * @return m
	 */
	public int getMonthNum(String month) {
		int m;

		if (month.indexOf("Jan") != -1) {
			m = 1;
		} else if (month.indexOf("Feb") != -1) {
			m = 2;
		} else if (month.indexOf("Mar") != -1) {
			m = 3;
		} else if (month.indexOf("Apr") != -1) {
			m = 4;
		} else if (month.indexOf("May") != -1) {
			m = 5;
		} else if (month.indexOf("Jun") != -1) {
			m = 6;
		} else if (month.indexOf("Jul") != -1) {
			m = 7;
		} else if (month.indexOf("Aug") != -1) {
			m = 8;
		} else if (month.indexOf("Sep") != -1) {
			m = 9;
		} else if (month.indexOf("Oct") != -1) {
			m = 10;
		} else if (month.indexOf("Nov") != -1) {
			m = 11;
		} else if (month.indexOf("Dec") != -1) {
			m = 12;
		} else {
			m = -1;
		}

		return m;
	}

}
