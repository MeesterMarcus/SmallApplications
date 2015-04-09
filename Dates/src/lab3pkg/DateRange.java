package lab3pkg;

/**
 * This is a simple class that will take in two dates
 * and display the range of the two. It is used for
 * when the current date is after the previous date in time.
 * @author Marcus Lorenzana
 *
 */
public class DateRange {
	public String s1;
	public String s2;

	/**
	 * Initialize s1 and s2 to the corresponding dates
	 * @param d1
	 * @param d2
	 */
	public DateRange(Date d1, Date d2) {
		s1 = d1.toString();
		s2 = d2.toString();

	}

	/**
	 * Print the DateRange
	 */
	public String toString() {
		return "DateRange: " + s1 + " - " + s2;
	}

}
