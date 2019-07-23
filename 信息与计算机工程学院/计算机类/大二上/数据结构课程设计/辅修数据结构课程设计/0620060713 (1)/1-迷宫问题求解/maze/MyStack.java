package guy.maze;

import java.util.LinkedList;

public class MyStack {
	
	private LinkedList ll = new LinkedList ();
	
	//入栈
	public void push(Object o)
	{
		ll.addFirst(o);
	}
	
	//出栈
	public Object pop()
	{
		return ll.removeFirst();
	}
	
	//得到栈顶元素
	public Object peek()
	{
		return ll.getFirst();
	}
	
	//判断空
	public boolean isEmpty()
	{
		return ll.isEmpty();
	}
}
