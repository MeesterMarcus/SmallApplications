package length;

/**
 * Subclass of Length, this class is used for operating on the foot unit. 
 * @author Marcus Lorenzana
 *
 */
public class Foot extends Length{

	/**
	 * Foot constructor
	 * @param length
	 */
	public Foot(double length) {
		super(length);
	}

	/**
	 * Add other length to this length and convert
	 */
	public void add(Length other) {
		double otherMeter = other.toMeters(); 
		double otherFoot = otherMeter*3.28084; 
		setLength(getLength()+otherFoot); 
	}

	/**
	 * Get unit of this object
	 */
	public String getUnit() {
		if (getLength() == 1.0){
			return "foot"; 
			} else{
				return "feet";
			}
	}

	/**
	 * Convert to Meters
	 */
	public double toMeters() {
		return getLength()*0.3048;
	}

}
