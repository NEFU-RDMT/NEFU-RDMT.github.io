package guy.scoreManage;

public class Menu{
	
	private GetOneStr gos = new GetOneStr();
	private Operate opt = new Operate();
	
	public void getMenu()
	{
		
		System.out.println("1: ����ѧ��");
		System.out.println("2: �鿴ѧ����Ϣ");
		System.out.println("3: �鿴ѧ���ɼ�����");
		System.out.println("0: �˳�ϵͳ");
		System.out.println();
		System.out.println("��������Ҫ���еĲ���,�����س�ȷ��");
		
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
				System.out.println("�����������,����������");
				getMenu();
				break;
		}
	}

}
