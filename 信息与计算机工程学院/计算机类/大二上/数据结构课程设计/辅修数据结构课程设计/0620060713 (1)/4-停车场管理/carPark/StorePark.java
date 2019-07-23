package guy.carPark;

public class StorePark {
	
	private static Park park = new Park();

	public static Park getPark() {
		return park;
	}

	public static void setPark(Park _park) {
		park = _park;
	}
}
