package guy.carPark;

public class Customer {
	
	public static void main(String[] args)
	{
		ManageCarPark mcp = new ManageCarPark();
		//车库的车位为5个!!!!!
		
		mcp.inCar("a");
		mcp.inCar("b");
		mcp.inCar("c");
		mcp.inCar("d");
		mcp.inCar("e");
		mcp.inCar("f");
		mcp.inCar("g");
		System.out.println(mcp.outCar("d"));
		System.out.println(mcp.outCar("a"));
		System.out.println(mcp.outCar("b"));
		System.out.println(mcp.outCar("c"));
		System.out.println(mcp.outCar("f"));
		System.out.println(mcp.outCar("h"));
		System.out.println(mcp.outCar("g"));
	}

}
