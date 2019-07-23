package guy.maze;

public class Game {
	
	private Maze m = new Maze();
	private int[][] maze;
	private MyStack stack = new MyStack();
	private int xMaze;//用来表示迷宫的行
	private int yMaze;//用来表示迷宫的列
	private Unit nowUnit;//存放当前的迷宫单位
	
	//初始化一个迷宫
	//1表示是路 0表示是墙 3表示入口 9表示出口 6表示该单位已经走过
	private void getMaze(int[][] aMaze)
	{
		xMaze = aMaze.length;
		yMaze = aMaze[aMaze.length-1].length;
		m.setMaze(aMaze);
	}
	
	//遍历迷宫找到入口
	private void getEntrance()
	{
		boolean flag = false;//用来控制循环
		
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
			if(flag)// 如果找到入口 则跳出循环
			{
				break;
			}
		}
	}
	
	//走迷宫
	public String breakMaze(int[][] aMaze)
	{
		String message = "";
		//第一步初始化迷宫
		getMaze(aMaze);
		
		//第二步找到迷宫的入口
		getEntrance();
		
		//第三步 把入口作为当前单位移动
		while(true)
		{
			printMaze();
			
			boolean nowOK = move(nowUnit);
			
			if(nowOK)//如果当前位置的上下左右找到出口 成功退出
			{
				message = "恭喜你,成功走出迷宫";
				break;
			}
			else//如果没有
			{
				//判断栈是不是空
				if(stack.isEmpty())//如果空
				{
					message = "找不到出口,失败退出";
					break;
				}
				else//如果不空取出一个单位作为当前单位再进行判断
				{
					nowUnit = (Unit) stack.pop();
					maze[nowUnit.getX()][nowUnit.getY()] = 6;//把其值改为6 代表该单位已经走过
				}
			}
		}
		return message;
	}
	
	//当前单位的判断
	private boolean move(Unit unit)
	{
		//得到当前单位的 坐标
		int x = unit.getX();
		int y = unit.getY();
		int up = 0;
		int down = 0;
		int left = 0;
		int right = 0;
		boolean flag = false;
		
		//上
		if(x>0)
		{
			up = maze[x-1][y];
			if(up == 9)
			{
				flag = true;
			}
		}       
		//下
		if(x<(xMaze-1))
		{
			down = maze[x+1][y]; 
			if(down == 9)
			{
				flag = true;
			}
		}        
		//左
		if(y>0)
		{
			left = maze[x][y-1];
			if(left == 9)
			{
				flag = true;
			}
		}       
		//右
		if(y<(yMaze-1))
		{
			right = maze[x][y+1];
			if(right == 9)
			{
				flag = true;
			}
		}
		
		if(flag)//找到出口
		{
			return true;
		}
		if(!flag)//如果没有入口把是通路的单位压入栈
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
	
	//用来输出迷宫当前数据
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

