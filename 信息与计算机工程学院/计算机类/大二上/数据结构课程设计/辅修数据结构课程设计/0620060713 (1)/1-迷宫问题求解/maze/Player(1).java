package guy.maze;

public class Player {
	
	public static void main(String[] args)
	{
		Game game = new Game();
		
		//�Լ������Թ� ������������
		//1��ʾ��· 0��ʾ��ǽ 3��ʾ��� 9��ʾ���� 6��ʾ�õ�λ�Ѿ��߹�
		int[][] arr = {{0,0,0,0,1},
					   {1,1,1,1,1},
					   {1,3,1,0,0},
					   {0,1,0,0,0}};
		System.out.println(game.breakMaze(arr));
	}

}
