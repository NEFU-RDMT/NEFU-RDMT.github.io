package guy.carPark;

import java.util.LinkedList;

public class MyStack {
	
	private LinkedList ll = new LinkedList(); 
	
	//栈的最大容量
	private int maxElement = 5;
	
	public int getMaxElement() {
		return maxElement;
	}
	
	//设置最大容量
	public void setMaxElement(int maxElement) {
		this.maxElement = maxElement;
	}

	//压入一个元素进栈
	public void push(Object o)
	{
		if(isFull())
		{
			try {
				throw new StackFullException();
			} catch (StackFullException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		else
		{
			ll.addFirst(o);
		}
	}
	
	//出栈
	public Object pop()
	{
		if(isEmpty())
		{
			try {
				throw new StackNullException();
			} catch (StackNullException e) {
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
	
	//读取
	public Object peek()
	{
		if(isEmpty())
		{
			try {
				throw new StackNullException();
			} catch (StackNullException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return ll.getFirst();
		}
		else
		{
			return ll.getFirst();
		}
	}
	
	//判断栈空
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}
	
	//判断栈满
	public boolean isFull()
	{
		if(ll.size() < maxElement)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	public LinkedList getLl() {
		return ll;
	}

	public void setLl(LinkedList ll) {
		this.ll = ll;
	}
	
}
