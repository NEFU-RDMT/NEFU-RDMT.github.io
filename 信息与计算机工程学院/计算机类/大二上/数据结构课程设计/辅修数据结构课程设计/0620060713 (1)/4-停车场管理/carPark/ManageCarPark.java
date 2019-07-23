package guy.carPark;

public class ManageCarPark {
	
	private Park park;
	
	public void inCar(String carName)
	{
		park = StorePark.getPark();
		
		if(! park.getCarPark().isFull())//停车场不满
		{
			System.out.println(carName+"车已经存好");
			park.getCarPark().push(carName);
		}
		else//停车场满
		{
			park.getEasyRoad().put(carName);
			System.out.println("停车场满,"+carName+"车在便道上排队");
		}
		
		StorePark.setPark(park);
		System.out.println();
	}
	
	public String  outCar(String carName)
	{
		park = StorePark.getPark();
		
		System.out.println();
		System.out.println("取车开始");
		String theCar = "";
		
		park = StorePark.getPark();
		int temp = park.getCarPark().getLl().indexOf(carName);;
		if(temp == -1)//判断停车场里 有没有这个car
		{
			theCar = "停车场里没有车"+carName;
			System.out.println(theCar);
		}
		else
		{
			for(int i=0; i<temp; i++)//把要取的车之前的车取出来放进临时的停车处
			{
				String car = (String) park.getCarPark().pop();
				System.out.println(car+"车从车库放在临时停车位;为车"+carName+"让道");
				park.getTempPark().push(car);
			}
			//把要取的车取出来
			theCar = (String) park.getCarPark().pop()  + "从车库中取出";
			System.out.println(theCar+"从车库中取出来");
			
			// 把临时停车处的车放进停车场
			for(int i=0; i<temp; i++)
			{
				String car = (String) park.getTempPark().pop();
				System.out.println(car+"车从临时停车位开进车库");
				park.getCarPark().push(car);
			}
			
			//判断便道上有没有车 如果有 放进停车场一辆
			if(! park.getEasyRoad().isEmpty())
			{
				String car = (String) park.getEasyRoad().get();
				System.out.println(car+"车从便道开进车库");
				park.getCarPark().push(car);
			}
		}
		System.out.println("取车结束");
		StorePark.setPark(park);
		return theCar;
	}

}
