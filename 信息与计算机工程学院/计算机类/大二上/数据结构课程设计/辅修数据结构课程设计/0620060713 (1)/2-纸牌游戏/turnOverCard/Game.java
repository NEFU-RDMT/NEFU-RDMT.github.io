package guy.turnOverCard;

public class Game {

	public void game()
	{
		Card c = new Card();
		
		int card[] = c.getCard();
		
		for(int i=2; i<=52; i++)
		{
			for(int j=1; j<=52; j++)
			{
				if(j%i==0)
				{
					card[j] = playGame(card[j]);
				}
			}
		}
		
		printResult(card);
	}
	
	private int playGame(int num)
	{
		int temp = (num+1)%2;
		return temp;
	}
	
	private void printResult(int[] a)
	{
		for(int i=1; i<a.length; i++)
		{
			if(a[i]==1)
			{
				System.out.println("正面向上的牌有:第"+i+"张");
			}
		}
			
	}
}