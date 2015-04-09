package length;

/**
 * Subclass of Length, this class is used for operating on the yard unit. 
 * @author Marcus Lorenzana
 *
 */
public class Yard extends Length{

	/**
	 * Yard constructor
	 * @param length
	 */
	public Yard(double length) {
		super(length);
	}

	/**
	 * Add other length to this length and convert
	 */
	public void add(Length other) {
		double otherMeter = other.toMeters(); 
		double otherYard = otherMeter*1.09361; 
		setLength(getLength()+otherYard); 
		
	}

	/**
	 * Get unit of this object
	 */
	public String getUnit() {
		if (getLength() == 1.0){
			return "yard"; 
			} else{
				return "yards";
			}
	}

	/**
	 * Convert to Meters
	 */
	public double toMeters() {
		return getLength()*0.9144;
	}

}
