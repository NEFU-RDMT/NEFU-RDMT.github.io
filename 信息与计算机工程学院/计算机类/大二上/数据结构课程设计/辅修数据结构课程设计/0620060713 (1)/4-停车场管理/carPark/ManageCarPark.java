package guy.carPark;

public class ManageCarPark {
	
	private Park park;
	
	public void inCar(String carName)
	{
		park = StorePark.getPark();
		
		if(! park.getCarPark().isFull())//ͣ��������
		{
			System.out.println(carName+"���Ѿ����");
			park.getCarPark().push(carName);
		}
		else//ͣ������
		{
			park.getEasyRoad().put(carName);
			System.out.println("ͣ������,"+carName+"���ڱ�����Ŷ�");
		}
		
		StorePark.setPark(park);
		System.out.println();
	}
	
	public String  outCar(String carName)
	{
		park = StorePark.getPark();
		
		System.out.println();
		System.out.println("ȡ����ʼ");
		String theCar = "";
		
		park = StorePark.getPark();
		int temp = park.getCarPark().getLl().indexOf(carName);;
		if(temp == -1)//�ж�ͣ������ ��û�����car
		{
			theCar = "ͣ������û�г�"+carName;
			System.out.println(theCar);
		}
		else
		{
			for(int i=0; i<temp; i++)//��Ҫȡ�ĳ�֮ǰ�ĳ�ȡ�����Ž���ʱ��ͣ����
			{
				String car = (String) park.getCarPark().pop();
				System.out.println(car+"���ӳ��������ʱͣ��λ;Ϊ��"+carName+"�õ�");
				park.getTempPark().push(car);
			}
			//��Ҫȡ�ĳ�ȡ����
			theCar = (String) park.getCarPark().pop()  + "�ӳ�����ȡ��";
			System.out.println(theCar+"�ӳ�����ȡ����");
			
			// ����ʱͣ�����ĳ��Ž�ͣ����
			for(int i=0; i<temp; i++)
			{
				String car = (String) park.getTempPark().pop();
				System.out.println(car+"������ʱͣ��λ��������");
				park.getCarPark().push(car);
			}
			
			//�жϱ������û�г� ����� �Ž�ͣ����һ��
			if(! park.getEasyRoad().isEmpty())
			{
				String car = (String) park.getEasyRoad().get();
				System.out.println(car+"���ӱ����������");
				park.getCarPark().push(car);
			}
		}
		System.out.println("ȡ������");
		StorePark.setPark(park);
		return theCar;
	}

}
