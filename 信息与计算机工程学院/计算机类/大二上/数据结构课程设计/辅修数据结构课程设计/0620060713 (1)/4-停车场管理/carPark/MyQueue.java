package guy.carPark;

import java.util.LinkedList;

public class MyQueue {

	private LinkedList ll = new LinkedList();
	
	//����Ԫ��
	public void put(Object o)
	{
		ll.addLast(o);
	}
		 
	//ȡ��Ԫ��
	public Object get()
	{
		if(isEmpty())
		{
			try {
				throw new QueueNullException();
			} catch (QueueNullException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return ll.removeFirst();
		}
		else
		{
			return ll.removeFirst();
		}
	}
	
	//�жϿ�
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}

}
