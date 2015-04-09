package length;

/**
 * Subclass of Length, this class is used for operating on the inch unit. 
 * @author Marcus Lorenzana
 *
 */
public class Inch extends Length {

	/**
	 * Inch constructor
	 * @param length
	 */
	public Inch(double length) {
		super(length);
	}

	/**
	 * Add other length to this length and convert
	 */
	public void add(Length other) {
		double otherMeter = other.toMeters(); 
		double otherInch = otherMeter*39.3701; 
		setLength(getLength()+otherInch); 
	}

	/**
	 * Get unit of this object
	 */
	public String getUnit() {
		if (getLength() == 1.0){
			return "inch"; 
			} else{
				return "inches";
			}
	}

	/**
	 * Convert to Meters
	 */
	public double toMeters() {
		return getLength()*0.0254;
	}

}
