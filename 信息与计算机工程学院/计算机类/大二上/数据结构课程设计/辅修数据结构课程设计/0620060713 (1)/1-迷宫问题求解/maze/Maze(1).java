package guy.maze;

//该类表示一个迷宫 用一个二维数组来表示
//1表示是路 0表示是墙 3表示入口 9表示出口 6表示路已经走过
public class Maze {
	
	private int[][] maze;
	
	public int[][] getMaze() {
		return maze;
	}

	public void setMaze(int[][] maze) {
		this.maze = maze;
	}

}
