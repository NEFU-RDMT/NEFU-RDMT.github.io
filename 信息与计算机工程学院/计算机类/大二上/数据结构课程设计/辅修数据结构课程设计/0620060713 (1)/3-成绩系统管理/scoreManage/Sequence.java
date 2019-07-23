package guy.scoreManage;

public class Sequence {
	
	public double[] getOrderscore(double[] arr)
	{
		
		for(int i=1; i<arr.length; i++)
		{
			for(int j=0; j<arr.length-1; j++)
			{
				if(arr[j]<arr[j+1])
				{
					double temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		return null;
	}

}
