package guy.carPark;

public class Park {
	
	//���
	MyQueue easyRoad = new MyQueue();
	
	//ͣ����
	MyStack carPark = new MyStack();
	
	//��ʱͣ���õ�
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
