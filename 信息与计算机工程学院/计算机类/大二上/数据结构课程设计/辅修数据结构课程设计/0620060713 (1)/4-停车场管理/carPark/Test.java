package guy.carPark;

public class Test {
	
	public static void main(String[] args)
	{
		ManageCarPark mcp = new ManageCarPark();
		//����ĳ�λΪ5��!!!!!
		
		mcp.inCar("a");
		mcp.inCar("b");
		mcp.inCar("c");
		mcp.inCar("d");
		mcp.inCar("e");
		mcp.inCar("f");
		mcp.inCar("g");
		
		mcp.outCar("a");
		mcp.outCar("d");
		mcp.outCar("g");
		mcp.outCar("h");
		mcp.outCar("e");
		mcp.outCar("b");
		mcp.outCar("f");
		mcp.outCar("c");
		mcp.outCar("g");
		mcp.outCar("i");
	}

}
