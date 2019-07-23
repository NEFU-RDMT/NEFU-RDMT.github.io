package guy.scoreManage;

public class Student {
	
	private int num;
	private String name;
	private Score score;
	private double all;
	
	public double getAll(){
		return this.score.getEnglish()+this.score.getMath()+this.score.getChinese();
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public Score getScore() {
		return score;
	}
	public void setScore(Score score) {
		this.score = score;
	}
}
