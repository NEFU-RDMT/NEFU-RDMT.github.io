package guy.carPark;

public class Park {
	
	//便道
	MyQueue easyRoad = new MyQueue();
	
	//停车场
	MyStack carPark = new MyStack();
	
	//临时停车用的
	MyStack tempPark = new MyStack();

	public MyStack getCarPark() {
		return carPark;
	}

	public void setCarPark(MyStack carPark) {
		this.carPark = carPark;
	}

	public MyQueue getEasyRoad() {
		return easyRoad;
	}

	public void setEasyRoad(MyQueue easyRoad) {
		this.easyRoad = easyRoad;
	}

	public MyStack getTempPark() {
		return tempPark;
	}

	public void setTempPark(MyStack tempPark) {
		this.tempPark = tempPark;
	}
}
