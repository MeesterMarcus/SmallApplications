package length;

/**
 * Subclass of Length, this class is used for operating on the meter unit. 
 * @author Marcus Lorenzana
 *
 */
public class Meter extends Length {

	/**
	 * Meter constructor
	 * @param length
	 */
	public Meter(double length) {
		super(length);
	}

	/**
	 * Add other length to this length and convert
	 */
	public void add(Length other) {
		double otherMeter = other.toMeters(); 
		setLength(getLength()+otherMeter); 
	}

	/**
	 * Get unit of this object
	 */
	public String getUnit() {
		if (getLength() == 1.0){
		return "meter"; 
		} else{
			return "meters";
		}
	}

	/**
	 * Convert to Meters
	 */
	public double toMeters() {
		return getLength();
	}

}
