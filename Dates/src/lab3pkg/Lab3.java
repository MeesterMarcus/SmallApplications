package lab3pkg;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * This is the main class for the project which will test the data from
 * dates.txt. Using this main class, the Date class, and the DateRange class, this
 * program will create Date objects based off the data in dates.txt. It will then
 * check if the next date is later that the previous date, and if so, will create a 
 * DateRange object to print out the timeframe between the two dates. 
 * @author Marcus Lorenzana
 *
 */

public class Lab3 {

	/**
	 * Main function that will read in the data and initialize each Date.
	 * Adds each Date to an ArrayList named dateList.
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = null;
		ArrayList<Date> dateList = new ArrayList<Date>();
		try {
			in = new Scanner(new File("dates.txt"));
		} catch (FileNotFoundException exception) {
			System.err.println("failed to open dates.txt");
			System.exit(1);
		}
		while (in.hasNextLine()) {
			String line = in.nextLine();
			Date date = new Date(line);
			date.initDateArray();
			dateList.add(date);
		}

		produceDateOutput(dateList);

	}

	/**
	 * Takes in a list of Dates in the form of an ArrayList and outputs each date,
	 * followed by its DateRange if eligible. 
	 * @param dateList
	 */
	public static void produceDateOutput(ArrayList<Date> dateList) {
		//Need to store the first Date outside of for loop so we
		//can check previous Dates.
		Date firstDate = dateList.get(0);
		int fmonth = firstDate.dateArr[0];
		int fyear = firstDate.dateArr[2];
		int fday = firstDate.dateArr[1];
		//Check if the date is correct
		String fcheckDate = fyear + "-" + fmonth + "-" + fday;
		boolean fgoodDate = firstDate.isLegalDate(fcheckDate);
		if (fgoodDate) {
			System.out.println(firstDate);
		} else
			System.out.println("Invalid Date");
		//Start the for loop at 1 so we can get the first Date as the previous Date.
		for (int i = 1; i < dateList.size(); i++) {
			int month = dateList.get(i).dateArr[0];
			int year = dateList.get(i).dateArr[2];
			int day = dateList.get(i).dateArr[1];

			String checkDate = year + "-" + month + "-" + day;
			boolean goodDate = dateList.get(i).isLegalDate(checkDate);

			if (goodDate) {
				System.out.println(dateList.get(i));
				int x = dateList.get(i - 1).compareTo(dateList.get(i));
				if (x > 0) {
					DateRange newRange = new DateRange(dateList.get(i - 1),
							dateList.get(i));
					System.out.println(newRange);
				}
			} else
				System.out.println("Invalid Date");
		}

	}

}
