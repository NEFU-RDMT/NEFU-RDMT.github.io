package guy.carPark;

import java.util.LinkedList;

public class MyStack {
	
	private LinkedList ll = new LinkedList(); 
	
	//ջ���������
	private int maxElement = 5;
	
	public int getMaxElement() {
		return maxElement;
	}
	
	//�����������
	public void setMaxElement(int maxElement) {
		this.maxElement = maxElement;
	}

	//ѹ��һ��Ԫ�ؽ�ջ
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
	
	//��ջ
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
	
	//��ȡ
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
	
	//�ж�ջ��
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}
	
	//�ж�ջ��
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
