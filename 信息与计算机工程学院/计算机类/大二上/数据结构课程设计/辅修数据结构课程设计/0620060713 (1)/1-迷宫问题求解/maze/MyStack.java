package guy.maze;

import java.util.LinkedList;

public class MyStack {
	
	private LinkedList ll = new LinkedList ();
	
	//��ջ
	public void push(Object o)
	{
		ll.addFirst(o);
	}
	
	//��ջ
	public Object pop()
	{
		return ll.removeFirst();
	}
	
	//�õ�ջ��Ԫ��
	public Object peek()
	{
		return ll.getFirst();
	}
	
	//�жϿ�
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}
}
