package guy.maze;

public class Test {
	
	public static void main(String[] args)
	{
		Game game = new Game();
		
		//自己设置迷宫 能走上下左右
		//1表示是路 0表示是墙 3表示入口 9表示出口 6表示该单位已经走过
		int[][] arr = {{0,0,0,0,1},
					   {0,0,1,1,1},
					   {0,3,1,0,1},
					   {0,1,0,0,9}};
		System.out.println(game.breakMaze(arr));
	}

}
