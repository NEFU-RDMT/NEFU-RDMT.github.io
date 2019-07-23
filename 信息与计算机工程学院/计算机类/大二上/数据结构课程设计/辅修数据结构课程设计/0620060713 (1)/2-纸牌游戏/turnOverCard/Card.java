package guy.turnOverCard;

public class Card {
	
	int [] card = new int[53];
	
	//初始化牌 正面向上用1表示 反面向上用0表示
	public Card()
	{
		for(int i=1; i<=52; i++)
		{
			card[i] = 1;
		}
	}

	public int[] getCard() {
		return card;
	}

	public void setCard(int[] card) {
		this.card = card;
	}
}
