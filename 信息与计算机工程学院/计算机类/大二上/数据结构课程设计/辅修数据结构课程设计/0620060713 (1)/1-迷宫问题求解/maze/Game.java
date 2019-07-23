package guy.maze;

public class Game {
	
	private Maze m = new Maze();
	private int[][] maze;
	private MyStack stack = new MyStack();
	private int xMaze;//������ʾ�Թ�����
	private int yMaze;//������ʾ�Թ�����
	private Unit nowUnit;//��ŵ�ǰ���Թ���λ
	
	//��ʼ��һ���Թ�
	//1��ʾ��· 0��ʾ��ǽ 3��ʾ��� 9��ʾ���� 6��ʾ�õ�λ�Ѿ��߹�
	private void getMaze(int[][] aMaze)
	{
		xMaze = aMaze.length;
		yMaze = aMaze[aMaze.length-1].length;
		m.setMaze(aMaze);
	}
	
	//�����Թ��ҵ����
	private void getEntrance()
	{
		boolean flag = false;//��������ѭ��
		
		nowUnit = new Unit();
		maze = m.getMaze();
		
		for(int i=0; i<xMaze; i++)
		{
			for(int j=0;j<yMaze; j++)
			{
				if(maze[i][j] == 3)
				{
					nowUnit.setX(i);
					nowUnit.setY(j);
					nowUnit.setValue(3);
					flag = true;
				}
			}
			if(flag)// ����ҵ���� ������ѭ��
			{
				break;
			}
		}
	}
	
	//���Թ�
	public String breakMaze(int[][] aMaze)
	{
		String message = "";
		//��һ����ʼ���Թ�
		getMaze(aMaze);
		
		//�ڶ����ҵ��Թ������
		getEntrance();
		
		//������ �������Ϊ��ǰ��λ�ƶ�
		while(true)
		{
			printMaze();
			
			boolean nowOK = move(nowUnit);
			
			if(nowOK)//�����ǰλ�õ����������ҵ����� �ɹ��˳�
			{
				message = "��ϲ��,�ɹ��߳��Թ�";
				break;
			}
			else//���û��
			{
				//�ж�ջ�ǲ��ǿ�
				if(stack.isEmpty())//�����
				{
					message = "�Ҳ�������,ʧ���˳�";
					break;
				}
				else//�������ȡ��һ����λ��Ϊ��ǰ��λ�ٽ����ж�
				{
					nowUnit = (Unit) stack.pop();
					maze[nowUnit.getX()][nowUnit.getY()] = 6;//����ֵ��Ϊ6 ����õ�λ�Ѿ��߹�
				}
			}
		}
		return message;
	}
	
	//��ǰ��λ���ж�
	private boolean move(Unit unit)
	{
		//�õ���ǰ��λ�� ����
		int x = unit.getX();
		int y = unit.getY();
		int up = 0;
		int down = 0;
		int left = 0;
		int right = 0;
		boolean flag = false;
		
		//��
		if(x>0)
		{
			up = maze[x-1][y];
			if(up == 9)
			{
				flag = true;
			}
		}       
		//��
		if(x<(xMaze-1))
		{
			down = maze[x+1][y]; 
			if(down == 9)
			{
				flag = true;
			}
		}        
		//��
		if(y>0)
		{
			left = maze[x][y-1];
			if(left == 9)
			{
				flag = true;
			}
		}       
		//��
		if(y<(yMaze-1))
		{
			right = maze[x][y+1];
			if(right == 9)
			{
				flag = true;
			}
		}
		
		if(flag)//�ҵ�����
		{
			return true;
		}
		if(!flag)//���û����ڰ���ͨ·�ĵ�λѹ��ջ
		{
			if(up == 1)
			{
				stack.push(new Unit(x-1,y,1));
			}
			if(down == 1)
			{
				stack.push(new Unit(x+1,y,1));
			}
			if(left == 1)
			{
				stack.push(new Unit(x,y-1,1));
			}
			if(right == 1)
			{
				stack.push(new Unit(x,y+1,1));
			}
		}
		return false;
	}
	
	//��������Թ���ǰ����
	private void printMaze()
	{
		for(int i=0; i<xMaze; i++)
		{
			for(int j=0;j<yMaze; j++)
			{
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	
	
	
	
	
	
	
	
	
	
	
}

