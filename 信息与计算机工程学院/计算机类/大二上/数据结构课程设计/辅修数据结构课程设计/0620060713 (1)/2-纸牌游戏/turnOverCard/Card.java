package guy.turnOverCard;

public class Card {
	
	int [] card = new int[53];
	
	//��ʼ���� ����������1��ʾ ����������0��ʾ
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
