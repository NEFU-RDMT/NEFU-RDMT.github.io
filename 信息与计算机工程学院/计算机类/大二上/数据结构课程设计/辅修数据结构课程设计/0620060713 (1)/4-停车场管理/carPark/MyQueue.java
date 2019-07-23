package guy.carPark;

import java.util.LinkedList;

public class MyQueue {

	private LinkedList ll = new LinkedList();
	
	//放入元素
	public void put(Object o)
	{
		ll.addLast(o);
	}
		 
	//取出元素
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
	
	//判断空
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}

}
