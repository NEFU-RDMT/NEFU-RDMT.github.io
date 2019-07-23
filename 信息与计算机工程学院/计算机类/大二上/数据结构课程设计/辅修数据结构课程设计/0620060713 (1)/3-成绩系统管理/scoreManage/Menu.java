package guy.scoreManage;

public class Menu{
	
	private GetOneStr gos = new GetOneStr();
	private Operate opt = new Operate();
	
	public void getMenu()
	{
		
		System.out.println("1: 增加学生");
		System.out.println("2: 查看学生信息");
		System.out.println("3: 查看学生成绩排名");
		System.out.println("0: 退出系统");
		System.out.println();
		System.out.println("请输入你要进行的操作,并按回车确认");
		
		int flag = Integer.parseInt(gos.getStrFromKeyBoard());
		switch(flag)
		{
			case 1:
				opt.AddStudent();
				break;
			case 2:
				opt.lookMsgByNum();
				break;
			case 3:
				opt.lookAllScore();
				break;
			case 0:
				break;
			default:
				System.out.println("你的输入有误,请重新输入");
				getMenu();
				break;
		}
	}

}
